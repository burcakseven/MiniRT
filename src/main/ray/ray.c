//
// Created by emakas on 12.04.2023.
//

#include <frame/frame.h>
#include <ray/ray.h>

t_ray make_ray(point3 origin, t_vec3 direction) {
  t_ray r;
  vec3_init(&r.orig, origin.x, origin.y, origin.z);
  vec3_init(&r.dir, direction.x, direction.y, direction.z);
  return r;
}

point3 ray_at(t_ray r, double t) {
  t_vec3 result;
  result = vec3_scale(r.dir, t);
  result = vec3_add(r.orig, result);
  return result;
}

t_ray transformed_ray(point3 normal_vec, t_ray r, int inverse_flag) {
  float *matrix;
  t_ray new_r;

  matrix = init_matrix(normal_vec, inverse_flag);
  new_r.dir = matrix_vector_multiply(matrix, r.dir);
  new_r.dir = vec3_normalize(new_r.dir);
  new_r.orig = matrix_vector_multiply(matrix, r.orig);
  del(matrix);
  return new_r;
}

t_vec3 normal_at_sphere(point3 center, point3 hit_point) {
  t_vec3 normal;
  normal = vec3_subtract(hit_point, center);
  return vec3_normalize(normal);
}

t_vec3 array_to_vec3(const float coord[3]) {
  return (t_vec3){coord[0], coord[1], coord[2]};
}

unsigned int ray_color(const t_ray *r, const t_scene *scene) {
  t_vec3 sp_center;
  double sp_radius;
  t_root root;
  point3 hit_point;

  if (scene->sphere) {
    sp_center.x = scene->sphere->coordinate[0];
    sp_center.y = scene->sphere->coordinate[1];
    sp_center.z = scene->sphere->coordinate[2];
    sp_radius = scene->sphere->diameter / 2.0;

    if ((root = hit_sphere(sp_center, sp_radius, *r)).root_number > 0) {
      hit_point = ray_at(*r, root.root1);
      t_vec3 normal = normal_at_sphere(sp_center, hit_point);
      t_vec3 sphere_to_light =
          vec3_subtract(array_to_vec3(scene->light.coordinate), hit_point);
      sphere_to_light = vec3_normalize(sphere_to_light);

      double dot = vec3_dot(&normal, &sphere_to_light);
      if (dot < 0)
        dot = 0;

      int r_chan = ((scene->sphere->color >> 16) & 0xFF) * dot;
      int g_chan = ((scene->sphere->color >> 8) & 0xFF) * dot;
      int b_chan = (scene->sphere->color & 0xFF) * dot;
      return (r_chan << 16 | g_chan << 8 | b_chan);
    }
  }

  // t = 0.5 * (r->dir.y) + 1.0;
  // color full = {1.0, 1.0, 1.0};
  // color blue = {0.5, 0.7, 1.0};

  // added = vec3_add(vec3_scale(full, (1.0 - t)), vec3_scale(blue, t));
  return 0x000000;
}

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

static unsigned int apply_lighting(const t_hit_record *rec,
                                    const t_scene *scene) {
  t_vec3 light_pos = array_to_vec3(scene->light.coordinate);
  t_vec3 light_dir = vec3_normalize(vec3_subtract(light_pos, rec->p));

  double dot = vec3_dot(&rec->normal, &light_dir);
  if (dot < 0)
    dot = 0;

  double intensity = dot * scene->light.brightness;

  int r = ((rec->color >> 16) & 0xFF) * intensity;
  int g = ((rec->color >> 8) & 0xFF) * intensity;
  int b = (rec->color & 0xFF) * intensity;

  return (r << 16 | g << 8 | b);
}

static int hit_anything(const t_ray *r, const t_scene *scene,
                        t_hit_record *rec) {
  t_vec3 sp_center;
  double sp_radius;
  t_vec3 pl_point;
  t_root root;
  int hit = 0;
  double closest_so_far = INFINITY;

  if (scene->sphere) {
    sp_center = array_to_vec3(scene->sphere->coordinate);
    sp_radius = scene->sphere->diameter / 2.0;
    root = hit_sphere(sp_center, sp_radius, *r);
    if (root.root_number > 0 && root.root1 > 0.001 && root.root1 < closest_so_far) {
      closest_so_far = root.root1;
      rec->t = root.root1;
      rec->p = ray_at(*r, rec->t);
      rec->normal = normal_at_sphere(sp_center, rec->p);
      rec->color = scene->sphere->color;
      hit = 1;
    }
  }
  if (scene->plane) {
    pl_point = array_to_vec3(scene->plane->coordinate);
    root = hit_plane(pl_point, array_to_vec3(scene->plane->v_normal), *r);
    if (root.root_number > 0 && root.root1 > 0.001 && root.root1 < closest_so_far) {
      closest_so_far = root.root1;
      rec->t = root.root1;
      rec->p = ray_at(*r, rec->t);
      rec->normal = array_to_vec3(scene->plane->v_normal);
      rec->color = scene->plane->color;
      hit = 1;
    }
  }
  return hit;
}

unsigned int ray_color(const t_ray *r, const t_scene *scene) {
  t_hit_record rec;

  if (hit_anything(r, scene, &rec)) {
    return apply_lighting(&rec, scene);
  }

  return 0x000000;
}

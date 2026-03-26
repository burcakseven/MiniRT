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

t_ray transformed_ray(point3 normal_vec, t_vec3 center, t_ray r, int inverse_flag) {
  float *matrix;
  t_ray new_r;

  new_r.orig = vec3_subtract(r.orig, center);
  new_r.dir = r.dir;
  
  matrix = init_matrix(normal_vec, inverse_flag);
  new_r.dir = matrix_vector_multiply(matrix, new_r.dir);
  new_r.orig = matrix_vector_multiply(matrix, new_r.orig);
  new_r.dir = vec3_normalize(new_r.dir);
  del(matrix);
  return new_r;
}

t_vec3 normal_at_sphere(point3 center, point3 hit_point) {
  t_vec3 normal;
  normal = vec3_subtract(hit_point, center);
  return vec3_normalize(normal);
}

t_vec3 normal_at_cylinder(t_vec3 cy_center, t_vec3 cy_axis, t_vec3 p)
{
    t_vec3 v;
    double m;
    t_vec3 projection_p;
    t_vec3 normal;
  
    v = vec3_subtract(p, cy_center);
    m = vec3_dot(&v, &cy_axis);
    projection_p = vec3_add(cy_center, vec3_scale(cy_axis, m));
    normal = vec3_subtract(p, projection_p);

    return (vec3_normalize(normal));
}

t_vec3 array_to_vec3(const float coord[3]) {
  return (t_vec3){coord[0], coord[1], coord[2]};
}

static int hit_anything(const t_ray *r, const t_scene *scene,
                        t_hit_record *rec) {
  t_vec3 sp_center;
  double sp_radius;
  t_vec3 pl_point;
  t_root root;
  int hit = 0;
  double closest_so_far = 1e30;

  if (scene->sphere) {
    double t;
    sp_center = array_to_vec3(scene->sphere->coordinate);
    sp_radius = scene->sphere->diameter / 2.0;
    root = hit_sphere(sp_center, sp_radius, *r);
    t = closest_positive_root(root);
    if (t > 0 && t < closest_so_far) {
      closest_so_far = t;
      rec->t = t;
      rec->p = ray_at(*r, t);
      rec->normal = normal_at_sphere(sp_center, rec->p);
      rec->color = scene->sphere->color;
      hit = 1;
    }
  }
  if (scene->plane) {
    pl_point = array_to_vec3(scene->plane->coordinate);
    root = hit_plane(pl_point, array_to_vec3(scene->plane->v_normal), *r);
    if (root.root_number > 0 && root.root1 > 0.001 &&
        root.root1 < closest_so_far) {
      closest_so_far = root.root1;
      rec->t = root.root1;
      rec->p = ray_at(*r, rec->t);
      rec->normal = vec3_normalize(array_to_vec3(scene->plane->v_normal));
      rec->color = scene->plane->color;
      hit = 1;
    }
  }
  if (scene->cylinder) {
    double t;
    t_vec3 cy_center = array_to_vec3(scene->cylinder->coordinate);
    t_vec3 cy_axis   = vec3_normalize(array_to_vec3(scene->cylinder->v_axis));
    double cy_radius = scene->cylinder->diameter / 2.0;
    double cy_height = scene->cylinder->height;

    root = hit_cylinder(cy_center, cy_axis, *r, cy_radius, cy_height);
    t = closest_positive_root(root);
    if (t > 0 && t < closest_so_far) {
      closest_so_far = t;
      rec->t = t;
      rec->p = ray_at(*r, t);
      rec->normal = normal_at_cylinder(cy_center, cy_axis, rec->p);
      rec->color = scene->cylinder->color;
      hit = 1;
    }
  }
  return hit;
}

int is_in_shadow(t_vec3 light_vec, const t_scene *scene, const t_hit_record *rec) {
    t_ray shadow_ray;
    t_hit_record shadow_rec;
    double light_dist = vec3_length(light_vec);
    t_vec3 light_dir = vec3_normalize(light_vec);

    shadow_ray.orig = vec3_add(rec->p, vec3_scale(rec->normal, 0.001));
    shadow_ray.dir = light_dir;

    if (hit_anything(&shadow_ray, scene, &shadow_rec)) {
        if (shadow_rec.t < light_dist)
            return 1;
    }
    return 0;
}

static unsigned int apply_lighting(const t_hit_record *rec, const t_scene *scene) {
    t_vec3 light_pos = array_to_vec3(scene->light.coordinate);
    t_vec3 light_vec = vec3_subtract(light_pos, rec->p);
    t_vec3 light_dir = vec3_normalize(light_vec);

    double obj_r = ((rec->color >> 16) & 0xFF) / 255.0;
    double obj_g = ((rec->color >> 8) & 0xFF) / 255.0;
    double obj_b = (rec->color & 0xFF) / 255.0;

    double amb_r_light = ((scene->ambient.color >> 16)) / 255.0;
    double amb_g_light = ((scene->ambient.color >> 8)) / 255.0;
    double amb_b_light = (scene->ambient.color) / 255.0;

    double final_r = obj_r * scene->ambient.range * amb_r_light;
    double final_g = obj_g * scene->ambient.range * amb_g_light;
    double final_b = obj_b * scene->ambient.range * amb_b_light;

    if (!is_in_shadow(light_vec, scene, rec)) {
        double dot = vec3_dot(&rec->normal, &light_dir);
        if (dot > 0) {
            double diffuse_intensity = dot * scene->light.brightness;
            
            double l_r = ((scene->light.color >> 16) & 0xFF) / 255.0;
            double l_g = ((scene->light.color >> 8) & 0xFF) / 255.0;
            double l_b = (scene->light.color & 0xFF) / 255.0;

            final_r += obj_r * diffuse_intensity * l_r;
            final_g += obj_g * diffuse_intensity * l_g;
            final_b += obj_b * diffuse_intensity * l_b;
        }
    }

    int r = (int)(final_r * 255);
    int g = (int)(final_g * 255);
    int b = (int)(final_b * 255);

    if (r > 255) r = 255;
    if (g > 255) g = 255;
    if (b > 255) b = 255;

    return (r << 16 | g << 8 | b);
}

// static unsigned int apply_ambient(unsigned int obj_color, const t_scene
// *scene) {
//     double ratio = scene->ambient.range;

//     int r = ((obj_color >> 16) & 0xFF) * ratio * (((scene->ambient.color >>
//     16) & 0xFF) / 255.0); int g = ((obj_color >> 8) & 0xFF) * ratio *
//     (((scene->ambient.color >> 8) & 0xFF) / 255.0); int b = (obj_color &
//     0xFF) * ratio * (((scene->ambient.color & 0xFF) / 255.0));

//     return (r << 16 | g << 8 | b);
// }


unsigned int ray_color(const t_ray *r, const t_scene *scene) {
  t_hit_record rec;

  if (hit_anything(r, scene, &rec)) {
    return apply_lighting(&rec, scene);
  }

  return 0x000000;
}

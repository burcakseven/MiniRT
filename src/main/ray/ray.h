#ifndef RAY_H
#define RAY_H

#include <vec3/r_vec3.h>
struct s_scene;

typedef struct s_ray {
  t_vec3 orig;
  t_vec3 dir;
} t_ray;

typedef struct s_hit_record {
  point3 p;
  t_vec3 normal;
  double t;
  unsigned int color;
} t_hit_record;

t_ray make_ray(point3 origin, t_vec3 direction);
t_vec3 ray_at(t_ray r, double t);
unsigned int ray_color(const t_ray *r, const struct s_scene *scene);
t_ray transformed_ray(point3 normal_vec, point3 center, t_ray r, int inverse_flag);

// point3  fint_intersect(t_ray ray, t_scene scene, color *colour);

#endif
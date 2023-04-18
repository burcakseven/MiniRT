#ifndef RAY_H
#define RAY_H

#include <vec3/r_vec3.h>

typedef struct s_ray
{
    t_vec3 orig;
    t_vec3 dir;
} t_ray;

t_ray make_ray(point3 origin, t_vec3 direction);
t_vec3 ray_at(t_ray r, double t);
color ray_color (const t_ray *r);

//point3  fint_intersect(t_ray ray, t_scene scene, color *colour);


#endif
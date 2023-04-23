#ifndef RAY_H
#define RAY_H

#include <vec3/vec3.h>
#include <matrix/matrix.h>

typedef struct s_ray
{
    t_vec3 orig;
    t_vec3 dir;
    t_vec3 diff; //orijine göre ray direction 
} t_ray;

t_ray make_ray(t_point3 origin, t_vec3 direction);
t_vec3 ray_at(t_ray r, double t);
t_color ray_color (const t_ray *r);
t_ray transformed_ray(t_point3 normal_vec, t_ray r, int inverse_flag);

//point3  fint_intersect(t_ray ray, t_scene scene, color *colour);


#endif
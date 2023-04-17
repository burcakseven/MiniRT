#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <vec3/r_vec3.h>

t_vec3 transform(t_vec3 vectors[3], t_vec3 vector);
t_vec3 rotate_x(long double angle, t_vec3 vector);
t_vec3 rotate_y(long double angle, t_vec3 vector);
t_vec3 rotate_z(long double angle, t_vec3 vector);

#endif
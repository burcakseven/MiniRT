#ifndef R_VEC3_H
#define R_VEC3_H

#include <math.h>

typedef struct s_vec3
{
    double x, y, z;
}              t_vec3;

typedef t_vec3 point3;  // 3D point
typedef t_vec3 color;   // RGB color

t_vec3 vec3_create(double x, double y, double z);
void vec3_init(t_vec3* v, double x, double y, double z);
t_vec3 vec3_add(const t_vec3 a, const t_vec3 b);
t_vec3 vec3_subtract(const t_vec3 a, const t_vec3 b);
t_vec3 vec3_scale(const t_vec3 v, const double s);
double vec3_length(const t_vec3 v);
t_vec3 vec3_normalize(t_vec3 v);
double vec3_dot(const t_vec3* a, const t_vec3* b);
t_vec3 vec3_cross(const t_vec3 a, const t_vec3 b);

#endif

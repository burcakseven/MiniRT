#ifndef R_VEC3_H
#define R_VEC3_H

#include <math.h>

typedef struct s_vec3
{
    double x, y, z;
}              t_vec3;

void vec3_init(t_vec3* v, double x, double y, double z);
void vec3_add(const t_vec3* a, const t_vec3* b, t_vec3* c);
void vec3_subtract(const t_vec3* a, const t_vec3* b, t_vec3* c);
void vec3_scale(const t_vec3* v, double s, t_vec3* w);
double vec3_length(const t_vec3* v);
void vec3_normalize(t_vec3* v);
double vec3_dot(const t_vec3* a, const t_vec3* b);
void vec3_cross(const t_vec3* a, const t_vec3* b, t_vec3* c);

#endif

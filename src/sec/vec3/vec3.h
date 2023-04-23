#ifndef VEC3_H
#define VEC3_H

typedef struct s_vec3
{
    long double x, y, z;
}              t_vec3;

typedef t_vec3 t_point3;  // 3D point
typedef t_vec3 t_color;   // RGB color

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
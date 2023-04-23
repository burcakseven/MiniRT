#include "vec3.h"
#include <math.h>

t_vec3 vec3_create(double x, double y, double z){
    t_vec3 vector;

    vector.x = x;
    vector.y = y;
    vector.z = z;
    return (vector);
}

void vec3_init(t_vec3* v, double x, double y, double z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

t_vec3 vec3_add(const t_vec3 a, const t_vec3 b)
{
    t_vec3 c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    return c;
}

t_vec3 vec3_subtract(const t_vec3 a, const t_vec3 b)
{
    t_vec3 c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    c.z = a.z - b.z;
    return c;
}

t_vec3 vec3_scale(const t_vec3 v, const double s)
{
    t_vec3 w;
    w.x = v.x * s;
    w.y = v.y * s;
    w.z = v.z * s;
    return w;
}

double vec3_length(const t_vec3 v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

t_vec3 vec3_normalize(t_vec3 v)
{
    t_vec3 normalize;
    double len;

    len = vec3_length(v);
    if (len != 0.0) {
        normalize.x = v.x / len;
        normalize.y = v.y / len;
        normalize.z = v.z / len;
    }
    else
        return (v);
    return (normalize);
}
#include <stdio.h>
double vec3_dot(const t_vec3* a, const t_vec3* b)
{
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

t_vec3 vec3_cross(const t_vec3 a, const t_vec3 b)
{
    t_vec3 c;
    c.x = a.y * b.z - a.z * b.y;
    c.y = a.z * b.x - a.x * b.z;
    c.z = a.x * b.y - a.y * b.x;
    return c;
}

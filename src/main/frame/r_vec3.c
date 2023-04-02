#include "r_vec3.h"

void vec3_init(t_vec3* v, double x, double y, double z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

void vec3_add(const t_vec3* a, const t_vec3* b, t_vec3* c)
{
    c->x = a->x + b->x;
    c->y = a->y + b->y;
    c->z = a->z + b->z;
}

void vec3_subtract(const t_vec3* a, const t_vec3* b, t_vec3* c)
{
    c->x = a->x - b->x;
    c->y = a->y - b->y;
    c->z = a->z - b->z;
}

void vec3_scale(const t_vec3* v, double s, t_vec3* w)
{
    w->x = v->x * s;
    w->y = v->y * s;
    w->z = v->z * s;
}

double vec3_length(const t_vec3* v)
{
    return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

void vec3_normalize(t_vec3* v)
{
    double len = vec3_length(v);
    if (len != 0.0) {
        v->x /= len;
        v->y /= len;
        v->z /= len;
    }
}

double vec3_dot(const t_vec3* a, const t_vec3* b)
{
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

void vec3_cross(const t_vec3* a, const t_vec3* b, t_vec3* c)
{
    c->x = a->y * b->z - a->z * b->y;
    c->y = a->z * b->x - a->x * b->z;
    c->z = a->x * b->y - a->y * b->x;
}

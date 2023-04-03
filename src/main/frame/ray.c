#include "ray.h"

t_ray make_ray(point3 origin, t_vec3 direction)
{
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

color ray_color (const t_ray *r)
{
    double t;
    color added;
    vec3_normalize(r->dir);
    t = 0.5 *(r->dir.y) +1.0;
    color full = {1.0,1.0,1.0};
    color blue = {0.5, 0.7, 1.0};

    added = vec3_add(vec3_scale(full,(1.0-t)),vec3_scale(blue, t));
    return  added;
}

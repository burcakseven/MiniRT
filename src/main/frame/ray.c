#include "ray.h"

t_ray make_ray(t_vec3 origin, t_vec3 direction) {
    t_ray r;
    vec3_init(&r.orig, origin.x, origin.y, origin.z);
    vec3_init(&r.dir, direction.x, direction.y, direction.z);
    return r;
}

t_vec3 ray_at(t_ray r, double t) {
    t_vec3 result;
    vec3_scale(&r.dir, t, &result);
    vec3_add(&r.orig, &result, &result);
    return result;
}

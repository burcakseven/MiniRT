//
// Created by emakas on 12.04.2023.
//

#include <ray/ray.h>

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

int hit_sphere(const point3 center, double rad, const t_ray r)
{
    t_vec3 oc;

    oc = vec3_subtract(r.orig,center);
    double a = vec3_dot(&r.dir, &r.dir);
    double b = 2.0 * vec3_dot(&oc, &r.dir);
    double c = vec3_dot(&oc,&oc) - rad*rad;
    double discr =(b*b) -(4*a*c);
    // if(discr >= 0)
    //     return 1;
    // return 0;
    return (discr > 0);
}

color ray_color (const t_ray *r)
{
    double t;
    color added;
    point3 sp = {0,0,1};
    if(hit_sphere(sp,0.5,*r))
    {
        color cl = {1, 0, 0};
        //printf("MERH\nA");
        return cl;
    }
    t = 0.5 *(r->dir.y) +1.0;
    color full = {1.0,1.0,1.0};
    color blue = {0.5, 0.7, 1.0};

    added = vec3_add(vec3_scale(full,(1.0-t)),vec3_scale(blue, t));
    return  added;
}

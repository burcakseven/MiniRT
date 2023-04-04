/* #include "frame.h"

int hit_sphere(const point3 center, double rad, const t_ray r)
{
    t_vec3 oc;

    oc = vec3_subtract(r.orig,center);
    double a = vec3_dot(&r.dir, &r.dir);
    double b = 2.0 * vec3_dot(&oc, &r.dir);
    double c = vec3_dot(&oc,&oc) - rad*rad;
    double discr = b*b -4*a*c;
    if(discr > 0)
        return 1;
    return 0;
} */
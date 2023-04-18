#include "frame.h"

/* int hit_sphere(const point3 center, double rad, const t_ray r)
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
}
 */
double plane_const(const point3 center,point3 normalize_vec)
{
    double d;
    d = -1 * vec3_dot(&center,&normalize_vec);
    return d;
}

double hit_plane(const point3 center, const point3 vec1, const t_ray r)
{
//vec1 is normal vector of plane
    double t;
    point3 vec2;

    vec2= vec3_subtract(r.orig,center);
    t = vec3_dot(&vec1, &vec2);
    t += plane_const(center,vec1);
    t *= -1;
    t = t / vec3_dot(&vec1, &r.dir);

    return t;
}

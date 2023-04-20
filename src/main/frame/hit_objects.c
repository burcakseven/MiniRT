#include "frame.h"

double discriminant(double a,double b, double c)
{
	return (b * b - 4 * a * c);
}

int hit_sphere(const point3 center, double rad, const t_ray r)
{
    t_vec3 oc;

    oc = vec3_subtract(r.orig,center);
    double a = vec3_dot(&r.dir, &r.dir);
    double b = 2.0 * vec3_dot(&oc, &r.dir);
    double c = vec3_dot(&oc,&oc) - rad*rad;
    return (discriminant(a,b,c));
}


double hit_plane(const point3 center, const point3 normal_vec, const t_ray r)
{
	double t;
	t_ray new_r;
	new_r = transformed_ray(normal_vec,r,1);
    t = new_r.orig.z / vec3_scale(new_r.dir,-1).z;

    return t;
}


double hit_cylinder(const point3 center, const point3 normal_vec, const t_ray r)
{
	double a;
	double b;
	double c;
    t_ray new_r;

	new_r = transformed_ray(normal_vec,r,1);
	a = pow(new_r.dir.x,2) + pow(new_r.dir.y,2);
	b = 2 *(new_r.orig.x * new_r.dir.x + new_r.orig.y * new_r.dir.y);
	c = pow(new_r.orig.x,2) + pow(new_r.orig.y,2) - 1;

	return(discriminant(a,b,c));
}
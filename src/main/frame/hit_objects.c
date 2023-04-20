#include "frame.h"

double discriminant(double a,double b, double c)
{
	return (b * b - 4 * a * c);
}

t_root roots(double a,double b, double discriminant)
{
	t_root root;
	if(discriminant < 0)
		root.root_number = 0;
	else if (discriminant == 0 )
	{
		root.root_number = 1;
		root.root1 = -b / (-2 * a);
	}
	else
	{
		root.root_number = 2;
		root.root1 = (-b + sqrt(discriminant)) / (-2 * a);
		root.root2 = (-b - sqrt(discriminant)) / (-2 * a);
	}
	return root;
}

t_root hit_sphere(const point3 center, double rad, const t_ray r)
{
    t_vec3 oc;

    oc = vec3_subtract(r.orig,center);
    double a = vec3_dot(&r.dir, &r.dir);
    double b = 2.0 * vec3_dot(&oc, &r.dir);
    double c = vec3_dot(&oc,&oc) - rad*rad;
    return (roots(a,b,discriminant(a,b,c)));
}


double hit_plane(const point3 center, const point3 normal_vec, const t_ray r)
{
	double t;
	t_ray new_r;
	new_r = transformed_ray(normal_vec,r,1);
    t = new_r.orig.z / vec3_scale(new_r.dir,-1).z;

    return t;
}

t_root hit_cylinder(point3 center, const point3 normal_vec,\
 const t_ray r, const double radius, const double height) // sınırsız silindir?
{
	double a;
	double b;
	double c;
    t_ray new_r;

	center = transformed_ray(center,r,1).orig;
	new_r = transformed_ray(normal_vec,r,1);
	if(center.z - new_r.dir.z )
	a = pow(new_r.dir.x,2) + pow(new_r.dir.y,2);
	b = 2 *(new_r.orig.x * new_r.dir.x + new_r.orig.y * new_r.dir.y);
	c = pow(new_r.orig.x,2) + pow(new_r.orig.y,2) - pow(radius,2);

	return(roots(a,b,discriminant(a,b,c)));
}
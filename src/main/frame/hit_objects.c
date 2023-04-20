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
	root.discriminant;
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


t_root hit_plane(const point3 center, const point3 normal_vec, const t_ray ray)// buna bak
{
	t_root root;
	t_ray new_ray;
	new_ray = transformed_ray(normal_vec,ray,1);
	root.root_number = 1;
    root.root1 = new_ray.orig.z / vec3_scale(new_ray.dir,-1).z;

    return root;
}

t_root hit_cylinder(point3 center, const point3 normal_vec,\
 const t_ray ray, const double radius, const double height) // sınırsız silindir?
{
	double a;
	double b;
	double c;
    t_ray new_ray;

	center = transformed_ray(center,ray,1).orig;
	new_ray = transformed_ray(normal_vec,ray,1);
	if(center.z - new_ray.dir.z )
	a = pow(new_ray.dir.x,2) + pow(new_ray.dir.y,2);
	b = 2 *(new_ray.orig.x * new_ray.dir.x + new_ray.orig.y * new_ray.dir.y);
	c = pow(new_ray.orig.x,2) + pow(new_ray.orig.y,2) - pow(radius,2);

	return(roots(a,b,discriminant(a,b,c)));
}

t_root root_control(t_root root) // ne döndürsem?
{
	t_root root;

	// root = hit_sphere(shpere.coordinate, shpere.diameter, r);//şu an işe yaramıyor parser değişinde yarar
	if(root.root_number == 0)
		return root;
	else if (root.root1 < 0 || root.root2 < 0)
	{
		root.root_number = 0;
	}
		return root;
}
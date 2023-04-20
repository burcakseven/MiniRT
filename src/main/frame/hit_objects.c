#include "frame.h"

t_root hit_sphere(const point3 center, double rad, const t_ray r)
{
    t_vec3 oc;

    oc = vec3_subtract(r.orig,center);
    double a = vec3_dot(&r.dir, &r.dir);
    double b = 2.0 * vec3_dot(&oc, &r.dir);
    double c = vec3_dot(&oc,&oc) - rad*rad;
    return (roots(a,b,discriminant(a,b,c)));
}

t_root hit_plane(const point3 center, const point3 normal_vec, const t_ray ray)
{
	t_root	root;
	t_ray	new_ray;
	double	t;
	double	u;
	double	v;

	new_ray = transformed_ray(normal_vec,ray,1);
	if(!is_equal(new_ray.dir.z,0.0))
	{
		t = new_ray.orig.z / vec3_scale(new_ray.dir,-1).z;
		if(t > 0.0)
		{
			u = new_ray.orig.x + (new_ray.dir.x * t);
			v = new_ray.orig.y + (new_ray.dir.y * t);
			if(fabs(u) < 1.0 && fabs(v) < 1.0)
			{
				root.root_number = 1;
				root.root1 = t;
				return (root);
			}
		}
	}
		root.root_number = 0;
    return (root);
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

void swap_roots(t_root *root)
{
	double temp;
	if(root->root1 < root->root2)
		return ;
	temp = root->root1;
	root->root1 = root->root2;
	root->root2 = temp;
}

t_root root_control(t_root root) // ne döndürsem?
{
	if(root.root_number == 0)
		return root;
	else if (root.root1 < 0 || root.root2 < 0)
	{
		root.root_number = 0;
	}
	swap_roots(&root);
	return root;
}
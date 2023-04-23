#include "objects.h"
#include <utils/utils.h>
#include <stdio.h>
t_bool int_test(double a, double b, double c, t_intersection *inter_data)
{
	double t1;
	double t2;
	double discriminant;

	discriminant = (b * b) - (4.0 * a * c);
	inter_data->discriminant = discriminant;
	// printf("a: %f, b: %f, c: %f, discriminant: %f\n",a,b,c,*discriminant);	ft_error("");
	if(discriminant > 0.0)
	{
		t1 = ((-b + sqrt(discriminant)) / 2.0);
		t2 = ((-b - sqrt(discriminant)) / 2.0);
		if(t1 > 0.0 && t2 > 0.0)
		{
			if(t1 > t2)
				inter_data->int_param = t1;
			else
				inter_data->int_param = t2;
			return (TRUE);
		}
	}
	return (FALSE);
}

void sphere_formula(const t_ray ray, t_intersection *inter_data)
{
	inter_data->int_point = vec3_add(ray.orig ,\
	 vec3_scale(ray.diff_normal, inter_data->int_param));
}

t_bool intersec_sphere(const t_ray ray, t_intersection *inter_data)
{
	double b;
	double c;
	t_vec3 dir;

	dir = vec3_normalize(ray.diff);
	//ray direction is a unit vector so a will be a 1
	b = 2.0 * vec3_dot(&(ray.orig) , &dir);
	c = vec3_dot(&ray.orig, &ray.orig) - 1.0;
	if(int_test(1, b, c, &inter_data))
	{
		sphere_formula(ray, inter_data);
		return (TRUE);
	}
	return (FALSE);

}




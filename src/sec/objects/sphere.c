#include "objects.h"
#include <utils/utils.h>
#include <stdio.h>
t_bool int_test(double a, double b, double c, double *discriminant)
{
	*discriminant = (b * b) - (4.0 * a * c);
	if(*discriminant >= 0.0)
		return (TRUE);
	return (FALSE);
}

t_bool intersec_sphere(const t_ray ray, t_intersection *inter_data)
{
	double b;
	double c;
	t_vec3 dir;
	t_bool result;

	dir = vec3_normalize(ray.diff);
	//ray direction is a unit vector so a will be a 1
	b = 2.0 * vec3_dot(&(ray.orig) , &dir);
	c = vec3_dot(&ray.orig, &ray.orig) - 1.0;
	result = int_test(1, b, c, &(inter_data->discriminant));
	if(result)
		return (TRUE);
	return (FALSE);

}




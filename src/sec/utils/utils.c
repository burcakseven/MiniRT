#include <utils/utils.h>
#include <math.h>

long double to_rad(long double degrees) {
    return degrees * M_PI / 180.0;
}

t_point3 convert_point3(float coordinate[3]){
    t_point3  point;

    point.x = (long double) coordinate[0];
    point.y = (long double) coordinate[1];
    point.z = (long double) coordinate[2];
	return (point);
}

int is_equal(double first, double second)
{
    if(fabs(first-second) < __DBL_EPSILON__)
        return (1);
    return (0);
}

void ft_error(char *msg)
{
	printf("%s error\n", msg);
    garbage_collect();
	exit(1);
}


double discriminant(double a,double b, double c)
{
	return (b * b - 4 * a * c);
}

t_root hit_sphere(const t_point3 center, double rad, const t_ray r)
{
    t_vec3 oc;

    oc = vec3_subtract(r.orig,center);
    double a = vec3_dot(&r.dir, &r.dir);
    double b = 2.0 * vec3_dot(&oc, &r.dir);
    double c = vec3_dot(&oc,&oc) - rad*rad;
    return (roots(a,b,discriminant(a,b,c)));
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
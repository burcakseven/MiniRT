#ifndef UTILS_H
# define UTILS_H
# include <math.h>
# include <vec3/vec3.h>
#include <ray/ray.h>
#define TRUE 0xFF
#define FALSE 0x00


typedef struct	s_root {
int		root_number;
double	root1;
double	root2;
// double	discriminant;
}              t_root;

t_root hit_sphere(const t_point3 center, double rad, const t_ray r);
t_root roots(double a,double b, double discriminant);
t_root root_control(t_root root);

typedef unsigned char t_bool;
long double to_rad(long double degrees);
void ft_error(char *msg);
int is_equal(double first, double second);
t_point3 convert_point3(float coordinate[3]);

#endif
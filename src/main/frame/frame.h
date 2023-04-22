#ifndef FRAME_H
# define FRAME_H

#include <mlx.h>
#include <stdio.h>
#include <vec3/r_vec3.h>
#include <ray/ray.h>
#include <math.h>
#include <matrix/matrix.h>
#include <utils/utils.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}              t_data;

typedef struct	s_root {
int		root_number;
double	root1;
double	root2;
// double	discriminant;
}              t_root;

double deg2rad(double degrees);
unsigned int rgb_color(t_color colour);
double discriminant(double a,double b, double c);
t_root roots(double a,double b, double discriminant);
t_root root_control(t_root root);
// double hit_plane(const t_point3 center, const point3 vec1, const t_ray r);
t_root hit_sphere(const t_point3 center, double rad, const t_ray r)
t_root hit_plane(const t_point3 center, const t_point3 normal_vec, const t_ray r);
t_root hit_cylinder(t_point3 center, const t_point3 normal_vec,\
 const t_ray r, const double radius, const double height);

#endif
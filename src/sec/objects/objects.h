#ifndef OBJECTS_H
#define OBJECTS_H

#include <ray/ray.h>
#include <matrix/matrix.h>
#include <scene/scene.h>
#include <utils/utils.h>

typedef struct	s_intersection
{
	t_vec3	int_point;
	t_vec3	local_normal;
	t_vec3	local_color;
	double	int_param;
	double	discriminant;
}				t_intersection;

t_bool intersec_sphere(const t_ray ray, t_intersection *inter_data);

#endif
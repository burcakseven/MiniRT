#include "r_vec3.h"
#include <math.h>
#include <stdio.h>
#include <utils/utils.h>

t_vec3 rotate_xy(t_vec3 vec, long double angle){
	t_vec3 ret_vec;
	long double angle_in_rad;

	angle_in_rad = to_rad(angle);
	ret_vec.z = vec.z;
	ret_vec.x = (cos(angle_in_rad) * vec.x) - (sin(angle_in_rad) * vec.y);
	ret_vec.y = (sin(angle_in_rad) * vec.x) + (cos(angle_in_rad) * vec.y);
	//printf("rotated (%Lf) in z axis vec: (%Lf,%Lf,%Lf)\n",angle,ret_vec.x, ret_vec.y,ret_vec.z);
	return (ret_vec);
}

t_vec3 rotate_xz(t_vec3 vec, long double angle){
	t_vec3 ret_vec;
	long double angle_in_rad;

	angle_in_rad = to_rad(angle);
	ret_vec.y = vec.y;
	ret_vec.x = (cosl(angle_in_rad) * vec.x) - (sinl(angle_in_rad) * vec.z);
	ret_vec.z = (sinl(angle_in_rad) * vec.x) + (cosl(angle_in_rad) * vec.z);
	//printf("rotated (%Lf) in y axis vec: (%Lf,%Lf,%Lf)\n",angle,ret_vec.x, ret_vec.y,ret_vec.z);
	return (ret_vec);
}

t_vec3 rotate_yz(t_vec3 vec, long double angle){
	t_vec3 ret_vec;
	long double angle_in_rad;

	angle_in_rad = to_rad(angle);
	ret_vec.x = vec.x;
	ret_vec.y = (cosl(angle_in_rad) * vec.y) - (sinl(angle_in_rad) * vec.z);
	ret_vec.z = (sinl(angle_in_rad) * vec.y) + (cosl(angle_in_rad) * vec.z);
	//printf("rotated (%Lf) in x axis vec: (%Lf,%Lf,%Lf)\n",angle,ret_vec.x, ret_vec.y,ret_vec.z);
	return (ret_vec);
}

#include "r_vec3.h"
#include <math.h>
#include <stdio.h>
t_vec3 rotate_xy(t_vec3 vec, long double angle){
	t_vec3 ret_vec;

	ret_vec.z = vec.z;
	ret_vec.x = (cos(angle) * vec.x) - (sin(angle) * vec.y);
	ret_vec.y = (sin(angle) * vec.x) + (cos(angle) * vec.y);
	printf("rotated (%Lf) x-y vec: (%Lf,%Lf,%Lf)\n",angle,ret_vec.x, ret_vec.y,ret_vec.z);
	return (ret_vec);
}

t_vec3 rotate_xz(t_vec3 vec, long double angle){
	t_vec3 ret_vec;

	ret_vec.y = vec.y;
	ret_vec.x = (cosl(angle) * vec.x) - (sinl(angle) * vec.z);
	ret_vec.z = (sinl(angle) * vec.x) + (cosl(angle) * vec.z);
	return (ret_vec);
}

t_vec3 rotate_yz(t_vec3 vec, long double angle){
	t_vec3 ret_vec;

	ret_vec.x = vec.x;
	ret_vec.z = (cosl(angle) * vec.z) - (sinl(angle) * vec.y);
	ret_vec.y = (sinl(angle) * vec.z) + (cosl(angle) * vec.y);
	return (ret_vec);
}

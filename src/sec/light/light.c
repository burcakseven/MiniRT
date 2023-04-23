#include "light.h"
#include <stdio.h>

t_bool computeIllumin(const t_intersection inter,t_light *light)
{
    t_vec3	light_dir;
    t_vec3	star_point;
    double	angle;

    light_dir = vec3_subtract(light->coordinate, inter.int_point);
    light_dir = vec3_normalize(light_dir);
    star_point = inter.int_point;
	angle = acos(vec3_dot(&inter.local_normal, &light_dir));
	printf("\n%f\n",angle);
	if(angle > 1.5708)
	{
	//no illumination 180D = 1.5...R
	light->brightness = 0.0;
	return (FALSE);
	}
	else
	{
	light->brightness = light->brightness * (1.0 - (angle / 1.5708));
	// printf("%Lf \n",light->brightness);
	// exit(1);
	return (TRUE);
	}
}
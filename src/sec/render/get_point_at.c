#include "render.h"

static t_vec3	vec3_add3(t_vec3 v1, t_vec3 v2, t_vec3 v3){
	return vec3_add(vec3_add(v1,v2),v3);
}

#include <stdio.h>

t_ray	get_point_at(t_virtural_canvas c, t_camera camera, int x, int y) {
	t_point3	dir;
	t_vec3		scale_x;
	t_vec3		scale_y;

	scale_x = vec3_scale(c.unit_h,x);
	scale_y = vec3_scale(c.unit_v,y);
	dir = vec3_add3(c.top_left,scale_x,scale_y);
	return (make_ray(camera.coordinate,dir));
}

#include "render.h"
#include <math.h>
#include <utils/utils.h>

#include <stdio.h>
t_virtural_canvas make_virtural_canvas(t_camera camera) {
	t_virtural_canvas	canvas;

	//front
	canvas.norm_j = vec3_normalize(camera.v_orientation);

	// left
	canvas.norm_i = vec3_cross(camera.up,canvas.norm_j);

	//top
	canvas.norm_k = vec3_cross(canvas.norm_j,canvas.norm_i);

	canvas.norm_i = vec3_scale(canvas.norm_i,(double) tanl(to_rad((double) camera.fov / 2)));
	canvas.norm_k = vec3_scale(canvas.norm_k,(ASPECT_RATIO * vec3_length(canvas.norm_i)));
	
	// tl = v_look + v_left + v_top
	canvas.top_left = vec3_add(vec3_add(canvas.norm_i,canvas.norm_k),vec3_add(canvas.norm_j,camera.coordinate));

	canvas.unit_h = vec3_scale(canvas.norm_i, -2.0 / (double) WIDTH);

	canvas.unit_v = vec3_scale(canvas.norm_k, -2.0 / (double) (WIDTH));
	return (canvas);
}

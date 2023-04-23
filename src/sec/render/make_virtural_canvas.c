#include "render.h"
#include <math.h>
#include <utils/utils.h>

#include <stdio.h>
t_virtural_canvas make_virtural_canvas(t_camera camera) {
	t_virtural_canvas	canvas;

	printf("initializing.\n");
	//front
	canvas.norm_j = vec3_normalize(camera.v_orientation);
	printf("norm_j[%Lf,%Lf,%Lf]\n",canvas.norm_j.x,canvas.norm_j.y,canvas.norm_j.z);
	// left
	canvas.norm_i = vec3_cross(camera.up,canvas.norm_j);
	printf("norm_i[%Lf,%Lf,%Lf]\n",canvas.norm_i.x,canvas.norm_i.y,canvas.norm_i.z);
	//top
	canvas.norm_k = vec3_cross(canvas.norm_j,canvas.norm_i);
	printf("norm_k[%Lf,%Lf,%Lf]\n",canvas.norm_k.x,canvas.norm_k.y,canvas.norm_k.z);
	

	printf("scaling i and k.\n");
	canvas.norm_i = vec3_scale(canvas.norm_i,(double) tanl(to_rad((double) camera.fov / 2)));
	printf("norm_i[%Lf,%Lf,%Lf]\n",canvas.norm_i.x,canvas.norm_i.y,canvas.norm_i.z);
	canvas.norm_k = vec3_scale(canvas.norm_k,ASPECT_RATIO / 2.0);
	printf("norm_k[%Lf,%Lf,%Lf]\n",canvas.norm_k.x,canvas.norm_k.y,canvas.norm_k.z);
	
	printf("calculating top-left.\n");
	// tl = v_look + v_left + v_top
	canvas.top_left = vec3_add(vec3_add(canvas.norm_i,canvas.norm_j),vec3_add(canvas.norm_j,camera.coordinate));
	printf("top_left[%Lf,%Lf,%Lf]\n",canvas.top_left.x,canvas.top_left.y,canvas.top_left.z);

	printf("calculating units.\n");
	canvas.unit_h = vec3_scale(canvas.norm_i, -2.0 / (double) WIDTH);
	printf("unit_h[%Lf,%Lf,%Lf]\n",canvas.unit_h.x,canvas.unit_h.y,canvas.unit_h.z);

	canvas.unit_v = vec3_scale(canvas.norm_j, -2.0 / (double) HEIGHT);
	printf("unit_v[%Lf,%Lf,%Lf]\n",canvas.unit_v.x,canvas.unit_v.y,canvas.unit_v.z);
	return (canvas);
}

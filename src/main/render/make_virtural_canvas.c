#include "render.h"
#include <math.h>
#include <utils/utils.h>

t_virtural_canvas make_virtural_canvas(t_camera camera) {
	t_virtural_canvas	canvas;

	canvas.v_camera = camera.coordinate;
	canvas.norm_k = vec3_normalize(camera.v_orientation);
	printf("slen of k axis: %f\n",vec3_length(canvas.norm_k));
	canvas.norm_i = vec3_normalize(vec3_cross((point3){0,1,0},canvas.norm_k));
	canvas.norm_j = vec3_normalize(vec3_cross(canvas.norm_k,canvas.norm_i));
	canvas.norm_i = vec3_scale(canvas.norm_i,tan(to_rad((double) camera.fov / 2.0)));
	canvas.norm_j = vec3_scale(canvas.norm_j,ASPECT_RATIO * vec3_length(canvas.norm_i));

	printf("slen of i axis: %f\n",vec3_length(canvas.norm_i));
	printf("slen of j axis: %f\n",vec3_length(canvas.norm_j));

	canvas.canva_h.orig = vec3_add(canvas.norm_i,canvas.norm_k);
	canvas.canva_h.dir = vec3_add(canvas.norm_k,vec3_scale(canvas.norm_i,-1.0));
	canvas.canva_v.orig = vec3_add(canvas.norm_j,canvas.norm_k);
	canvas.canva_v.dir = vec3_add(canvas.norm_k,vec3_scale(canvas.norm_j,-1.0));
	canvas.v_unit_h = vec3_scale(vec3_subtract(canvas.canva_h.dir,canvas.canva_h.orig),(double) 1 / WIDTH);
	canvas.v_unit_v = vec3_scale(vec3_subtract(canvas.canva_v.dir,canvas.canva_v.orig),(double) 1 / HEIGHT);
	return (canvas);
}

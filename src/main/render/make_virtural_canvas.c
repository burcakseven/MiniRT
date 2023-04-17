#include "render.h"
#include <math.h>
#include <utils/utils.h>

t_virtural_canvas make_virtural_canvas(t_camera camera) {
	t_virtural_canvas	canvas;
	t_ray				horizontal;
	t_ray				vertical;
	t_ray				zindex;
	t_vec3				scaled_vec;

	scaled_vec = vec3_scale(convert_point3(camera.v_orientation),(double) camera.fov / 2.0);
}

	
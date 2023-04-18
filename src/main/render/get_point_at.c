#include "render.h"

static t_vec3	vec3_add3(t_vec3 v1, t_vec3 v2, t_vec3 v3){
	return vec3_add(vec3_add(v1,v2),v3);
}

#include <stdio.h>
point3		get_point_at(t_virtural_canvas c, int x, int y) {
	point3	pnt_tl;
	point3	pnt_px;

	point3 scaledx = vec3_scale(c.v_unit_h,x);
	point3 scaledy = vec3_scale(c.v_unit_v,y);
	pnt_tl = vec3_add3(c.norm_i,c.norm_j,c.norm_k);
	pnt_px = vec3_add(scaledx,scaledy);
	//printf("scaledX[%Lf,%Lf,%Lf]\n",scaledx.x,scaledx.y,scaledx.z);
	point3 res = vec3_add3(pnt_tl,pnt_px,c.v_camera);
	
	return (res);
}

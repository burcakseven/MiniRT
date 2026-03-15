#include "render.h"

static t_vec3 vec3_add3(t_vec3 v1, t_vec3 v2, t_vec3 v3) {
  return vec3_add(vec3_add(v1, v2), v3);
}

#include <stdio.h>
point3 get_point_at(t_virtural_canvas c, int x, int y) {

  point3 scaledx = vec3_scale(c.v_unit_h, x);
  point3 scaledy = vec3_scale(c.v_unit_v, y);
  point3 ray_dir = vec3_add(c.canva_h.orig,vec3_add(scaledx, scaledy));
  // printf("scaledX[%Lf,%Lf,%Lf]\n",scaledx.x,scaledx.y,scaledx.z);

  return (vec3_normalize(ray_dir));
}

#include "../vec3/r_vec3.h"
#include "render.h"
#include <math.h>
#include <stdio.h>
#include <utils/utils.h>

t_virtural_canvas make_virtural_canvas(t_camera camera) {
  t_virtural_canvas canvas;
  t_vec3 canvas_half_width;
  t_vec3 canvas_half_height;

  canvas.camera_pos = convert_point3(camera.coordinate);
  canvas.norm_k = vec3_normalize(convert_point3(camera.v_orientation));
  printf("slen of k axis: %f\n", vec3_length(canvas.norm_k));
  canvas.norm_i = vec3_normalize(vec3_cross((point3){0, 1, 0}, canvas.norm_k));
  canvas.norm_j = vec3_normalize(vec3_cross(canvas.norm_k, canvas.norm_i));
  canvas_half_width =
      vec3_scale(canvas.norm_i, tan(to_rad((double)camera.fov / 2.0)));
  canvas_half_height =
      vec3_scale(canvas.norm_j, vec3_length(canvas_half_width) / ASPECT_RATIO);

  printf("slen of i axis: %f\n", vec3_length(canvas_half_width));
  printf("slen of j axis: %f\n", vec3_length(canvas_half_height));

  point3 top_left_edge = vec3_add(
      vec3_subtract(canvas.norm_k, canvas_half_width), canvas_half_height);
  canvas.canva_h.orig = top_left_edge;
  canvas.canva_v.orig = top_left_edge;

  canvas.canva_h.dir = vec3_add(top_left_edge, vec3_scale(canvas_half_width, 2.0));
  canvas.canva_v.dir = vec3_subtract(top_left_edge, vec3_scale(canvas_half_height, 2.0));
  canvas.v_unit_h = vec3_scale(canvas_half_width, 2.0 / WIDTH);
  canvas.v_unit_v = vec3_scale(canvas_half_height, -2.0 / HEIGHT);
  return (canvas);
}

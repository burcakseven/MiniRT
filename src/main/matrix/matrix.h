#ifndef MATRIX_H
#define MATRIX_H

#include <ray.h>
#include "../frame/frame.h"
#include <gc.h>
#include <scene.h>

void translation(point3 ray, point3 trans_data);
float *transformationMatrix(float angleX, float angleY, float angleZ, float *matrix);
float *matrix_inverse(float matrix[9]);
t_vec3 matrix_vector_multiply(float matrix[9], t_vec3 vector);

#endif
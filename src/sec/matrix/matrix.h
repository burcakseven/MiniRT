#ifndef MATRIX_H
#define MATRIX_H

#include <ray/ray.h>
#include <vec3/vec3.h>
#include <math.h>
#include <gc/gc.h>
#include <utils/utils.h>

float *transformationMatrix(float angleX, float angleY, float angleZ, float *matrix);
float *matrix_inverse(float matrix[9]);
t_vec3 matrix_vector_multiply(float matrix[9], t_vec3 vector);
float *init_matrix(t_point3 normal_vec, int inverse_flag);

#endif
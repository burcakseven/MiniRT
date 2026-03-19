#ifndef MATRIX_H
#define MATRIX_H

#include <frame/frame.h>
#include <gc/gc.h>
#include <parser/scene.h>
#include <ray/ray.h>

t_vec3 translation(point3 ray, point3 trans_data);
float *transformationMatrix(float radX, float angleY, float radZ,
                            float *matrix);
float *matrix_inverse(float matrix[9]);
t_vec3 matrix_vector_multiply(float matrix[9], t_vec3 vector);
float *init_matrix(point3 normal_vec, int inverse_flag);

#endif
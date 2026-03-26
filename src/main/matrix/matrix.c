#include "matrix.h"
#include <math.h>

t_vec3 translation(point3 ray, point3 trans_data) {
  return (vec3_add(ray, trans_data));
}

float *transformationMatrix(float radX, float radY, float radZ, float *matrix) {

  float cosX = cos(radX), sinX = sin(radX);
  float cosY = cos(radY), sinY = sin(radY);
  float cosZ = cos(radZ), sinZ = sin(radZ);

  matrix[0] = cosY * cosZ;
  matrix[1] = -cosX * sinZ + sinX * sinY * cosZ;
  matrix[2] = sinX * sinZ + cosX * sinY * cosZ;

  matrix[3] = cosY * sinZ;
  matrix[4] = cosX * cosZ + sinX * sinY * sinZ;
  matrix[5] = -sinX * cosZ + cosX * sinY * sinZ;

  matrix[6] = -sinY;
  matrix[7] = sinX * cosY;
  matrix[8] = cosX * cosY;
  return matrix;
}

float *matrix_inverse(float matrix[9]) {
  float *inverse = new (sizeof(float) * 9);
  float det = matrix[0] * (matrix[4] * matrix[8] - matrix[5] * matrix[7]) -
              matrix[1] * (matrix[3] * matrix[8] - matrix[5] * matrix[6]) +
              matrix[2] * (matrix[3] * matrix[7] - matrix[4] * matrix[6]);
  if (det == 0)
    ft_error("Matrix is singular");

  float inv_det = 1.0 / det;
  inverse[0] = (matrix[4] * matrix[8] - matrix[5] * matrix[7]) * inv_det;
  inverse[1] = (matrix[2] * matrix[7] - matrix[1] * matrix[8]) * inv_det;
  inverse[2] = (matrix[1] * matrix[5] - matrix[2] * matrix[4]) * inv_det;
  inverse[3] = (matrix[5] * matrix[6] - matrix[3] * matrix[8]) * inv_det;
  inverse[4] = (matrix[0] * matrix[8] - matrix[2] * matrix[6]) * inv_det;
  inverse[5] = (matrix[2] * matrix[3] - matrix[0] * matrix[5]) * inv_det;
  inverse[6] = (matrix[3] * matrix[7] - matrix[4] * matrix[6]) * inv_det;
  inverse[7] = (matrix[1] * matrix[6] - matrix[0] * matrix[7]) * inv_det;
  inverse[8] = (matrix[0] * matrix[4] - matrix[1] * matrix[3]) * inv_det;
  return inverse;
}

t_vec3 matrix_vector_multiply(float matrix[9], t_vec3 vector) {
  t_vec3 result;
  result.x = matrix[0] * vector.x + matrix[1] * vector.y + matrix[2] * vector.z;
  result.y = matrix[3] * vector.x + matrix[4] * vector.y + matrix[5] * vector.z;
  result.z = matrix[6] * vector.x + matrix[7] * vector.y + matrix[8] * vector.z;
  return result;
}

float *init_matrix(point3 normal_vec, int inverse_flag) {
  float *matrix;
  float *temp;

  matrix = new (sizeof(float) * 9);
  temp = new (sizeof(float) * 9);

  float radZ = atan2(-normal_vec.x, normal_vec.y);
  float radX = atan2(normal_vec.z, normal_vec.y);
  float radY = 0;
  temp = transformationMatrix(radX, radY, radZ, matrix);
  if (inverse_flag == 1)
    matrix = matrix_inverse(temp);
  del(temp);
  return matrix;
}

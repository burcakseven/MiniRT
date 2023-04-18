#include <ray.h>
#include "../frame/frame.h"
#include <gc.h>
#include <scene.h>

void translation(point3 ray, point3 trans_data)
{
    return (vec3_add(ray,trans_data));
}

void calculateTransformationMatrix(float angleX, float angleY, float angleZ, float *matrix)
{
    float radX = deg2rad(angleX);
    float radY = deg2rad(angleY);
    float radZ =  deg2rad(angleZ);

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
}

float [3][3]matrix_inverse(float matrix[3][3])
{
    float **inverse = (float **)new(sizeof(float *) * 3);
    int i = 0;
    while (i < 3)
        inverse[i++] = (float *)new(sizeof(float) * 3);//malloc kısmı başka fonksiyona taşınabilir

    float det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]) -
                matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
                matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    if (det == 0)
        ft_error();

    float inv_det = 1.0 / det;
    inverse[0][0] = (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]) * inv_det;
    inverse[0][1] = (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]) * inv_det;
    inverse[0][2] = (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]) * inv_det;
    inverse[1][0] = (matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]) * inv_det;
    inverse[1][1] = (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]) * inv_det;
    inverse[1][2] = (matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2]) * inv_det;
    inverse[2][0] = (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]) * inv_det;
    inverse[2][1] = (matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1]) * inv_det;
    inverse[2][2] = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) * inv_det;
    return inverse;
}

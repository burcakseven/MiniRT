//
// Created by emakas on 12.04.2023.
//

#include <ray/ray.h>
#include <vec3/vec3.h>
#include <matrix/matrix.h>

t_ray make_ray(t_point3 origin, t_vec3 direction)
{
    t_ray r;
    vec3_init(&r.orig, origin.x, origin.y, origin.z);
    vec3_init(&r.dir, direction.x, direction.y, direction.z);
    r.diff = vec3_subtract(r.dir, r.orig);
    r.diff_normal = vec3_normalize(r.diff);
    return r;
}

t_point3 ray_at(t_ray r, double t) {
    t_vec3 result;
    result = vec3_scale(r.dir, t);
    result = vec3_add(r.orig, result);
    return result;
}

t_ray transformed_ray(t_point3 normal_vec, t_ray r, int inverse_flag)
{
    float *matrix;
    t_ray new_r;

	matrix = init_matrix(normal_vec,inverse_flag);
    new_r.dir = matrix_vector_multiply(matrix,r.dir);
    new_r.dir = vec3_normalize(new_r.dir);
    new_r.orig = matrix_vector_multiply(matrix,r.orig);
    del(matrix);
    return new_r;
}


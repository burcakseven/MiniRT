//
// Created by emakas on 12.04.2023.
//

#include <ray/ray.h>
#include <frame/frame.h>

t_ray make_ray(point3 origin, t_vec3 direction)
{
    t_ray r;
    vec3_init(&r.orig, origin.x, origin.y, origin.z);
    vec3_init(&r.dir, direction.x, direction.y, direction.z);
    return r;
}

point3 ray_at(t_ray r, double t) {
    t_vec3 result;
    result = vec3_scale(r.dir, t);
    result = vec3_add(r.orig, result);
    return result;
}

t_ray transformed_ray(point3 normal_vec, t_ray r, int inverse_flag)
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

color ray_color (const t_ray *r)
{
    double t;
    color added;
    point3 sp = {0,0,1};
    if(hit_sphere(sp,0.5,*r).root_number)
    {
        color cl = {1, 0, 0};
        //printf("MERH\nA");
        return cl;
    }
    // if(hit_plane(sp,(point3){0,1,0},*r))
    // {
    //     color cl = {1, 0, 0};
    //     //printf("MERH\nA");
    //     return cl;
    // }
    t = 0.5 *(r->dir.y) +1.0;
    color full = {1.0,1.0,1.0};
    color blue = {0.5, 0.7, 1.0};

    added = vec3_add(vec3_scale(full,(1.0-t)),vec3_scale(blue, t));
    return  added;
}

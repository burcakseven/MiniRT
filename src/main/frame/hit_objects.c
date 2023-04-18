#include "frame.h"

/* int hit_sphere(const point3 center, double rad, const t_ray r)
{
    t_vec3 oc;

    oc = vec3_subtract(r.orig,center);
    double a = vec3_dot(&r.dir, &r.dir);
    double b = 2.0 * vec3_dot(&oc, &r.dir);
    double c = vec3_dot(&oc,&oc) - rad*rad;
    double discr = b*b -4*a*c;
    if(discr > 0)
        return 1;
    return 0;
}
 */
double plane_const(const point3 center,point3 normalize_vec)
{
    double d;
    d = -1 * vec3_dot(&center,&normalize_vec);
    return d;
}

double hit_plane(const point3 center, const point3 vec1, const t_ray r)
{
    float *matrix;
    float *temp;
    double t;
    t_ray new_r;

    matrix = new(sizeof(float)*9);
    temp = new(sizeof(float)*9);
    temp = transformationMatrix(vec1.x,vec1.y,vec1.z,matrix);
    matrix = matrix_inverse(temp);
    del(temp);
    new_r.orig = matrix_vector_multiply(matrix,r.orig);
    new_r.dir = matrix_vector_multiply(matrix,r.dir);
    t = new_r.orig.z / vec3_scale(new_r.dir,-1).z;

    return t;
}

#ifndef UTILS_H
# define UTILS_H
# include <math.h>
# include <vec3/r_vec3.h>

long double to_rad(long double degrees);

point3 convert_point3(float coordinate[3]);
int is_equal(double first, double second);

#endif
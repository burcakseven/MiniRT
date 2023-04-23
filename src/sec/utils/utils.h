#ifndef UTILS_H
# define UTILS_H
# include <math.h>
# include <vec3/vec3.h>
#define TRUE 0xFF
#define FALSE 0x00

typedef unsigned char t_bool;
long double to_rad(long double degrees);
void ft_error(char *msg);
int is_equal(double first, double second);
t_point3 convert_point3(float coordinate[3]);

#endif
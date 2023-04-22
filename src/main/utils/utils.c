#include <utils/utils.h>

long double to_rad(long double degrees) {
    return degrees * M_PI / 180.0;
}

t_point3 convert_point3(float coordinate[3]){
    t_point3  point;

    point.x = (long double) coordinate[0];
    point.y = (long double) coordinate[1];
    point.z = (long double) coordinate[2];
	return (point);
}

int is_equal(double first, double second)
{
    if(fabs(first-second) < __DBL_EPSILON__)
        return (1);
    return (0);
}
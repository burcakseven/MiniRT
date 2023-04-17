#include <utils/utils.h>

long double to_rad(long double degrees) {
    return degrees * M_PI / 180.0;
}

point3 convert_point3(float coordinate[3]){
    point3  point;

    point.x = (long double) coordinate[0];
    point.y = (long double) coordinate[1];
    point.z = (long double) coordinate[2];
	return (point);
}

#include "frame.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int rgb_color(color colour)
{
    int ir;
	int ig;
	int ib;

	ir = (int)(255.999 * colour.x);
    ig = (int)(255.999 * colour.y);
    ib = (int)(255.999 * colour.z);
	return(ir<< 16 | ig << 8 | ib);
}

double deg2rad(double degrees)
{
    return degrees * M_PI / 180.0;
}

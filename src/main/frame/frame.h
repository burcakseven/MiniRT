#ifndef FRAME_H
# define FRAME_H

#include <mlx.h>
#include <stdio.h>
#include "r_vec3.h"


# define WIDTH		1920
# define HEIGHT		1080

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}              t_data;

int rgb_color(int r,int g,int b);

#endif
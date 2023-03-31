#ifndef FRAME_H
# define FRAME_H

#include <mlx.h>

# define WIDTH		1920
# define HEIGHT		1080

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}              t_data;


#endif
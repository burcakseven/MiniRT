//
// Created by emakas on 10.04.2023.
//

#ifndef RENDER_H
# define RENDER_H
# include <vec3/r_vec3.h>
# include <ray/ray.h>
# include <stdlib.h>
# include <mlx.h>
# include <parser/scene.h>
# define WIDTH			1000
# define HEIGHT			1000
# define ASPECT_RATIO	(double) WIDTH / (double) HEIGHT
# define WINDOW_TITLE	"miniRTE"


typedef struct	s_canvas {
	void	*img;
	void	*addr;
	int		bits_ppx;
	int		line_length;
	int		endian;
}			t_canvas;

typedef struct	s_mlx {
	void	*mlx;
	void	*win;
}			t_mlx;

typedef struct s_virtural_canvas
{
	t_ray	horizontal;
	t_ray	vertical;
} t_virtural_canvas;


t_canvas	get_canvas();
int			put_pixel_to_img(int x, int y, color colour);
void		print_img();
t_mlx		get_mlx();
t_virtural_canvas	make_virtural_canvas(t_camera camera);

#endif //MINIRT_RENDER_H

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
# define WIDTH			500
# define HEIGHT			500
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
	t_point3	norm_k;
	t_point3	norm_i;
	t_point3	norm_j;
	t_ray	canva_h;
	t_ray	canva_v;
	t_vec3	v_unit_v;
	t_vec3	v_unit_h;
	int		width;
	int		height;
	t_point3	v_camera;
} t_virtural_canvas;


t_canvas	get_canvas();
int			put_pixel_to_img(int x, int y, t_color colour);
void		print_img();
t_mlx		get_mlx();
t_virtural_canvas	make_virtural_canvas(t_camera camera);
t_point3		get_point_at(t_virtural_canvas c, int x, int y);

#endif //MINIRT_RENDER_H

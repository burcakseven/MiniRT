//
// Created by emakas on 10.04.2023.
//

#ifndef RENDER_H
# define RENDER_H
# include <vec3/vec3.h>
# include <scene/scene.h>
# include <ray/ray.h>
# include <stdlib.h>
# include <mlx.h>
# define WIDTH			1024
# define HEIGHT			720
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
	t_point3	norm_k; // top of camera
	t_point3	norm_i; // left of camera
	t_point3	norm_j; // front of camera
	t_point3	top_left; // top left point of canvas
	t_point3	unit_v; // -i / WIDTH
	t_point3	unit_h; // -k / HEIGHT
} t_virtural_canvas;


t_canvas			get_canvas();
int					put_pixel_to_img(int x, int y, t_color colour);
void				print_img();
t_mlx				get_mlx();
t_virtural_canvas	make_virtural_canvas(t_camera camera);
t_ray				get_point_at(t_virtural_canvas c, t_camera camera, int x, int y);
void				render_scene(t_scene scene);
#endif //MINIRT_RENDER_H

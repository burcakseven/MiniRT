#include "scene.h"

void fill_data(t_scene *scene)
{
    scene->ambient.color = -1;
    scene->camera.fov = -1;
    scene->light.color = -1;
    scene->sphere = new(sizeof(t_sphere)*10); // realloc kullanılabilir ya da linkedlist oluşturulabilir
    scene->plane = new(sizeof(t_plane)*10);
    scene->cylinder = new(sizeof(t_cylinder)*10);
}

void	fill_data_operations(char *arg, t_scene *scene)
{
    int fd;

    fd = check_file(arg);
    fill_data(scene);
	read_scene_data(scene,fd);
}

void	my_mlx_pixel_put(void *addr, int bits_per_pixel, int line_len,  int x, int y, int color)
{
	char	*dst;

	dst = addr + (y * line_len + x * (bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

#include <mlx.h>
int	main(int ac, char **av)
{
	t_scene scene;
	if (ac != 2)
	{
		ft_error();
	}
	fill_data_operations(av[1], &scene);

    void *mlx;
    void *win;
    
    void *img;
    char *img_addr;
    int bits_per_pixel;
    int image_line_len;
    int image_endian;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1080, 1080, "WINDOW");
    img = mlx_new_image(mlx,1080, 1080);

    img_addr = (char *) mlx_get_data_addr(img, &bits_per_pixel, &image_line_len, &image_endian);

    for (int i = 0; i < 1080; i++){
        for (int j = 0; j < 1080; j++){
            my_mlx_pixel_put(img_addr, bits_per_pixel, image_line_len, i, j, 0xFF0000);
        }
    }
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);
}
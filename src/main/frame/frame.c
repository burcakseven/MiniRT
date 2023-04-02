#include "frame.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int rgb_color(int r,int g,int b)
{
	return(r<< 16 | g << 8 | b);
}

void print_color(t_data *img)
{

    for (int j = 255-1; j >= 0; --j) {
        for (int i = 0; i < 255; ++i) {
            double r = (double)i / (255-1);
            double g = (double)j / (255-1);
            double b = 0.25;

            int ir = (int)(255.999 * r);
            int ig = (int)(255.999 * g);
            int ib = (int)(255.999 * b);
			int rgb = rgb_color(ir,ig,ib);
			my_mlx_pixel_put(img, i, j, rgb);
        }
    }

}

void	init_mlx(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	print_color(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

int	main()
{
	init_mlx();
}

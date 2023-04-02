#include "frame.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int rgb_color(color colour)
{
	int ir;
	int ig;
	int ib;

	ir = (int)(255.999 * colour.x);
    ig = (int)(255.999 * colour.y);
    ib = (int)(255.999 * colour.z);
	return(ir<< 16 | ig << 8 | ib);
}

void print_color(t_data *img)
{

    for (int j = 255-1; j >= 0; --j) {
        for (int i = 0; i < 255; ++i) {
            double r = (double)i / (255-1);
            double g = (double)j / (255-1);
            double b = 0.25;

			color pixel_color = {r, g, b};
			int rgb = rgb_color(pixel_color);
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

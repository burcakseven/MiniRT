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

double deg2rad(double degrees) {
    return degrees * M_PI / 180.0;
}

void print_color(t_data *img)
{
    // Image
    const double aspect_ratio = 16.0 / 16.0;
    const int image_width = 400;
    const int image_height = (int)(image_width / aspect_ratio);

    // Camera
    t_vec3 origin = { -50.0, 0, 20 };
    t_vec3 orientation = { 0.0, 0.0, 1.0 };
    // double fov = 70.0;

    double viewport_height = 4.0;
    double viewport_width = aspect_ratio * viewport_height;

    t_vec3 normalz = {0.0, 1.0, 0.0};
    t_vec3 horizontal = vec3_scale(vec3_normalize(vec3_cross(orientation,normalz)),viewport_width);
    t_vec3 vertical = vec3_scale(vec3_normalize(vec3_cross(horizontal, orientation)),viewport_height);

    t_vec3 lower_left_corner = vec3_subtract(vec3_subtract(vec3_subtract(origin, vec3_scale(horizontal, 0.5)),
                                        vec3_scale(vertical, 0.5)), orientation);

    // Render
    printf("P3\n%d %d\n255\n", image_width, image_height);

    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            double u = (double)i / (image_width - 1);
            double v = (double)j / (image_height - 1);
            t_ray r = make_ray(origin, vec3_add(lower_left_corner, vec3_add(vec3_scale(horizontal, u),
                                            vec3_scale(vertical, v))));

            color pixel_color = ray_color(&r);
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

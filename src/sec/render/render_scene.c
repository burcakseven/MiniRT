#include "render.h"
#include <scene/scene.h>
#include <objects/objects.h>
#define WIDTH 500
#define HEIGHT 500
#include <stdio.h>
#include <utils/utils.h>


t_bool get_screen_point(t_camera camera, int screen_x, int screen_y, t_ray *camera_ray) {
	t_point3	point;

	point = vec3_add(camera.center, vec3_scale(camera.u,screen_x));
	point = vec3_add(point, vec3_scale(camera.v, screen_y));
    *camera_ray = make_ray(camera.coordinate, point);
	return (TRUE);
}

//void render_scene(t_scene scene){
//	t_ray			camera_ray;
//	t_intersection	intersect;
//	t_color			color;
//	double 			x_fact;
//	double			y_fact;
//	int 			x_index;
//	int 			y_index;
//	double			normX;
//	double			normY;

//	x_fact = 1.0 / (WIDTH / 2.0);
//	y_fact = 1.0 / (HEIGHT / 2.0);
//	printf("deneme\n");
//	y_index = 0;
//	while (y_index < HEIGHT)
//	{
//		x_index = 0;
//		while (x_index < WIDTH)
//		{
//			normX = x_index * x_fact - 1.0;
//			normY = y_index * y_fact - 1.0;
//			get_screen_point(scene.camera,x_index,y_index,&camera_ray);
//			if(intersec_sphere(camera_ray, &intersect))
//			{
//				color = (t_color){1,1,0};
//				put_pixel_to_img(x_index, y_index, color);
//			}
//			else
//			{
//				color = (t_color){1,0,0};
//				put_pixel_to_img(x_index, y_index, color);
//			}
//		x_index++;
//		}
//		y_index++;
//	}
//}

void render_scene(t_scene scene){
	t_virtural_canvas c;
	t_ray ray;
	t_color color;
	t_intersection intersect;
	int x_index;
	int y_index;

	c = make_virtural_canvas(scene.camera);
	y_index = 0;
	while (y_index < HEIGHT){
		x_index = 0;
		while (x_index < WIDTH){
			ray = get_point_at(c,scene.camera,x_index,y_index);
			printf("(%Lf,%Lf,%Lf)->(%Lf,%Lf,%Lf)\n",ray.orig.x,ray.orig.y,ray.orig.z,ray.dir.x,ray.dir.y,ray.dir.z);
			if(hit_sphere((t_point3){0,-10,0},0.1,ray).root_number >= 0)
			{
				color = (t_color){1,1,0};
				put_pixel_to_img(x_index, y_index, color);
			}
			else
			{
				color = (t_color){1,0,0};
				put_pixel_to_img(x_index, y_index, color);
			}
			x_index++;
		}
		y_index++;
	}
}
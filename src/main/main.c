#include <unistd.h>
#include <frame/frame.h>
#include <stdio.h>
#include <mlx.h>
#include <parser/scene.h>
#include <render/render.h>
#include <ray/ray.h>
#include <utils/utils.h>

t_canvas get_canvas(){
    static t_canvas *canvas = NULL;
    t_mlx mlx;

    mlx = get_mlx();
    if (canvas == NULL) {
        canvas = malloc(sizeof *canvas);
        canvas->img = mlx_new_image(mlx.mlx,WIDTH,HEIGHT);
        canvas->addr = mlx_get_data_addr(canvas->img, &(canvas->bits_ppx),\
        &(canvas->line_length),&(canvas->endian));
    }
    return (*canvas);
}

t_camera create_camera(){
    t_camera camera;

    camera.coordinate.x = 3.0f;
    camera.coordinate.y = 0.0f;
    camera.coordinate.z = 4.0f;
    camera.v_orientation.x = 1.0f;
    camera.v_orientation.y = 0.0f;
    camera.v_orientation.z = 0.0f;

    camera.fov = 90;
    return camera;
}

t_cylinder create_cylinder(){

    t_cylinder cylinder;
    cylinder.color = 0xFF0000;
    cylinder.coordinate.x = 1.0f;
    cylinder.coordinate.y = 1.0f;
    cylinder.coordinate.z = 1.0f;
    cylinder.v_axis.x = 0.0f;
    cylinder.v_axis.y = 1.0f;
    cylinder.v_axis.z = 0.0f;
    cylinder.diameter = 0.5f;
    cylinder.height = 1.0f;
    return cylinder;
}

/**
 * For cylinder
 * @return
 */
t_point3 find_intercept(t_ray ray, t_sphere sphere, t_color *colour){
	t_point3 point;
	(void) ray;
	(void) sphere;
	(void) colour;
    point.x = 1;
    point.y = 1;
    point.z = 1;
	return (point);
}


/**
 * reduce colour according to relation between light source and interception point
*/
void reduce_color(t_light light, t_point3 intercept, t_color *colour){
    (void) light;
    (void) intercept;
    (void) colour;

    return ;
}

void render_scene(t_scene scene) {
    t_color colour;
    //point3 intersection;
    t_ray ray;
    t_virtural_canvas canvas;
    int h = 0;

    canvas = make_virtural_canvas(scene.camera);
    ray.orig = scene.camera.coordinate;
    while (h < HEIGHT){
        int w = 0;
        while (w < WIDTH) {
            /* BUNU */
            ray.dir = get_point_at(canvas,w,h);
            colour = ray_color(&ray);
            put_pixel_to_img(w,h,colour);
            w++;
        }
        h++;
    }
}

void show_img(){
    t_mlx mlx;
    t_canvas canvas;

    mlx = get_mlx();
    canvas = get_canvas();
    mlx_put_image_to_window(mlx.mlx,mlx.win,canvas.img,0,0);
    mlx_loop(mlx.mlx);
}



#ifndef TEST
int	main(int ac, char **av)
{
    t_scene scene;
    t_cylinder cylinder = create_cylinder();
	scene.camera = create_camera();
	//scene = create_scene(av[1]);
    render_scene(scene);
    show_img();
    return 0;
}
#endif

#ifdef TEST
#include <stdio.h>
int main(){
	printf("DO NOT TEST ME!!\n")
}
#endif

/**
 * Test Codes
 */



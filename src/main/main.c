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

    camera.coordinate[0] = 0.0f;
    camera.coordinate[1] = 0.0f;
    camera.coordinate[2] = 0.0f;
    camera.v_orientation[0] = 0.0f;
    camera.v_orientation[1] = 0.0f;
    camera.v_orientation[2] = 1.0f;
    camera.viewport_height = 2.0;
    camera.viewport_width = ASPECT_RATIO * camera.viewport_height;

    camera.fov = 60;
    return camera;
}

t_cylinder create_cylinder(){

    t_cylinder cylinder;
    cylinder.color = 0xFF0000;
    cylinder.coordinate[0] = 1.0f;
    cylinder.coordinate[1] = 1.0f;
    cylinder.coordinate[2] = 1.0f;
    cylinder.v_axis[0] = 0.0f;
    cylinder.v_axis[1] = 1.0f;
    cylinder.v_axis[2] = 0.0f;
    cylinder.diameter = 0.5f;
    cylinder.height = 1.0f;
    return cylinder;
}

/**
 * For cylinder
 * @return
 */
point3 find_intercept(t_ray ray, t_sphere sphere, color *colour){
	point3 point;
	(void) ray;
	(void) sphere;
	(void) colour;
    point.x = 1;
    point.y = 1;
    point.z = 1;
	return (point);
}

t_ray create_ray(point3 origin, t_vec3 direction){
    t_ray ray;

    ray.orig = origin;
    ray.dir = direction;
    return (ray);
}

point3 convert_point3(float coordinate[3]){
    point3  point;

    point.x = (long double) coordinate[0];
    point.y = (long double) coordinate[1];
    point.z = (long double) coordinate[2];
	return (point);
}

/**
 * reduce colour according to relation between light source and interception point
*/
void reduce_color(t_light light, point3 intercept, color *colour){
    (void) light;
    (void) intercept;
    (void) colour;

    return ;
}

void render_scene(t_scene scene){
    color       colour;
    t_canvas    canvas;
    point3      intersection;
    t_ray       ray;

    canvas = get_canvas();

    ray.orig = convert_point3(scene.camera.coordinate);

    //printf("old vec: (%Lf,%Lf,%Lf) -> (%Lf, %Lf, %Lf)\n",ray.orig.x,ray.orig.y,ray.orig.z,ray.dir.x,ray.dir.y,ray.dir.z);
    ray.dir = vec3_add(convert_point3(scene.camera.v_orientation), convert_point3(scene.camera.coordinate));
    printf("sum vec: (%Lf,%Lf,%Lf) -> (%Lf, %Lf, %Lf)\n",ray.orig.x,ray.orig.y,ray.orig.z,ray.dir.x,ray.dir.y,ray.dir.z);
    ray.dir = rotate_xz(ray.dir,scene.camera.fov/2);
    printf("rotated vec: (%Lf,%Lf,%Lf) -> (%Lf, %Lf, %Lf)\n",ray.orig.x,ray.orig.y,ray.orig.z,ray.dir.x,ray.dir.y,ray.dir.z);
    ray.dir = rotate_yz(ray.dir,scene.camera.fov/2);
    printf("rotated vec: (%Lf,%Lf,%Lf) -> (%Lf, %Lf, %Lf)\n",ray.orig.x,ray.orig.y,ray.orig.z,ray.dir.x,ray.dir.y,ray.dir.z);


    int v_index = 0;
    // render image
    while (v_index < HEIGHT){
        //printf("old vec: (%f,%f,%f)\n",ray.dir.x,ray.dir.y,ray.dir.z);
        ray.dir = rotate_yz(ray.dir,-((double) v_index * ((double) scene.camera.fov / HEIGHT)));
        
        //ray.dir = rotate_zy(ray.dir,-((double) v_index * ((double) scene.camera.fov / HEIGHT)));
        //printf("rotated y-z vec: (%f,%f,%f)\n",ray.dir.x,ray.dir.y,ray.dir.z);
        
        int h_index = 0;
        while (h_index < WIDTH) {
            ray.dir = rotate_xz(ray.dir,-((double) h_index * ((double) scene.camera.fov / WIDTH)));
            colour = ray_color(&ray);
            put_pixel_to_img(h_index,v_index,colour);
            h_index++;
        }
        v_index++;
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
int	main()
{
    t_scene scene;
    t_cylinder cylinder = create_cylinder();
    scene.camera = create_camera();
    scene.cylinder = &cylinder;
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
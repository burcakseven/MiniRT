#include <scene/scene.h>
#include <ray/ray.h>
#include <utils/utils.h>
#include <render/render.h>

t_camera create_camera(){
    t_camera camera;

    camera.coordinate = (t_point3){0,-20.0,0.0};
    camera.v_orientation = vec3_normalize((t_point3){0.0, 1.0, 0.0});
    camera.up = (t_point3){0.0,0.0,1.0};
    camera.lenght = 1.0;
    camera.HorzSize = 0.25;
    camera.apRatio = 16/9;
    camera.fov = 10;
	camera.look_at = vec3_add(camera.coordinate, camera.v_orientation);
    return camera;
}

t_camera update_camera(t_camera camera)
{
    t_vec3 u_vector;
    t_vec3 v_vector;
    t_vec3 screen_center;

    u_vector = vec3_cross(camera.v_orientation,camera.up);
    v_vector = vec3_cross(u_vector, camera.v_orientation);

    camera.center = vec3_add(camera.coordinate,vec3_scale(camera.v_orientation,camera.lenght));

    u_vector = vec3_scale(u_vector, camera.HorzSize);
    v_vector = vec3_scale(v_vector,(camera.HorzSize/camera.apRatio));
	camera.u = u_vector;
	camera.v = v_vector;
    return camera;
}


void print_img(){
	t_canvas	canvas;
	t_mlx		mlx;
	
	canvas = get_canvas();
	mlx = get_mlx();
	mlx_put_image_to_window(mlx.mlx,mlx.win,canvas.img,0,0);
	mlx_loop(mlx.mlx);
}
#include <stdio.h>
int main(int ac, char **av){
	t_scene scene;
    //parse
	scene = create_scene(av[1]);
	printf("HELLO WORLD!!!\n");
	scene.camera = create_camera();
	//scene.camera = update_camera(scene.camera);
	render_scene(scene);
	print_img();
}
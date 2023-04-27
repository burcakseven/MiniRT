#include <scene/scene.h>
#include <ray/ray.h>
#include <utils/utils.h>
#include <render/render.h>
#include <parser/parser.h>
#include <gc/gc.h>

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

void print_img(){
	t_canvas	canvas;
	t_mlx		mlx;
	
	canvas = get_canvas();
	mlx = get_mlx();
	mlx_put_image_to_window(mlx.mlx,mlx.win,canvas.img,0,0);
	mlx_loop(mlx.mlx);
}

t_scene create_empty_scene(){
	t_scene scene;

	scene.cylinder = new(sizeof(t_container_cy));
	scene.plane = new(sizeof(t_container_pl));
	scene.sphere = new(sizeof(t_container_sp));
	return (scene);
}

int main(int ac, char **av){
	t_scene scene;
    //parse
	if (ac == 2)
	{
		scene = create_empty_scene();
		printf("HELLO WORLD!\n");
		scene = create_scene(av[1]);
		printf(
			"camera:\n"
			"\tcoordinate: (%Lf,%Lf,%Lf)\n"
			"\torientation: (%Lf,%Lf,%Lf)\n"
			"\tfov: %d\n",
			scene.camera.coordinate.x,scene.camera.coordinate.y,scene.camera.coordinate.z,
			scene.camera.v_orientation.x,scene.camera.v_orientation.y,scene.camera.v_orientation.z,
			scene.camera.fov
		);
		render_scene(scene);
		print_img();
		return (0);
	}
	printf("Invalid Arguments\n");
	return (1);
}
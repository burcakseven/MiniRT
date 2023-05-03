#include <scene/scene.h>
#include <ray/ray.h>
#include <utils/utils.h>
#include <render/render.h>
#include <parser/parser.h>
#include <gc/gc.h>
#include <libft.h>

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

void print_ambient(t_ambient_light light)
{
	printf(
		"\tambient:\n"
		"\t\tcolor: (%Lf,%Lf,%Lf)\n"
		"\t\trange: %f\n",
		light.color.x,light.color.y,light.color.z,
		light.range
	);
}
void print_light(t_light light)
{
	printf(
		"\tlight:\n"
		"\t\tcoordinate: (%Lf,%Lf,%Lf)\n"
		"\t\tcolor: (%Lf,%Lf,%Lf)\n"
		"\t\tbrightness: %Lf\n",
		light.coordinate.x,light.coordinate.y,light.coordinate.z,
		light.color.x,light.color.y,light.color.z,
		light.brightness
	);
}

void print_camera(t_camera camera)
{
	printf(
		"\tcamera:\n"
		"\t\tcoordinate: (%Lf,%Lf,%Lf)\n"
		"\t\torientation: (%Lf,%Lf,%Lf)\n"
		"\t\tfov: %d\n",
		camera.coordinate.x,camera.coordinate.y,camera.coordinate.z,
		camera.v_orientation.x,camera.v_orientation.y,camera.v_orientation.z,
		camera.fov
	);
}
void print_spheres(t_container_sp *container){
	printf("\tspheres:\n");
	while (container->next){
		t_sphere sphere = *(container->content);
		printf(
			"\t\t- sphere:\n"
			"\t\t\tcoordinate: (%Lf,%Lf,%Lf)\n"
			"\t\t\tdiameter: (%f)\n"
			"\t\t\tcolor: (%X)\n",
			sphere.coordinate.x,sphere.coordinate.y,sphere.coordinate.z,
			sphere.diameter,
			sphere.color
		);
		container = container->next;
	}
}
void print_cylinders(t_container_cy *container){
	printf("\tcylinder:\n");
	while (container->next){
		t_cylinder cylinder = *(container->content);
		printf(
			"\t\t- cylinder:\n"
			"\t\t\tcoordinate: (%Lf,%Lf,%Lf)\n"
			"\t\t\tv_axis: (%Lf,%Lf,%Lf)\n"
			"\t\t\tdiameter: (%f)\n"
			"\t\t\theight: (%f)\n"
			"\t\t\tcolor: (%X)\n",
			cylinder.coordinate.x,cylinder.coordinate.y,cylinder.coordinate.z,
			cylinder.v_axis.x,cylinder.v_axis.y,cylinder.v_axis.z,
			cylinder.diameter,
			cylinder.height,
			cylinder.color
		);
		container = container->next;
	}
}

void print_planes(t_container_pl *container){
	printf("\tplane:\n");
	while (container->next){
		t_plane plane = *(container->content);
		printf(
			"\t\t- plane:\n"
			"\t\t\tcoordinate: (%Lf,%Lf,%Lf)\n"
			"\t\t\tv_normal: (%Lf,%Lf,%Lf)\n"
			"\t\t\tcolor: (%X)\n",
			plane.coordinate.x,plane.coordinate.y,plane.coordinate.z,
			plane.v_normal.x,plane.v_normal.y,plane.v_normal.z,
			plane.color
		);
		container = container->next;
	}
}


void print_scene(t_scene scene) {
	printf("*******************\n");
	printf("scene:\n");
	print_ambient(scene.ambient);
	print_light(scene.light);
	print_camera(scene.camera);
	print_spheres(scene.sphere);
	print_cylinders(scene.cylinder);
	print_planes(scene.plane);
	printf("*******************\n");
}


int main(int ac, char **av){
	t_scene scene;
    //parse
	if (ac == 2)
	{
		scene = create_scene(av[1]);
		print_scene(scene);
		render_scene(scene);
		print_img();
		return (0);
	}
	ft_putendl_fd("Invalid arguments.",2);
	return (1);
}
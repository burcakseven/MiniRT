#include "scene.h"

void fill_data(t_scene *scene)
{
    scene->ambient.color = -1;
    scene->camera.fov = -1;
    scene->light.color = -1;
    scene->sphere = malloc(sizeof(t_sphere)*10);
    scene->plane = malloc(sizeof(t_plane)*10);
    scene->cylinder = malloc(sizeof(t_cylinder)*10);
}

void	fill_data_operations(char *arg, t_scene *scene)
{
    int fd;

    fd = control_file(arg);
    fill_data(scene);
	read_scene_data(scene,fd);
}

int	main(int ac, char **av)
{
	t_scene scene;
	if (ac != 2)
	{
		ft_error();
	}
	fill_data_operations(av[1], &scene);
}
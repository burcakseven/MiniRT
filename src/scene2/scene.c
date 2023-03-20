#include "scene.h"

void	fill_data_operations(char *arg, t_scene *scene)
{
    int fd;

    fd = control_file(arg);
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
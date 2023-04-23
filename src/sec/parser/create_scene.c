#include "parser.h"
#include <utils/utils.h>

t_scene	create_scene(char *file)
{
	t_scene	scene;
	int		fd;

	fd = try_open(file);
	if (fd >= 0)
	{
		read_scene_data(&scene,fd);
	}
	else
		ft_error("Invalid input file.");
	return scene;
}

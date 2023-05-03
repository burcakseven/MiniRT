#include "parser.h"
#include <utils/utils.h>

static t_scene create_empty_scene(){
	t_scene scene;

	scene.cylinder = new(sizeof(t_container_cy));
	scene.cylinder->next = NULL;
	scene.plane = new(sizeof(t_container_pl));
	scene.plane->next = NULL;
	scene.sphere = new(sizeof(t_container_sp));
	scene.sphere->next = NULL;
	return (scene);
}

t_scene	create_scene(char *file)
{
	t_scene	scene;
	int		fd;

	scene = create_empty_scene();
	fd = try_open(file);
	if (fd >= 0)
	{
		read_scene_data(&scene,fd);
	}
	else
		ft_error("Invalid input file.");
	return scene;
}

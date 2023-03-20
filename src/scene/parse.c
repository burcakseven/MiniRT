#include "scene.h"

void ambient_data(t_ambient *ambient, char *data)
{
	if(ambient->color)
		ft_error();
	ambient->range = ft_atof(&data);
	if(ambient->range < 0.0 || ambient->range > 1.0)
		ft_error();
	ambient->color = fill_rgb(&data);
}

void fill_coordinate(char **data, float xyz[][3], float min, float max)
{
	int i;

	i = 0;
	while (i < 3)
	{
		*data = remove_first_last_spaces(*data);
		if((*data) == NULL)
			ft_error();
		(*xyz)[i] = ft_atof(data);
		if((*xyz)[i] < min || (*xyz)[i] > max)
			ft_error();
		(*data)++;
		i++;
	}
}

void camera_data(t_camera *camera, char *data)
{
	if(camera->coordinate[0])
		ft_error();
	fill_coordinate(&data, &(camera->coordinate));
	fill_coordinate(&data,&(camera->v_orientation)); //?
	data = remove_first_last_spaces(data);
	if((data) == NULL) //diğer datalar freelenmeli?
			ft_error();
	camera->fov = ft_atof(&data);
}

void choose_element(char *element, t_scene *scene, char *data) // ilkinden sonra alfabetik harf içermeyecek kontrolü eklenecek
{
	//data harf içermeyecek kontrolü
	if(ft_compare("A",element))
		ambient_data(&(scene->ambient), data);
	else if (ft_compare("C",element))
		camera_data(&(scene->camera),data);
	// else if (ft_compare("L",element))
	// 	light_data(&(scene->light), data);
	// else if(ft_strncmp("sp",element,len))

	// else if(ft_strncmp("pl",element,len))

	// else if(ft_strncmp("cy",element,len))

	// else
	// 	fr_error();
}

char *pass_id(char *data)
{
	char	*id;
	int		i;

	i = 0;
	id = malloc(ft_strlen(data)+1);
	while (*data != '\0' && *data != ' ')
		id[i++] = *data++;
	id[i] = '\0';
	return id;
}

void process_line(t_scene *scene, char *data)
{
	char	*id;

	data = remove_first_last_spaces(data);
	if(!data)
		ft_error();
	id = pass_id(data);
	data += ft_strlen(id);
	choose_element(id, scene, data);
	free(id);
}

void read_scene_data(t_scene *scene, int fd)
{
    char *line = NULL;

    while (1)
	{
        line = get_next_line(fd);
        if (line == NULL)
            break;
        process_line(scene, line);
        free(line);
    }
}


// scene/scene.c scene/parse.c scene/utils.c
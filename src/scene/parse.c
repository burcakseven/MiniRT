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

void fill_coordinate(char **data, float xyz[][3])
{
	int i;

	i = 0;
	while (i < 3)
	{
		*data = remove_first_last_spaces(*data);
		if((*data) == NULL) //diğer datalar freelenmeli?
			ft_error();
		(*xyz)[i] = ft_atof(data);
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

// void light_data(t_light *light, char *data)
// {
// 	light
// }

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

void process_line(t_scene *scene, char *data)
{
	char	*element;
	int		i;

	i = 0;
	element = malloc(ft_strlen(data)+1);
	data = remove_first_last_spaces(data);
	if(!data)
		ft_error();
	while (*data != '\0' && *data != ' ')
		element[i++] = *data++;
	element[i] = '\0';
	data += i;
	choose_element(element, scene, data);
	free(element);
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

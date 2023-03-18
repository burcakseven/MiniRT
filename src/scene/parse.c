#include "scene.h"

int fill_rgb(char **data)
{
	int i;
	int j;
	char *color_string;
	int color;

	color = 0;
	i = 3;
	color_string = malloc(sizeof(char)*i+1);
	*(data) = remove_first_last_spaces(*data);
	while (i--)
	{
		j = 0;
		while (**data != '\0' && **data != ',' && **data != ' ')
		{
			color_string[j++] = **data;
			(*data)++;
		}
		(*data)++;
		color_string[j] = '\0';
		if(color_string[0] == '\0')
			ft_error();
		color += ft_atoi(color_string) << (8*i);
	}
	free(color_string);
	return color;
}

void ambient_lightning(t_ambient *ambient, char *data)
{
	if(ambient->color)
		ft_error();
	ambient->color = fill_rgb(&data);
}

void choose_element(char *element, t_scene *scene, char *data)
{
	if(ft_compare("A",element))
		ambient_lightning(&(scene->ambient), data);
	// else if (ft_strncmp("C",element,len))

	// else if (ft_strncmp("L",element,len))

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

#include "scene.h"

void choose_element(char *element, t_scene *scene, char *data)
{
	static int sl = 0;
	static int cy = 0;

	(void) sl, (void) cy;

	if(ft_compare("A",element))
		ambient_data(&(scene->ambient), data);
	else if (ft_compare("C",element))
		camera_data(&(scene->camera),data);
	else if (ft_compare("L",element))
		light_data(&(scene->light), data);
	else if(ft_compare("sp",element))
		sphere_data(&(scene->sphere), data);
	else if(ft_compare("pl",element))
		plane_data(&(scene->plane), data);
	else if(ft_compare("cy",element))
		cylinder_data(&(scene->cylinder), data);
	else
		ft_error();
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

void	validate_line_data(char *line)
{
	while (*line != '\0')
	{
		if((*line > '9' || *line < '0') && !(*line == '+' \
		|| *line == '-' || *line == '.' || *line == ' ' || *line == ','))
			ft_error();
		line++;
	}
}

void process_line(t_scene *scene, char *data)
{
	char	*id;
	(void) scene;
	data = remove_first_last_spaces(data);
	if(!data)
		ft_error();
	id = pass_id(data);
	data += ft_strlen(id);
    validate_line_data(data);
	data = remove_first_last_spaces(data);
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

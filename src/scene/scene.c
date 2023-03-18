#include "scene.h"

void	name_control(char *file_name)
{
	char	*cmp_addres;

	cmp_addres = ft_strnstr(file_name, ".rt", ft_strlen(file_name));
	if (cmp_addres != NULL)
	{
		if (*(cmp_addres + 3) == '\0')
			return ;
	}
	ft_error();
}

void	fill_data_operations(char *arg, t_scene *scene)
{
	int		fd;
	char	*file_name;

	file_name = remove_first_last_spaces(arg);
	if(!file_name)
		ft_error();
	name_control(file_name);
	fd = open(file_name, O_RDONLY);
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
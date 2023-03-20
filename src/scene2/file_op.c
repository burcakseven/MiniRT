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

int control_file(char *arg)
{
    int		fd;
	char	*file_name;

	file_name = remove_first_last_spaces(arg);
	if(!file_name)
		ft_error();
	name_control(file_name);
	fd = open(file_name, O_RDONLY);
	if(fd < 0)
		ft_error();
    return fd;
}

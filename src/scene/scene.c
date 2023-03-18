#include "scene.h"

char	*remove_first_last_spaces(char	*str)
{
	int	len;

	while (*str == ' ')
		str++;
	len = ft_strlen(str);
	while (len > 0 && str[len - 1] == ' ')
	{
		str[len - 1] = '\0';
		len--;
	}
	return (str);
}

void	name_control(char *file_name)
{
	char	*cmp_addres;

	cmp_addres = ft_strnstr(file_name, ".rt", ft_strlen(file_name));
	if (cmp_addres != NULL)
	{
		if (*(cmp_addres + 3) == '\0')
			return ;
	}
	printf("Error\n");
	exit(1);
}

void	fill_data_operations(char *arg)
{
	int		fd;
	char	*file_name;

	file_name = remove_first_last_spaces(arg);
	name_control(file_name);
	fd = open(file_name, O_RDONLY);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error\n");
		exit(1);
	}
	fill_data_operations(av[1]);
}
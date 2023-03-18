#include "scene.h"

void name_control(char *file_name)
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

int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error\n");
		exit(1);
	}
	name_control(av[1]);
}
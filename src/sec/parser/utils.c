#include "parser.h"
#include <libft.h>
#include <fcntl.h>

char	*remove_first_last_spaces(char	*str)
{
	int	len;
    if(!str || *str == '\0')
        return NULL;
	while (*str == ' ')
		str++;
	len = ft_strlen(str);
	while (len > 0 && str[len - 1] == ' ')
	{
		str[len - 1] = '\0';
		len--;
	}
    if(!str ||*str == '\0')
        return NULL;
	return (str);
}

int ft_compare(char *source1, char *source2)
{
    int len;
    int temp;
    len = ft_strlen(source1);
    temp = ft_strlen(source2);

    if(temp > len)
        len = temp;
    if(ft_strncmp(source1,source2,len) == 0)
        return (1);
    return (0);
}

int		try_open(char *file){
	char	*ext;

	ext = ".rt";
	if (ft_strncmp(ft_strrchr(file, '.'),ext,ft_strlen(ext)+1) != 0)
		return (-1);
	
	return (open(file,O_RDONLY));
}

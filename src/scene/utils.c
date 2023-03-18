#include "scene.h"

void ft_error()
{
	printf("Error\n");
	exit(1);
}

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

float ft_atof(char **str) //kontrol lazım .234 gibi bir sayı olursa? ya da 1.22.4 gibi bir sayı olursa?
{
    float result = 0.0;
    int sign = 1;
    int i = 0;
    while (**str == ' ')
		(*str)++;
    if (**str == '-')
	{
        sign = -1;
		(*str)++;
	}
    else if (**str == '+')
        (*str)++;
    while (ft_isdigit(**str) || **str == '.')
	{
		if(**str == '.' || i != 0)
		{
			i++;
			(*str)++;
		}
        result = result * 10.0 + (float)(**str - '0');
        (*str)++;
    }
    return sign * (result / (10 * i));
}
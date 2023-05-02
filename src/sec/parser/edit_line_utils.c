#include "parser.h"
#include <utils/utils.h>

void fill_coordinate(char **data, float xyz[][3], float min, float max)
{
	int i;

	i = 0;
	while (i < 3)
	{
		*data = remove_first_last_spaces(*data);
		if((*data) == NULL)
			ft_error("Invalid input for coordinate");
		(*xyz)[i] = ft_atof(data);
		if((*xyz)[i] < min || (*xyz)[i] > max)
			ft_error("Invalid input for coordinate");
		(*data)++;
		i++;
	}
}

float ft_atof(char **str) //kontrol lazım .234 gibi bir sayı olursa? ya da 1.22.4 gibi bir sayı olursa?
{
    float	result;
    float	sign;
    int		i;

    result = 0.0;
    sign = 1.0;
    i = 0;
    if (*((*str)++) == '-')
        sign = -1.0;
    else if (**str == '+')
        (*str)++;
    while (**str != '\0'&&(ft_isdigit(**str) || **str == '.'))
	{
		if(**str != '\0' && (**str == '.' || i != 0))
		{
			i++;
			if (**str == '.')
				(*str)++;
		}
        result = result * 10.0 + (float)(**str - '0');
        (*str)++;
    }
    return (sign * (result / (float)pow(10,i)));
}


int fill_rgb(char **data)
{
	int i;
	int j;
	char *color_string;
	int color;
    int temp_color;

	color = 0;
	i = 3;
	color_string = new(sizeof(char)*i+1);
	*(data) = remove_first_last_spaces(*data);
	while (i--)
	{
		j = 0;
		while (**data != '\0' && **data != ',' && **data != ' ')
			color_string[j++] = *(*data)++;
		(*data)++;
		color_string[j] = '\0';
        temp_color = ft_atoi(color_string);
        if(color_string[0] == '\0' || temp_color > 255 || temp_color < 0)
            ft_error("Invalid input near\n");
		color += temp_color << (8*i);
	}
	del(color_string);
	return color;
}

#include "scene.h"

void fill_coordinate(char **data, float xyz[][3], float min, float max)
{
	int i;

	i = 0;
	i = 0;
	while (i < 3)
	{
		*data = remove_first_last_spaces(*data);
		if (**data == '\0')
			ft_error("Expected 3 values (x,y,z) but line ended prematurely");
		
		(*xyz)[i] = ft_atof(data);
		
		if ((*xyz)[i] < min || (*xyz)[i] > max)
		{
			printf("Invalid value: [%f] ", (*xyz)[i]);
			ft_error("Value out of range for this parameter");
		}
		
		*data = remove_first_last_spaces(*data);
		if (i < 2) // Check for comma between x-y and y-z
		{
			if (**data != ',')
				ft_error("Missing comma separator between values. Example: 1.0,2.0,3.0");
			(*data)++; // Skip the comma
		}
		i++;
	}
}

float ft_atof(char **str) //kontrol lazım .234 gibi bir sayı olursa? ya da 1.22.4 gibi bir sayı olursa?
{
    float result;
    float sign;
    int i;

    result = 0.0;
    sign = 1.0;
    i = 0;
    if (**str == '-')
	{
        sign = -1.0;
		(*str)++;
	}
    else if (**str == '+')
        (*str)++;
    while (**str != '\0'&&(ft_isdigit(**str) || **str == '.'))
	{
		if(**str != '\0' && (**str == '.' || i != 0))
		{
			i++;
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
            ft_error("RGB color value must be [0, 255]. Expected format: R,G,B");
		color += temp_color << (8*i);
	}
	del(color_string);
	return color;
}

#include "scene.h"



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
			(*data)++; //if color_s[j-1] == '.' ret error eklenmesi gerekiyo
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

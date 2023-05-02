#include <scene/scene.h>
#include "parser.h"
#include <utils/utils.h>

static t_color	convert_color(int colour)
{
	t_color	color;

	color.x = (long double) (colour >> 16);
	color.y = (long double) ((colour >> 8) & 0x00FF);
	color.z = (long double) (colour & 0x0000FF);
	return (color);
}

void ambient_data(t_ambient_light *ambient, char *line)
{
	ambient->range = ft_atof(&line);
	if(*line == '\0' || ambient->range > 1 || ambient->range < 0)
		ft_error("Invalid range value");
	ambient->color = convert_color(fill_rgb(&line));
	if(*line != '\0' && *line != '\n')
		ft_error("Unexpected end for ambient.");
}

void camera_data(t_camera *camera, char *line)
{
	float	coordinate[3];
	float	v_orientation[3];

	fill_coordinate(&line, &coordinate, MIN, MAX);
	fill_coordinate(&line, &v_orientation, -1, 1);
	camera->coordinate = convert_point3(coordinate);
	camera->v_orientation = convert_point3(v_orientation);
	camera->fov = (int)ft_atof(&line);
	printf("camera fov: %d\n", camera->fov);
	camera->up = (t_vec3) {0,0,1};
	if(camera->fov < 0 || camera->fov > 180)
		ft_error("Invalid fov value for camera");
	if(*line != '\0' && *line != '\n')
		ft_error("Unexpected end on camera.");
}


void light_data(t_light *light, char *line)
{
	float	coordinate[3];

	fill_coordinate(&line, &coordinate, MIN, MAX);
	light->brightness = ft_atof(&line);
	light->coordinate = convert_point3(coordinate);
	if(light->brightness < 0 || light->brightness > 1)
		ft_error("Invalid brightness for light");
	light->color = convert_color(fill_rgb(&line));

	if(*line != '\0' && *line != '\n')
		ft_error("Unexpected end. for light");
}
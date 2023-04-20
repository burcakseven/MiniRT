#include "scene.h"
#include "utils/utils.h"

void ambient_data(t_ambient *ambient, char *line)
{
	if(ambient->color)
		ft_error();
  ambient->range = ft_atof(&line);
  if(*line == '\0' || ambient->range > 1 || ambient->range < 0)
    ft_error();
  ambient->color = fill_rgb(&line);
  if(*line != '\0' && *line != '\n')
    ft_error();
}

void camera_data(t_camera *camera, char *line)
{
    float coordinate[3];
    float v_orientation[3];

    if(camera->fov)
    ft_error();
    fill_coordinate(&line, &coordinate, MIN, MAX);
    fill_coordinate(&line, &v_orientation, -1, 1);
    camera->fov = (int)ft_atof(&line);
    camera->coordinate = convert_point3(coordinate);
    camera->v_orientation = convert_point3(v_orientation);
    if(camera->fov < 0 || camera->fov > 180)
        ft_error();
    if(*line != '\0' && *line != '\n')
        ft_error();
}


void light_data(t_light *light, char *line)
{
  fill_coordinate(&line, &light->coordinate, MIN, MAX);
  light->brightness = ft_atof(&line);
  if(light->brightness < 0 || light->brightness > 1)
    ft_error();
  fill_rgb(&line);

  if(*line != '\0' && *line != '\n')
    ft_error();
}
#include "scene.h"

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
  if(camera->fov)
    ft_error();
  fill_coordinate(&line, &camera->coordinate, MIN, MAX);
  fill_coordinate(&line, &camera->v_orientation, -1, 1);
  camera->fov = (int)ft_atof(&line);
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
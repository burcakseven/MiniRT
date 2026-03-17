#include "scene.h"

void ambient_data(t_ambient *ambient, char *line) {
  if (ambient->color)
    ft_error("Ambient light already defined. Only one 'A' allowed");
  ambient->range = ft_atof(&line);
  if (*line == '\0' || ambient->range > 1 || ambient->range < 0)
    ft_error("Ambient range must be [0, 1]. Expected format: A 0.2 255,255,255");
  ambient->color = fill_rgb(&line);
  if (*line != '\0' && *line != '\n')
    ft_error("Extra characters after ambient light data");
}

void camera_data(t_camera *camera, char *line) {
  if (camera->fov)
    ft_error("Camera already defined. Only one 'C' allowed");
  fill_coordinate(&line, &camera->coordinate, MIN, MAX);
  fill_coordinate(&line, &camera->v_orientation, -1, 1);
  camera->fov = (int)ft_atof(&line);
  if (camera->fov < 0 || camera->fov > 180)
    ft_error("Camera FOV must be [0, 180]. Expected format: C 0,0,0 0,0,1 70");
  if (*line != '\0' && *line != '\n')
    ft_error("Extra characters after camera data");
}

void light_data(t_light *light, char *line) {
  fill_coordinate(&line, &light->coordinate, MIN, MAX);
  light->brightness = ft_atof(&line);
  if (light->brightness < 0 || light->brightness > 1)
    ft_error("Light brightness must be [0, 1]. Expected format: L 0,0,0 0.6 255,255,255");
  light->color = fill_rgb(&line);

  while (*line == ' ')
    line++;
  if (*line != '\0' && *line != '\n')
    ft_error("Extra characters after light data");
}
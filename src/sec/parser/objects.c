#include "parser.h"
#include <utils/utils.h>
#include <stdio.h>

void sphere_data(t_container_sp **sphere, char *line)
{
	float			coordinate[3];
	t_container_sp	*next;
	t_sphere		*temp_sp;

    temp_sp = new(sizeof(t_sphere));
	next = new(sizeof(t_container_sp));
    fill_coordinate(&line ,&coordinate, MIN,MAX);
	temp_sp->coordinate = convert_point3(coordinate);
    temp_sp->diameter = ft_atof(&line);
    line = remove_first_last_spaces(line);
    temp_sp->color = fill_rgb(&line);
	next->content = temp_sp;
    next->next = *sphere;
    (*sphere)->prev = next;
	*sphere = next;
}


void plane_data(t_container_pl **plane, char *line)
{
    t_container_pl	*next;
	t_plane			*temp_pl;
    float			coordinate[3];
    float			v_normal[3];

 	next = new(sizeof(t_container_pl));
	temp_pl = new(sizeof(t_plane));
    fill_coordinate(&line, &coordinate, MIN, MAX);
    temp_pl->coordinate = convert_point3(coordinate);
    fill_coordinate(&line, &v_normal,-1,1);
    temp_pl->v_normal = convert_point3(v_normal);
    temp_pl->color = fill_rgb(&line);
    next->content = temp_pl;
	next->next = *plane;
	(*plane)->prev = *plane;
	*plane = next;
}

void cylinder_data(t_container_cy **cylinder, char *line)
{
	t_container_cy	*next;
	t_cylinder		*temp_cy;
    float coordinate[3];
    float v_axis[3];

	next = new(sizeof(t_container_cy));
    temp_cy = new(sizeof(t_cylinder));
    fill_coordinate(&line, &coordinate, MIN, MAX);
    temp_cy->coordinate = convert_point3(coordinate);
    fill_coordinate(&line, &v_axis, -1, 1);
    temp_cy->v_axis = convert_point3(v_axis);
    line = remove_first_last_spaces(line);
    temp_cy->diameter = ft_atof(&line);
    line = remove_first_last_spaces(line);
    temp_cy->height = ft_atof(&line);
    temp_cy->color = fill_rgb(&line);
    next->content = temp_cy;
	next->next = *cylinder;
	(*cylinder)->prev = next;
	*cylinder = next;
}
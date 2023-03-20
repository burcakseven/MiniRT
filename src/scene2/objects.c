#include "scene.h"

void sphere_data(t_sphere **sphere, char *line)
{
    static int sp = 0;

    t_sphere *temp_sp = sphere[sp];
    fill_coordinate(&line ,&(temp_sp->coordinate), MIN,MAX);
    temp_sp->diameter = ft_atof(*line);
    line = remove_first_last_spaces(line);
    temp_sp->color = fill_rgb(*line);
    sp++;
}

void plane_data(t_plane **plane, char *line)
{
    static int pl = 0;

    t_plane *temp_pl = plane[pl];
    fill_coordinate(&line, &(temp_pl->coordinate), MIN, MAX);
    fill_coordinate(&line, &(temp_pl->v_normal),-1,1);
    temp_pl->color = fill_rgb(&line);
    pl++;
}

void cylinder_data(t_cylinder **cylinder, char *line)
{
    static int cy = 0;

    t_cylinder *temp_cy = cylinder[cy];
    fill_coordinate(&line, &(temp_cy->coordinate), MIN, MAX);
    fill_coordinate(&line, &(temp_cy->v_axis), -1, 1);
    line = remove_first_last_spaces(line);
    temp_cy->diameter = ft_atof(&line);
    line = remove_first_last_spaces(line);
    temp_cy->height = ft_atof(&line);
    temp_cy->color = fill_rgb(&line);
    cy++;
}
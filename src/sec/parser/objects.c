#include "parser.h"

void sphere_data(t_sphere **sphere, char *line)
{
    static int sp = 0;

    t_sphere *temp_sp = sphere[sp];
    fill_coordinate(&line ,&(temp_sp->coordinate), MIN,MAX);
    temp_sp->diameter = ft_atof(&line);
    line = remove_first_last_spaces(line);
    temp_sp->color = fill_rgb(&line);
    sp++;
}


void plane_data(t_plane **plane, char *line)
{
    static int pl = 0;
    float coordinate[3];
    float v_normal[3];

    t_plane *temp_pl = plane[pl];
    fill_coordinate(&line, &coordinate, MIN, MAX);
    //temp_pl->coordinate = convert_point3(coordinate);
    fill_coordinate(&line, &v_normal,-1,1);
    //temp_pl->v_normal = convert_point3(v_normal);
    temp_pl->color = fill_rgb(&line);
    pl++;
}

void cylinder_data(t_cylinder **cylinder, char *line)
{
    static int cy = 0;
    float coordinate[3];
    float v_axis[3];

    t_cylinder *temp_cy = cylinder[cy];
    fill_coordinate(&line, &coordinate, MIN, MAX);
    temp_cy->coordinate = convert_point3(coordinate);
    fill_coordinate(&line, &v_axis, -1, 1);
    temp_cy->v_axis = convert_point3(v_axis);
    line = remove_first_last_spaces(line);
    temp_cy->diameter = ft_atof(&line);
    line = remove_first_last_spaces(line);
    temp_cy->height = ft_atof(&line);
    temp_cy->color = fill_rgb(&line);
    cy++;
}
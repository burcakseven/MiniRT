# ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <fcntl.h>
# include <get_next_line/get_next_line.h>
# include <libft.h>
# include <math.h>
# include <gc/gc.h>
# include <scene/scene.h>
# include <matrix/matrix.h>

# define MIN -2147483648
# define MAX 2147483647


char	*remove_first_last_spaces(char	*str);
void ft_error();
void read_scene_data(t_scene *scene, int fd);

t_scene create_scene(char *file);

//utils
int ft_compare(char *source1, char *source2);
float ft_atof(char **str);
int fill_rgb(char **data);

//file_op
int check_file(char *arg);

//edit_line_utils.c
int fill_rgb(char **data);
void fill_coordinate(char **data, float xyz[][3], float min, float max);

//data_placement
void ambient_data(t_ambient_light *ambient, char *line);
void camera_data(t_camera *camera, char *line);
void light_data(t_light *light, char *line);

//objects.c
void sphere_data(t_container_sp **sphere, char *line);
void plane_data(t_plane **plane, char *line);
void cylinder_data(t_cylinder **cylinder, char *line);

#endif
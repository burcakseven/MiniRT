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
void	read_scene_data(t_scene *scene, int fd);
t_scene	create_scene(char *file);

/**
 * @brief Try to open given file
 * @param arg: File address to attempt
 * @return If given file is valid file, fd is returned. Else, -1
*/
int		try_open(char *arg);
void	fill_coordinate(char **data, float xyz[][3], float min, float max);
void	ambient_data(t_ambient_light *ambient, char *line);
void	camera_data(t_camera *camera, char *line);
void	light_data(t_light *light, char *line);
void	sphere_data(t_container_sp **sphere, char *line);
void	plane_data(t_container_pl **plane, char *line);
void	cylinder_data(t_container_cy **cylinder, char *line);

#endif
# ifndef SCENE_H
# define SCENE_H

# include <stdio.h>
# include <fcntl.h>
# include <get_next_line/get_next_line.h>
# include <libft.h>
# include <math.h>
# include <gc/gc.h>
# include <assert.h>
#include <matrix/matrix.h>

# define MIN -2147483648
# define MAX 2147483647

typedef struct	s_ambient
{

	float	range; //value between [0 - 1]
	int		color; //0xAABBCC
}	t_ambient;

typedef struct s_camera {
	point3 	coordinate;
	t_vec3 	v_orientation; // between [0-1]
	int		fov; // between [0-180]
    float   viewport_height;
    float   viewport_width;
}	t_camera;

typedef struct s_light {
	point3 	coordinate;
	float	brightness; //value between [0 - 1]
	int		color; //0xAABBCC
}	t_light;

typedef struct	s_sphere
{
	point3 	coordinate;
	float	diameter;
	int		color;
}	t_sphere;

typedef struct	s_plane
{
	point3 	coordinate;
	t_vec3 	v_normal; // Yüzeye dik olan açı vektör (birim vektör)
	int		color;
}	t_plane;

typedef struct	s_cylinder
{
	point3 	coordinate;
	t_vec3 	v_axis; // Yüzeye dik olan açı vektör (birim vektör)
	float	height;
	float	diameter;
	int		color;
} t_cylinder;

typedef struct s_scene {
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	/*

		BURAYA BİR ŞEY LAZIM
		(Küre, çember ve silindir)
		void *object; // böyle bir şey olabilir
	
	*/
}	t_scene;

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
void ambient_data(t_ambient *ambient, char *line);
void camera_data(t_camera *camera, char *line);
void light_data(t_light *light, char *line);

//objects.c
void sphere_data(t_sphere **sphere, char *line);
void plane_data(t_plane **plane, char *line);
void cylinder_data(t_cylinder **cylinder, char *line);

#endif
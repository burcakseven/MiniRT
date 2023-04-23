#ifndef SCENE_H
#define SCENE_H

#include <vec3/vec3.h>

typedef struct	s_ambient_light
{

	float	range; //value between [0 - 1]
	t_color		color; //0xAABBCC
}	t_ambient_light;

typedef struct s_camera {
	t_point3 	coordinate;
	t_vec3 		v_orientation; // between [0-1]
	t_vec3		up; // V_left x V_orientation
	t_vec3		left; // Y x V_orientation
	t_vec3		center;
	t_vec3		u;//*
	t_vec3		v;//*
	t_vec3		look_at;
    double		lenght; //*
	double		HorzSize; //*
	double		apRatio; //*
	int			fov; // between [0-180]
    float   	viewport_height;
    float		viewport_width;
}	t_camera;

typedef struct	s_light {
	t_point3 	coordinate;
	long double	brightness; //value between [0 - 1]
	t_color	color; //0xAABBCC
}				t_light;

typedef struct	s_sphere
{
	t_point3 	coordinate;
	float	diameter;
	int		color;
}	t_sphere;

typedef struct	s_plane
{
	t_point3 	coordinate;
	t_vec3 	v_normal; // Yüzeye dik olan açı vektör (birim vektör)
	int		color;
}	t_plane;

typedef struct	s_cylinder
{
	t_point3 	coordinate;
	t_vec3 	v_axis; // Yüzeye dik olan açı vektör (birim vektör)
	float	height;
	float	diameter;
	int		color;
} t_cylinder;

typedef struct s_container_sp {
	t_sphere *content;
	struct s_container_sp *next;
	struct s_container_sp *prev;
} t_container_sp;


typedef struct s_container_cy {
	t_cylinder *content;
	struct s_container_cy *next;
	struct s_container_cy *prev;
} t_container_cy;


typedef struct s_container_pl {
	t_plane *content;
	struct s_container_pl *next;
	struct s_container_pl *prev;
} t_container_pl;

typedef struct s_scene {
	t_ambient_light	ambient;
	t_camera	camera;
	t_light		light;
	t_container_sp	*sphere;
	t_container_pl	*plane;
	t_container_cy	*cylinder;
	/*

		BURAYA BİR ŞEY LAZIM
		(Küre, çember ve silindir)
		void *object; // böyle bir şey olabilir
	
	*/
}	t_scene;

#endif
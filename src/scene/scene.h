#ifndef SCENE_H
#define SCENE_H

typedef struct	s_ambient {
	float	range; //value between [0 - 1]
	int		color; //0xAABBCC
}	t_ambient;

typedef struct s_camera {
	float 	coordinate[3];
	float	v_orientation[3]; // between [0-1]
	int		fov; // between [0-180]
}	t_camera;

typedef struct s_light {
	float 	coordinate[3]; 
	float	brightness; //value between [0 - 1]
	int		color; //0xAABBCC
}	t_light;


typedef struct	s_sphere {
	float 	coordinate[3];
	float	diameter;
	int		color;
}	t_sphere;

typedef struct	s_plane {
	float 	coordinate[3];
	float 	v_normal[3]; // Yüzeye dik olan açı vektör (birim vektör)
	int		color;
}	t_plane;

typedef struct	s_cylinder {
	float 	coordinate[3];
	float 	v_axis[3]; // Yüzeye dik olan açı vektör (birim vektör)
	float	height;
	float	diameter;
	int		color;
} t_cylinder;

typedef struct s_scene {
	t_ambient	ambient;
	t_camera	camera;
	t_light		s_light;
	
	/*

		BURAYA BİR ŞEY LAZIM
		(Küre, çember ve silindir)
		void *object; // böyle bir şey olabilir
	
	*/
}	t_scene;

#endif
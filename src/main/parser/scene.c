#include <parser/scene.h>

void fill_data(t_scene *scene)
{
    scene->ambient.color = (t_color){-1,-1,-1};
    scene->camera.fov = -1;
    scene->light.color = (t_color){-1,-1,-1};
    scene->sphere = new(sizeof(t_sphere)*10); // realloc kullanılabilir ya da linkedlist oluşturulabilir
    scene->plane = new(sizeof(t_plane)*10);
    scene->cylinder = new(sizeof(t_cylinder)*10);
}

void	fill_data_operations(char *arg, t_scene *scene)
{
    int fd;

    fd = check_file(arg);
    fill_data(scene);
	read_scene_data(scene,fd);
}

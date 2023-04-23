#include <fcntl.h>
#include <parser/scene.h>
#include <stdio.h>

t_scene create_scene(char *file){
    int fd;
    t_scene scene;

    fd = open(file, O_RDONLY);
    if (fd < 0){
        printf("file input error\n");
        ft_error();
    }
    read_scene_data(&scene, fd);
    return scene;
}
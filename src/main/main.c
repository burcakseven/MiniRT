#include <unistd.h>
#include <frame/frame.h>
#include <stdio.h>
#include <mlx.h>
#include <scene.h>

/*
void print_frame(){

    void *mlx;
    void *win;

    mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "");

    //t_frame_1920x1080 frame;

    //frame = get_frame_1920x1080();


    for(int i = 0; i < 1080; i++){
        for (int j = 0; j < 1920; j++){
            //mlx_pixel_put(mlx, win, i,j,frame.canvas[i][j]);
        }
    }

    mlx_loop(mlx);
}

int main(int ac, char **av) {

    (void) ac;
    (void) av;

	printf("burada miii?\n");
    
    t_frame_1920x1080 frame;

    frame = get_frame_1920x1080();
    
    for(int i = 0; i < 1080; i++){
        for (int j = 0; j < 1920; j++){
            frame_set_pixel(i, j, 255);
        }
    }
    printf("DERT TASA\n");
    print_frame();
    return (0);
}*/

#ifndef TEST
int	main()
{
	int fd = open("deneme.txt",O_RDONLY);
	int	bln;
	bln = 1;
	char *str;
    printf("maine girdi");
	while (bln)
	{
		str = get_next_line(fd);
		if (str)
		{
			printf("%s",str);
		}
		else
			bln = 0;
	}
}
#else
int main()
{
    
}
#endif
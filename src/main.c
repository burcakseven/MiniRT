#include <unistd.h>
#include <frame/frame.h>
#include <stdio.h>
#include <mlx.h>

void print_frame(){

    t_frame_1920x1080 frame;

    frame = get_frame_1920x1080();

    for(int i = 0; i < 1080; i++){
        for (int j = 0; j < 1920; j++){
            mlx_pixel_put(frame.mlx, frame.win, i,j,frame.canvas[i][j]);
        }
    }
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
    (void) frame;
    print_frame();
    mlx_loop(frame.mlx);
    return (0);
}
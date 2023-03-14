#include <unistd.h>
#include <mlx.h>
#include <frame/frame.h>
#include <stdio.h>

int main(int ac, char **av) {

    (void) ac;
    (void) av;

	printf("burada miii?\n");
    t_frame_1920x1080 frame;

    frame = get_frame_1920x1080();

    for(int i = 0; i < 1080; i++){
        for (int j = 0; j < 1920; j++){
            printf("setting pixel at [%d, %d]", i, j);
            frame_set_pixel(i, j, 255);
        }
    }
    printf("DERT TASA\n");

    mlx_put_image_to_window(frame.mlx, frame.win, frame.canvas, 0, 0);
    mlx_loop(frame.mlx);
    return (0);
}
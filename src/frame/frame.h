#ifndef FRAME_H
# define FRAME_H

struct s_frame_1920x1080 {
    int canvas[1080][1920];
    void *mlx;
    void *win;
};

typedef struct s_frame_1920x1080 t_frame_1920x1080;

t_frame_1920x1080 get_frame_1920x1080();

void frame_set_pixel(unsigned int row, unsigned int col, int val);

#endif
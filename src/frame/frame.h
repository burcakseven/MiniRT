#ifndef FRAME_H
# define FRAME_H

# define WIDTH		1920
# define HEIGHT		1080

struct s_frame {
    void *img;
};

typedef struct s_frame_1920x1080 t_frame_1920x1080;

t_frame_1920x1080 get_frame_1920x1080();

void frame_set_pixel(unsigned int row, unsigned int col, int val);

#endif
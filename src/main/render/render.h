//
// Created by emakas on 10.04.2023.
//

#ifndef RENDER_H
#define RENDER_H
#include <vec3/r_vec3.h>
#include <stdlib.h>
#include <mlx.h>

typedef struct s_canvas {
    void    *img;
    void    *addr;
    int     bits_ppx;
    int     line_length;
    int     endian;
} t_canvas;

t_canvas get_canvas();
int put_pixel_to_img(int x, int y, color colour);
void print_img();


#endif //MINIRT_RENDER_H

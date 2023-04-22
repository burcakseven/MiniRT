//
// Created by emakas on 10.04.2023.
//
#include "render.h"
#include "frame/frame.h"


int put_pixel_to_img(int x, int y,t_color colour) {
    t_canvas    canvas;
    int         offset;
    char        *dest;

    canvas = get_canvas();
    offset = (y * canvas.line_length) + (x * (canvas.bits_ppx / 8));
    dest = canvas.addr + offset;
    *(unsigned int *)dest = rgb_color(colour);
    //*(unsigned int *)dest = 0xFF0000;
    return (1);
}
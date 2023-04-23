//
// Created by emakas on 10.04.2023.
//
#include "render.h"

static unsigned int rgb_color(t_color colour)
{
    // int ir;
	// int ig;
	// int ib;

	// ir = (int)(255.999 * colour.x);
    // ig = (int)(255.999 * colour.y);
    // ib = (int)(255.999 * colour.z);
	return((int)colour.x << 16 | (int)colour.y << 8 | (int)colour.z);
}


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
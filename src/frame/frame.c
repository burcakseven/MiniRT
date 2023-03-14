#include "frame.h"
#include <unistd.h>
#include <mlx.h>

static t_frame_1920x1080	*frame_1920x1080(void)
{
	static t_frame_1920x1080	frame;
	if (frame.mlx == NULL)
	{
		frame.mlx = mlx_init();
		frame.win = mlx_new_window(frame.mlx, 1920, 1080, "");
	}

	return &frame;
}



t_frame_1920x1080 get_frame_1920x1080()
{
	return (*(frame_1920x1080()));
}

void frame_set_pixel(unsigned int row, unsigned int col, int val)
{
	t_frame_1920x1080 *frame = frame_1920x1080();

	frame->canvas[row][col] = val;
}

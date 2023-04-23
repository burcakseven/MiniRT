#include "render.h"

t_mlx get_mlx() {
    static void *mlx = NULL;
    static void *win = NULL;
    t_mlx retval;

    if (mlx == NULL)
        mlx = mlx_init();
    if (win == NULL)
        win = mlx_new_window(mlx, WIDTH, HEIGHT, WINDOW_TITLE);
    retval.mlx = mlx;
    retval.win = win;
    return retval;
}
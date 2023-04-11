#include <unistd.h>
#include <frame/frame.h>
#include <stdio.h>
#include <mlx.h>
#include <parser/scene.h>
#include <render/render.h>

#define WIDTH 1920
#define HEIGHT 1080
#define ASPECT_RATIO WIDTH / HEIGHT
#define WINDOW_TITLE "minirt"

void print_image(){

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

typedef struct s_mlx {
    void *mlx;
    void *win
} t_mlx;

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

void *get_img(){
    void *img = NULL;
    t_mlx mlx;

    mlx = get_mlx();
    if (img == NULL)
        img = mlx_new_image(mlx.mlx,WIDTH, HEIGHT);
    return img;
}


t_canvas get_canvas(){
    static t_canvas *canvas = NULL;
    t_mlx mlx;

    mlx = get_mlx();
    if (canvas == NULL) {
        canvas = malloc(sizeof *canvas);
        canvas->img = mlx_new_image(mlx.mlx,WIDTH,HEIGHT);
        canvas->addr = mlx_get_data_addr(canvas->img, &(canvas->bits_ppx),\
        &(canvas->line_length),&(canvas->endian));
    }
    return (*canvas);
}

t_camera create_camera(){
    t_camera camera;

    camera.coordinate[0] = 0.0f;
    camera.coordinate[1] = 0.0f;
    camera.coordinate[2] = 0.0f;
    camera.v_orientation[0] = 1.0f;
    camera.v_orientation[1] = 1.0f;
    camera.v_orientation[2] = 1.0f;

    camera.fov = 75;
    return camera;
}

t_cylinder create_cylinder(){

    t_cylinder cylinder;
    cylinder.color = 0xFF0000;
    cylinder.coordinate[0] = 1.0f;
    cylinder.coordinate[1] = 1.0f;
    cylinder.coordinate[2] = 1.0f;
    cylinder.v_axis[0] = 0.0f;
    cylinder.v_axis[1] = 1.0f;
    cylinder.v_axis[2] = 0.0f;
    cylinder.diameter = 0.5f;
    cylinder.height = 1.0f;
    return cylinder;
}

/**
 * For sphere
 * @return
 */
color find_intercept(t_ray ray, t_sphere sphere){

}

t_ray create_ray(){
    // calculate from camera point to canvas pixel
}

void render_scene(t_scene scene){
    t_canvas    canvas;
    color       colour;
    canvas = get_canvas();

    for (int i = 0; i < WIDTH; i++){
        for (int j = 0; j < HEIGHT; j++){
            t_ray ray = create_ray();
            colour = find_intercept(ray,*scene.sphere); // Temprorary Solution
            // mask colour with light
            put_pixel_to_img(i,j,(color){256,0,0});
        }
    }
}

void show_img(){
    t_mlx mlx;
    t_canvas canvas;

    mlx = get_mlx();
    canvas = get_canvas();
    mlx_put_image_to_window(mlx.mlx,mlx.win,canvas.img,0,0);
    mlx_loop(mlx.mlx);
}

#ifndef TEST
int	main()
{
    t_scene scene;
    t_cylinder cylinder = create_cylinder();
    scene.camera = create_camera();
    scene.cylinder = &cylinder;

    render_scene(scene);
    show_img();
    return 0;
}
#endif

#ifdef TEST
int main(){

}
#endif

/**
 * Test Codes
 */
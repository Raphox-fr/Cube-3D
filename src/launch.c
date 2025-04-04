#include "cube.h"

int ft_launch(t_ray *ray)
{
    ft_init(&ray);
    ray->mlx = mlx_init();
    if (!ray->mlx)
        return (0);
    mlx_get_screen_size(ray->mlx, &ray->width, &ray->height);
    ft_xpm_to_img(ray);
    ray->win = mlx_new_window(ray->mlx, ray->width, ray->height, "Cub3D");
    if (!ray->win)
    {
        //incomplete desrtoy texture a faire ?!
        printf("Error\nmlx_new_window\n");
        mlx_destroy_display(ray->mlx);
        free(ray->mlx);
        free(ray);
        return (0);
    }
    mlx_hook(ray->win, 2, 1L << 0, ft_key_press, ray);
    mlx_hook(ray->win, 3, 1L << 1, ft_key_release, ray);
    mlx_hook(ray->win, 17, 1L << 17, close_window, ray);
    mlx_loop_hook(ray->mlx, ft_loop, ray);
    mlx_loop(ray->mlx);
    return (1);
}

void ft_key_press(int keycode, t_ray *ray)
{
    if (keycode == KEY_ESC)
        close_window(ray);
    if (keycode == KEY_W)
        ray->key[keycode] = 1;
    if (keycode == KEY_A)
        ray->key[keycode] = 1;
    if (keycode == KEY_S)
        ray->key[keycode] = 1;
    if (keycode == KEY_D)
        ray->key[keycode] = 1;
    if (keycode == KEY_LEFT)
        ray->key[keycode] = 1;
    if (keycode == KEY_RIGHT)
        ray->key[keycode] = 1;
}


int close_window(t_ray *ray)
{
    mlx_destroy_window(ray->mlx, ray->win);
    exit(0);
    return (0);
}



int ft_loop(t_ray *ray)
{
    ft_move(ray);
    //rajouter memset pour clear l'image a chaque loop
    ft_raycast(ray);
    ft_draw(ray); //rajouter mlx_put_image_to_window
    return (0);
}


int ft_draw(t_ray *ray)
{

}

void    ft_move(t_ray *ray)
{
    if (ray->key[KEY_W])
    {
        if (!ray->map[(int)(ray->posX + ray->dirX * ray->moveSpeed)][(int)ray->posY])
            ray->posX += ray->dirX * ray->moveSpeed;
        if (!ray->map[(int)ray->posX][(int)(ray->posY + ray->dirY * ray->moveSpeed)])
            ray->posY += ray->dirY * ray->moveSpeed;
    }
    if (ray->key[KEY_S])
    {
        if (!ray->map[(int)(ray->posX - ray->dirX * ray->moveSpeed)][(int)ray->posY])
            ray->posX -= ray->dirX * ray->moveSpeed;
        if (!ray->map[(int)ray->posX][(int)(ray->posY - ray->dirY * ray->moveSpeed)])
            ray->posY -= ray->dirY * ray->moveSpeed;
    }
    if (ray->key[KEY_A])
    {
        if (!ray->map[(int)(ray->posX - ray->dirY * ray->moveSpeed)][(int)ray->posY])
            ray->posX -= ray->dirY * ray->moveSpeed;
        if (!ray->map[(int)ray->posX][(int)(ray->posY + ray->dirX * ray->moveSpeed)])
            ray->posY += ray->dirX * ray->moveSpeed;
    }
    if (ray->key[KEY_D])
    {
        if (!ray->map[(int)(ray->posX + ray->dirY * ray->moveSpeed)][(int)ray->posY])
            ray->posX += ray->dirY * ray->moveSpeed;
        if (!ray->map[(int)ray->posX][(int)(ray->posY - ray->dirX * ray->moveSpeed)])
            ray->posY -= ray->dirX * ray->moveSpeed;
    }
    if (ray->key[KEY_LEFT]) 
    {
        oldDirX = ray->dirX;
        ray->dirX = ray->dirX * cos(ray->rotSpeed) - ray->dirY * sin(ray->rotSpeed);
        ray->dirY = oldDirX * sin(ray->rotSpeed) + ray->dirY * cos(ray->rotSpeed);
        oldPlaneX = ray->planeX;
        ray->planeX = ray->planeX * cos(ray->rotSpeed) - ray->planeY * sin(ray->rotSpeed);
        ray->planeY = oldPlaneX * sin(ray->rotSpeed) + ray->planeY * cos(ray->rotSpeed);
    }
    if (ray->key[KEY_RIGHT]) 
    {
        oldDirX = ray->dirX;
        ray->dirX = ray->dirX * cos(-ray->rotSpeed) - ray->dirY * sin(-ray->rotSpeed);
        ray->dirY = oldDirX * sin(-ray->rotSpeed) + ray->dirY * cos(-ray->rotSpeed);
        oldPlaneX = ray->planeX;
        ray->planeX = ray->planeX * cos(-ray->rotSpeed) - ray->planeY * sin(-ray->rotSpeed);
        ray->planeY = oldPlaneX * sin(-ray->rotSpeed) + ray->planeY * cos(-ray->rotSpeed);
    }    
}

/*
fonction loop : raycast, draw, move + memset + mlx_put_image_to_window

define global KEY + speed 

FONCTIONS   mouvement key press
            rotation key press

fonction raycast(voir tuto)

fonction draw ! attention bits->per pixel et de haut en bas, et texture avec tableau
*/
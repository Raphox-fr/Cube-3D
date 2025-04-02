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
    if (keycode == KEY_W  || keycode == KEY_UP)
        ray->key[keycode] = 1;
    if (keycode == KEY_A)
        ray->key[keycode] = 1;
    if (keycode == KEY_S || keycode == KEY_DOWN)
        ray->key[keycode] = 1;
    if (keycode == KEY_D)
        ray->key[keycode] = 1;
    if (keycode == KEY_LEFT)
        ray->key[keycode] = 1;
    if (keycode == KEY_RIGHT)
        ray->key[keycode] = 1;
}

void ft_key_release(int keycode, t_ray *ray)
{
    if (keycode == KEY_W || keycode == KEY_UP)
        ray->key[keycode] = 0;
    if (keycode == KEY_A)
        ray->key[keycode] = 0;
    if (keycode == KEY_S || keycode == KEY_DOWN)
        ray->key[keycode] = 0;
    if (keycode == KEY_D)
        ray->key[keycode] = 0;
    if (keycode == KEY_LEFT)
        ray->key[keycode] = 0;
    if (keycode == KEY_RIGHT)
        ray->key[keycode] = 0;
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
    //ft_memset(ray->img, 0, /*ray->width * ray->height * 4*/);     //ft_memset(void *s, int c, size_t n)
    ft_raycast(ray);
   // mlx_put_image_to_window(ray->mlx, ray->win, ray->img, 0, 0);
    return (0);
}


int ft_draw(t_ray *ray)
{

}

void    ft_move(t_ray *ray)
{
    if (ray->key[KEY_W])
    {
        //fonction move avant
        if (!ray->map[(int)(ray->posX + ray->dirX * MOVE_SPEED)][(int)ray->posY])
            ray->posX += ray->dirX * MOVE_SPEED;
        if (!ray->map[(int)ray->posX][(int)(ray->posY + ray->dirY * MOVE_SPEED)])
            ray->posY += ray->dirY * MOVE_SPEED;
    }
    if (ray->key[KEY_S])
    {
        //fonction move arriere
        if (!ray->map[(int)(ray->posX - ray->dirX * MOVE_SPEED)][(int)ray->posY])
            ray->posX -= ray->dirX * MOVE_SPEED;
        if (!ray->map[(int)ray->posX][(int)(ray->posY - ray->dirY * MOVE_SPEED)])
            ray->posY -= ray->dirY * MOVE_SPEED;
    }
    if (ray->key[KEY_A])
    {
        //fonction move gauche
        if (!ray->map[(int)(ray->posX - ray->dirY * MOVE_SPEED)][(int)ray->posY])
            ray->posX -= ray->dirY * MOVE_SPEED;
        if (!ray->map[(int)ray->posX][(int)(ray->posY + ray->dirX * MOVE_SPEED)])
            ray->posY += ray->dirX * MOVE_SPEED;
    }
    if (ray->key[KEY_D])
    {
        //fonction move droite
        if (!ray->map[(int)(ray->posX + ray->dirY * MOVE_SPEED)][(int)ray->posY])
            ray->posX += ray->dirY * MOVE_SPEED;
        if (!ray->map[(int)ray->posX][(int)(ray->posY - ray->dirX * MOVE_SPEED)])
            ray->posY -= ray->dirX * MOVE_SPEED;
    }
    if (ray->key[KEY_LEFT]) 
    {
        //fonction rotation gauche
        ray->oldDirX = ray->dirX;
        ray->dirX = ray->dirX * cos(ROT_SPEED) - ray->dirY * sin(ROT_SPEED);
        ray->dirY = ray->oldDirX * sin(ROT_SPEED) + ray->dirY * cos(ROT_SPEED);
        ray->oldPlaneX = ray->planeX;
        ray->planeX = ray->planeX * cos(ROT_SPEED) - ray->planeY * sin(ROT_SPEED);
        ray->planeY = ray->oldPlaneX * sin(ROT_SPEED) + ray->planeY * cos(ROT_SPEED);
    }
    if (ray->key[KEY_RIGHT]) 
    {
        //fonction rotation droite
        ray->oldDirX = ray->dirX;
        ray->dirX = ray->dirX * cos(-ROT_SPEED) - ray->dirY * sin(-ROT_SPEED);
        ray->dirY = ray->oldDirX * sin(-ROT_SPEED) + ray->dirY * cos(-ROT_SPEED);
        ray->oldPlaneX = ray->planeX;
        ray->planeX = ray->planeX * cos(-ROT_SPEED) - ray->planeY * sin(-ROT_SPEED);
        ray->planeY = ray->oldPlaneX * sin(-ROT_SPEED) + ray->planeY * cos(-ROT_SPEED);
    }    
}

void    ft_raycast(t_ray *ray)
{
        int x;
        
        x = 0;
        while (x < ray->size_x)
        {
            ray->cameraX = 2 * x / ray->size_x - 1;
            ray->rayDirX = ray->dirX + ray->planeX * ray->cameraX;
            ray->rayDirY = ray->dirY + ray->planeY * ray->cameraX;
            ray->deltaDistX = sqrt(1 + (ray->rayDirY * ray->rayDirY) / (ray->rayDirX * ray->rayDirX));
            ray->deltaDistY = sqrt(1 + (ray->rayDirX * ray->rayDirX) / (ray->rayDirY * ray->rayDirY));
            
            //une fonction ici
            ray->mapX = ray->posX;
            ray->mapY = ray->posY;
            if (ray->rayDirX < 0)
            {
                ray->stepX = -1;
                ray->sideDistX = (ray->posX - ray->mapX) * ray->deltaDistX;
            }
            else
            {
                ray->stepX = 1;
                ray->sideDistX = (ray->mapX + 1.0 - ray->posX) * ray->deltaDistX;
            }
            if (ray->rayDirY < 0)
            {
                ray->stepY = -1;
                ray->sideDistY = (ray->posY - ray->mapY) * ray->deltaDistY;
            }
            else
            {
                ray->stepY = 1;
                ray->sideDistY = (ray->mapY + 1.0 - ray->posY) * ray->deltaDistY;
            }
            
            //une fonction la
            ray->hit = 0;
            while (ray->hit == 0)
            {
                if (ray->sideDistX < ray->sideDistY)
                {
                    ray->sideDistX += ray->deltaDistX;
                    ray->mapX += ray->stepX;
                    ray->side = 0;
                }
                else
                {
                    ray->sideDistY += ray->deltaDistY;
                    ray->mapY += ray->stepY;
                    ray->side = 1;
                }
                if (ray->map2d[ray->mapX][ray->mapY] > 0) //rajout structure map map2d
                    ray->hit = 1;
            }
            if (ray->side == 0)
                ray->perpWallDist = (ray->mapX - ray->posX + (1 - ray->stepX) / 2) / ray->rayDirX;
            else
                ray->perpWallDist = (ray->mapY - ray->posY + (1 - ray->stepY) / 2) / ray->rayDirY;
            
            //une fonction ici
            ray->lineHeight = (int)(ray->h / ray->perpWallDist);
            ray->drawStart = -ray->lineHeight / 2 + ray->h / 2;
            if (ray->drawStart < 0)
                ray->drawStart = 0;
            ray->drawEnd = ray->lineHeight / 2 + ray->h / 2;
            if (ray->drawEnd >= ray->h) //h = size_y
                ray->drawEnd = ray->h - 1;
            x++;
            //fonction draw apres 
    }
}

/*
fonction : init struct ray
fonction launch : memset + mlx_put_image_to_window
fonction draw ! attention bits->per pixel et de haut en bas, et texture avec tableau
*/
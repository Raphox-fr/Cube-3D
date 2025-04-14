/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:10:58 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/14 18:37:06 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void    ft_raycast(t_ray *ray)
{
 
        double x;
        ray->size_x = ray->width;
        ray->size_y = ray->height;
        x = 0;
        while (x < ray->size_x)
        {
            ray->cameraX = 2 * x / (double)ray->size_x - 1;
            ray->rayDirX = ray->dirX + ray->planeX * ray->cameraX;
            ray->rayDirY = ray->dirY + ray->planeY * ray->cameraX;
            // ray->deltaDistX = sqrt(1 + (ray->rayDirY * ray->rayDirY) / (ray->rayDirX * ray->rayDirX));
            // ray->deltaDistY = sqrt(1 + (ray->rayDirX * ray->rayDirX) / (ray->rayDirY * ray->rayDirY));
            ray->deltaDistX = fabs(1 / ray->rayDirX);
            ray->deltaDistY = fabs(1 / ray->rayDirY);
            ft_distance(ray);
            ft_dda(ray);
            ft_height(ray); 
            ft_display(ray, x);  
            x++; 
    }
}


void    ft_distance(t_ray *ray)
{
    ray->mapX = (int)ray->posX;
    ray->mapY = (int)ray->posY;
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
}
void ft_dda(t_ray *ray)
{
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
		// // if (ray->mapX >= 0 && ray->mapX < ray->size_x &&
		// // 	ray->mapY >= 0 && ray->mapY < ray->size_y)
        if (ray->mapX >= 0 && ray->mapX < ray->size_x &&
            ray->mapY >= 0 && ray->mapY < ray->size_y &&
            ray->mapp.map_dis[ray->mapY][ray->mapX] == '1')
        {
                
                if (ray->mapp.map_dis[ray->mapY][ray->mapX] == '1')
                {
                    ray->hit = 1;
                }
            }
		// else
		// {
		// 	printf("  OUT OF BOUNDS: mapX = %d, mapY = %d (max: %f, %f)\n", ray->mapX, ray->mapY, ray->size_x, ray->size_y);
		// 	break;
		// }
	}
    
	// if (ray->side == 0)
    //     ray->perpWallDist = (ray->sideDistX - ray->rayDirX);
    // else
    //     ray->perpWallDist = (ray->sideDistY - ray->rayDirY);

	if (ray->side == 0)
		ray->perpWallDist = (ray->mapX - ray->posX + (1 - ray->stepX) / 2) / ray->rayDirX;
	else
		ray->perpWallDist = (ray->mapY - ray->posY + (1 - ray->stepY) / 2) / ray->rayDirY;

}


void    ft_height(t_ray *ray)
{
    ray->h = ray->size_y;
    ray->lineHeight = (int)(ray->h / ray->perpWallDist);
    ray->drawStart = -ray->lineHeight / 2 + ray->h / 2;
    if (ray->drawStart < 0)
        ray->drawStart = 0;
    ray->drawEnd = ray->lineHeight / 2 + (ray->h / 2);
    if (ray->drawEnd >= ray->h) //h = size_y
        ray->drawEnd = ray->h -1 ; //-1 
}

// void ft_dda(t_ray *ray)
// {
//     ray->hit = 0;
//     while (ray->hit == 0)
//     {
//         if (ray->sideDistX < ray->sideDistY)
//         {
//             ray->sideDistX += ray->deltaDistX;
//             ray->mapX += ray->stepX;
//             ray->side = 0;
//         }
//         else
//         {
//             ray->sideDistY += ray->deltaDistY;
//             ray->mapY += ray->stepY;
//             ray->side = 1;
//         }
//         if (ray->mapX >= 0 && ray->mapX < ray->size_x
//             && ray->mapY >= 0 && ray->mapY < ray->size_y
//             && ray->map[ray->mapX][ray->mapY] == '1')
//             ray->hit = 1;
//     }
//     if (ray->side == 0)
//         ray->perpWallDist = (ray->mapX - ray->posX + (1 - ray->stepX) / 2) / ray->rayDirX;
//     else
//         ray->perpWallDist = (ray->mapY - ray->posY + (1 - ray->stepY) / 2) / ray->rayDirY;
// }

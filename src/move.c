/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:12:53 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/02 17:27:15 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube.h"


void    ft_move(t_ray *ray)
{
    if (ray->key[KEY_W])
        ft_move_forward(ray);
    if (ray->key[KEY_S])
        ft_move_back(ray);
    if (ray->key[KEY_A])
        ft_move_left(ray);
    if (ray->key[KEY_D])
        ft_move_right(ray);
    if (ray->key[KEY_LEFT]) 
        ft_rotate_left(ray);
    if (ray->key[KEY_RIGHT]) 
        ft_rotate_right(ray);
}

void    ft_rotate_left(t_ray *ray)
{
    ray->oldDirX = ray->dirX;
    ray->dirX = ray->dirX * cos(ROT_SPEED) - ray->dirY * sin(ROT_SPEED);
    ray->dirY = ray->oldDirX * sin(ROT_SPEED) + ray->dirY * cos(ROT_SPEED);
    ray->oldPlaneX = ray->planeX;
    ray->planeX = ray->planeX * cos(ROT_SPEED) - ray->planeY * sin(ROT_SPEED);
    ray->planeY = ray->oldPlaneX * sin(ROT_SPEED) + ray->planeY * cos(ROT_SPEED);
}

void    ft_rotate_right(t_ray *ray)
{
    ray->oldDirX = ray->dirX;
    ray->dirX = ray->dirX * cos(-ROT_SPEED) - ray->dirY * sin(-ROT_SPEED);
    ray->dirY = ray->oldDirX * sin(-ROT_SPEED) + ray->dirY * cos(-ROT_SPEED);
    ray->oldPlaneX = ray->planeX;
    ray->planeX = ray->planeX * cos(-ROT_SPEED) - ray->planeY * sin(-ROT_SPEED);
    ray->planeY = ray->oldPlaneX * sin(-ROT_SPEED) + ray->planeY * cos(-ROT_SPEED);
}
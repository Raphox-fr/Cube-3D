/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:12:53 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/14 18:34:07 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	ft_move(t_ray *ray)
{
	if (ray->key_w)
		ft_move_forward(ray);
	if (ray->key_s)
		ft_move_back(ray);
	if (ray->key_a)
		ft_move_left(ray);
	if (ray->key_d)
		ft_move_right(ray);
	if (ray->key_l)
		ft_rotate_left(ray);
	if (ray->key_r)
		ft_rotate_right(ray);
}

void	ft_rotate_left(t_ray *ray)
{
	// printf("ray->dirX est %f\n", ray->dirX);
	// printf("		ray->dirY est %f\n", ray->dirY);
	ray->oldDirX = ray->dirX;
	ray->dirX = ray->dirX * cos(ROT_SPD) - ray->dirY * sin(ROT_SPD);
	ray->dirY = ray->oldDirX * sin(ROT_SPD) + ray->dirY * cos(ROT_SPD);
	// printf("					planeX est %f\n", ray->planeX);
	// printf("								planeY est %f\n", ray->planeY);
	ray->oldPlaneX = ray->planeX;
	ray->planeX = ray->planeX * cos(ROT_SPD) - ray->planeY * sin(ROT_SPD);
	ray->planeY = ray->oldPlaneX * sin(ROT_SPD) + ray->planeY * cos(ROT_SPD);
}

void	ft_rotate_right(t_ray *ray)
{
	// printf("la valeur de ray->dirX est %f\n", ray->dirX);
	// printf("la valeur de ray->dirY est %f\n", ray->dirY);
	ray->oldDirX = ray->dirX;
	ray->dirX = ray->dirX * cos(-ROT_SPD) - ray->dirY * sin(-ROT_SPD);
	ray->dirY = ray->oldDirX * sin(-ROT_SPD) + ray->dirY * cos(-ROT_SPD);
	
	ray->oldPlaneX = ray->planeX;
	ray->planeX = ray->planeX * cos(-ROT_SPD) - ray->planeY * sin(-ROT_SPD);
	ray->planeY = ray->oldPlaneX * sin(-ROT_SPD) + ray->planeY * cos(-ROT_SPD);
}


// dirX,Y
// planeX,Y;

// void ft_move(t_ray *ray)
// {
// 	printf("Direction initiale: dirX=%f, dirY=%f\n", ray->dirX, ray->dirY);
//     printf("Position avant: X=%f, Y=%f\n", ray->posX, ray->posY);
//     printf("Touches: W=%d, A=%d, S=%d, D=%d\n", ray->key_w, ray->key_a, ray->key_s, ray->key_d);
	
//     if (ray->key_w)
//     {
//         ft_move_forward(ray);
//         printf("Avancer\n");
//     }
//     if (ray->key_s)
//     {
//         ft_move_back(ray);
//         printf("Reculer\n");
//     }
//     if (ray->key_a)
//     {
//         ft_move_left(ray);
//         printf("Gauche\n");
//     }
//     if (ray->key_d)
//     {
//         ft_move_right(ray);
//         printf("Droite\n");
//     }
//     if (ray->key_l)
//         ft_rotate_left(ray);
//     if (ray->key_r)
//         ft_rotate_right(ray);
		
//     printf("Position après: X=%f, Y=%f\n", ray->posX, ray->posY);
// }

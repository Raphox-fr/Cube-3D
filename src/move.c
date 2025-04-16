/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:12:53 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/16 12:50:31 by aneumann         ###   ########.fr       */
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
	ray->olddirx = ray->dirx;
	ray->dirx = ray->dirx * cos(ROT_SPD) - ray->diry * sin(ROT_SPD);
	ray->diry = ray->olddirx * sin(ROT_SPD) + ray->diry * cos(ROT_SPD);
	ray->oldplanex = ray->planeX;
	ray->planeX = ray->planeX * cos(ROT_SPD) - ray->planeY * sin(ROT_SPD);
	ray->planeY = ray->oldplanex * sin(ROT_SPD) + ray->planeY * cos(ROT_SPD);
}

void	ft_rotate_right(t_ray *ray)
{
	ray->olddirx = ray->dirx;
	ray->dirx = ray->dirx * cos(-ROT_SPD) - ray->diry * sin(-ROT_SPD);
	ray->diry = ray->olddirx * sin(-ROT_SPD) + ray->diry * cos(-ROT_SPD);
	ray->oldplanex = ray->planeX;
	ray->planeX = ray->planeX * cos(-ROT_SPD) - ray->planeY * sin(-ROT_SPD);
	ray->planeY = ray->oldplanex * sin(-ROT_SPD) + ray->planeY * cos(-ROT_SPD);
}

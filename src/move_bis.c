/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:25:06 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/15 21:19:36 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	ft_move_forward(t_ray *ray)
{
	if (ray->mapp.map_dis[(int)(ray->posY + ray->dirY * (MOVE_SPEED + MARGE))] \
			[(int)ray->posX] != '1')
		ray->posY += ray->dirY * MOVE_SPEED;
	if (ray->mapp.map_dis[(int)ray->posY] \
			[(int)(ray->posX + ray->dirX * (MOVE_SPEED + MARG))] != '1')
		ray->posX += ray->dirX * MOVE_SPEED;
}

void	ft_move_back(t_ray *ray)
{
	if (ray->mapp.map_dis[(int)(ray->posY - ray->dirY * (MOVE_SPEED + MARGE))] \
			[(int)ray->posX] != '1')
		ray->posY -= ray->dirY * MOVE_SPEED;
	if (ray->mapp.map_dis[(int)ray->posY] \
			[(int)(ray->posX - ray->dirX * (MOVE_SPEED + MARG))] != '1')
		ray->posX -= ray->dirX * MOVE_SPEED;
}

void	ft_move_left(t_ray *ray)
{
	double	perdirx;
	double	perdiry;

	perdirx = ray->dirY;
	perdiry -= ray->dirX;
	if (ray->mapp.map_dis[(int)ray->posY] \
			[(int)(ray->posX + perdirx * (MOVE_SPEED + MARG))] != '1')
	ray->posX += perdirx * MOVE_SPEED;
	if (ray->mapp.map_dis[(int)(ray->posY + \
				perdiry * (MOVE_SPEED + MARG))][(int)ray->posX] != '1')
	ray->posY += perdiry * MOVE_SPEED;
}

void	ft_move_right(t_ray *ray)
{
	double	perdirx;
	double	perdiry;

	perdirx -= ray->dirY;
	perdiry = ray->dirX;
	if (ray->mapp.map_dis[(int)ray->posY][(int)(ray->posX + \
				perdirx * (MOVE_SPEED + MARG))] != '1')
	ray->posX += perdirx * MOVE_SPEED;
	if (ray->mapp.map_dis[(int)(ray->posY + perdiry * (MOVE_SPEED + MARG))] \
			[(int)ray->posX] != '1')
	ray->posY += perdiry * MOVE_SPEED;
}

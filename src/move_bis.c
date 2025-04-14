/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:25:06 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/14 19:09:47 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"
void ft_move_forward(t_ray *ray)
{

	if (ray->mapp.map_dis[(int)(ray->posY + ray->dirY * (MOVE_SPEED + MARG))][(int)ray->posX] != '1')
		ray->posY += ray->dirY * MOVE_SPEED;
	else
		return ;
	if (ray->mapp.map_dis[(int)ray->posY][(int)(ray->posX + ray->dirX * ( MOVE_SPEED + MARG))] !='1')
		ray->posX += ray->dirX * MOVE_SPEED;
	else
		return ;	
}

void	ft_move_back(t_ray *ray)
{
	if (ray->mapp.map_dis[(int)(ray->posY - ray->dirY * (MOVE_SPEED + MARG))][(int)ray->posX] != '1')
		ray->posY -= ray->dirY * MOVE_SPEED;
	else
		return ;
	if (ray->mapp.map_dis[(int)ray->posY][(int)(ray->posX - ray->dirX * ( MOVE_SPEED + MARG))]!= '1')
		ray->posX -= ray->dirX * MOVE_SPEED;
	else
		return ;
	}

void	ft_move_left(t_ray *ray)
{
	// printf("la valeur de ray->posX est %f\n", ray->posX);
	// printf("la valeur de ray->posY est %f\n", ray->posY);
	// printf("la valeur de ray->dirX est %f\n", ray->dirX);
	// printf("la valeur de ray->dirY est %f\n", ray->dirY);
	// printf("la valeur de ray->map est %d\n", ray->mapp.map_dis[(int)ray->posY][(int)ray->posX]);
	// printf("la valeur de ray->map est %d\n", ray->mapp.map_dis[(int)ray->posY + 1][(int)ray->posX ]);
	// display_map_simple(ray->mapp.map_dis);
	if (ray->mapp.map_dis[(int)ray->posY][(int)(ray->posX - ray->dirY * (MOVE_SPEED + MARG))]!= '1')
		ray->posX += ray->dirY * MOVE_SPEED;
	else
		return ;
	if (ray->mapp.map_dis[(int)(ray->posY + ray->dirX * (MOVE_SPEED + MARG))][(int)ray->posX]!= '1')
		ray->posY -= ray->dirX * MOVE_SPEED;
	else
		return ;
}

void	ft_move_right(t_ray *ray)
{
	if (ray->mapp.map_dis[(int)ray->posY][(int)(ray->posX + ray->dirY * (MOVE_SPEED + MARG))]!= '1')
		ray->posX -= ray->dirY * MOVE_SPEED;
	else
		return ;
	if (ray->mapp.map_dis[(int)(ray->posY - ray->dirX * (MOVE_SPEED + MARG ))][(int)ray->posX]!= '1')
		ray->posY += ray->dirX * MOVE_SPEED;
	else
		return ;
}

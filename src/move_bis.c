/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:25:06 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/16 12:45:14 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	ft_move_forward(t_ray *ray)
{
	if (ray->mapp.map_dis[(int)(ray->posy + ray->diry * (MOVE_SPEED + MARG))] \
			[(int)ray->posx] != '1')
		ray->posy += ray->diry * MOVE_SPEED;
	if (ray->mapp.map_dis[(int)ray->posy] \
			[(int)(ray->posx + ray->dirx * (MOVE_SPEED + MARG))] != '1')
		ray->posx += ray->dirx * MOVE_SPEED;
}

void	ft_move_back(t_ray *ray)
{
	if (ray->mapp.map_dis[(int)(ray->posy - ray->diry * (MOVE_SPEED + MARG))] \
			[(int)ray->posx] != '1')
		ray->posy -= ray->diry * MOVE_SPEED;
	if (ray->mapp.map_dis[(int)ray->posy] \
			[(int)(ray->posx - ray->dirx * (MOVE_SPEED + MARG))] != '1')
		ray->posx -= ray->dirx * MOVE_SPEED;
}

void	ft_move_left(t_ray *ray)
{
	double	perdirx;
	double	perdiry;

	perdirx = ray->diry;
	perdiry -= ray->dirx;
	if (ray->mapp.map_dis[(int)ray->posy] \
			[(int)(ray->posx + perdirx * (MOVE_SPEED + MARG))] != '1')
	ray->posx += perdirx * MOVE_SPEED;
	if (ray->mapp.map_dis[(int)(ray->posy + \
				perdiry * (MOVE_SPEED + MARG))][(int)ray->posx] != '1')
	ray->posy += perdiry * MOVE_SPEED;
}

void	ft_move_right(t_ray *ray)
{
	double	perdirx;
	double	perdiry;

	perdirx -= ray->diry;
	perdiry = ray->dirx;
	if (ray->mapp.map_dis[(int)ray->posy][(int)(ray->posx + \
				perdirx * (MOVE_SPEED + MARG))] != '1')
	ray->posx += perdirx * MOVE_SPEED;
	if (ray->mapp.map_dis[(int)(ray->posy + perdiry * (MOVE_SPEED + MARG))] \
			[(int)ray->posx] != '1')
	ray->posy += perdiry * MOVE_SPEED;
}

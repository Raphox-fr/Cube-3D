/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:25:06 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/02 17:57:45 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_move_forward(t_ray *ray)
{
	if (!ray->map[(int)(ray->posX + ray->dirX * MOVE_SPEED)][(int)ray->posY])
		ray->posX += ray->dirX * MOVE_SPEED;
	if (!ray->map[(int)ray->posX][(int)(ray->posY + ray->dirY * MOVE_SPEED)])
		ray->posY += ray->dirY * MOVE_SPEED;
}

void	ft_move_back(t_ray *ray)
{
	if (!ray->map[(int)(ray->posX - ray->dirX * MOVE_SPEED)][(int)ray->posY])
		ray->posX -= ray->dirX * MOVE_SPEED;
	if (!ray->map[(int)ray->posX][(int)(ray->posY - ray->dirY * MOVE_SPEED)])
		ray->posY -= ray->dirY * MOVE_SPEED;
}

void	ft_move_left(t_ray *ray)
{
	if (!ray->map[(int)(ray->posX - ray->dirY * MOVE_SPEED)][(int)ray->posY])
		ray->posX -= ray->dirY * MOVE_SPEED;
	if (!ray->map[(int)ray->posX][(int)(ray->posY + ray->dirX * MOVE_SPEED)])
		ray->posY += ray->dirX * MOVE_SPEED;
}

void	ft_move_right(t_ray *ray)
{
	if (!ray->map[(int)(ray->posX + ray->dirY * MOVE_SPEED)][(int)ray->posY])
		ray->posX += ray->dirY * MOVE_SPEED;
	if (!ray->map[(int)ray->posX][(int)(ray->posY - ray->dirX * MOVE_SPEED)])
		ray->posY -= ray->dirX * MOVE_SPEED;
}

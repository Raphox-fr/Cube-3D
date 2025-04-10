/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:14:21 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/10 18:17:47 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void ft_display(t_ray *ray, int x)
{
	int				y;
	char			*pixel;
	unsigned int	color;
	int				dir;

	// Plafond
	y = 0;
	while (y < ray->drawStart)
	{
		pixel = ray->img->addr + (y * ray->img->line_length + x * (ray->img->bpp / 8));
		*(unsigned int *)pixel = ray->c_color;
		y++;
	}

	// Direction de la texture
    if (ray->side == 1)
    {
        if (ray->rayDirY > 0)
            dir = SOUTH;
        else
            dir = NORTH;
    }
    else
    {
        if (ray->rayDirX > 0)
            dir = EAST;
        else
            dir = WEST;
    }
	// Calcul des infos pour la texture murale
	double wallX;
    if (ray->side == 0)
	    wallX = ray->posY + ray->perpWallDist * ray->rayDirY;
    else
	    wallX = ray->posX + ray->perpWallDist * ray->rayDirX;
	wallX -= floor(wallX);

	int texX = (int)(wallX * ray->textures[dir].width); // voir si texX ici et pas structure 
	if ((ray->side == 0 && ray->rayDirX > 0) || (ray->side == 1 && ray->rayDirY < 0))
		texX = ray->textures[dir].width - texX - 1;

	double step = 1.0 * ray->textures[dir].height / ray->lineHeight;
	double texPos = (ray->drawStart - ray->size_y / 2 + ray->lineHeight / 2) * step;

	// Mur
	y = ray->drawStart;
	while (y < ray->drawEnd)
	{
		int texY = (int)texPos & (ray->textures[dir].height - 1);
		texPos += step;

		color = *(unsigned int *)(ray->textures[dir].addr
			+ (texY * ray->textures[dir].line_length
			+ texX * (ray->textures[dir].bpp / 8)));

		pixel = ray->img->addr + (y * ray->img->line_length + x * (ray->img->bpp / 8));
		*(unsigned int *)pixel = color;
		y++;
	}

	// Sol
	while (y < ray->size_y)
	{
		pixel = ray->img->addr + (y * ray->img->line_length + x * (ray->img->bpp / 8));
		*(unsigned int *)pixel = ray->f_color;
		y++;
	}
}

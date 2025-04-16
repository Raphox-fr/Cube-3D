/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:14:21 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/16 12:49:08 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	ft_display(t_ray *ray, int x)
{
	int	dir;

	ray->c_color = ray->mapp.hex_ceiling;
	ray->f_color = ray->mapp.hex_floor;
	ft_draw_ceiling(ray, x);
	dir = ft_get_texture_direction(ray);
	ft_draw_wall(ray, x, dir);
	ft_draw_floor(ray, x);
}

void	ft_draw_ceiling(t_ray *ray, int x)
{
	int		y;
	char	*pixel;

	y = 0;
	while (y < ray->drawstart)
	{
		pixel = ray->img->addr + (y * ray->img->line_length + x * (ray->img->bpp
					/ 8));
		*(unsigned int *)pixel = ray->c_color;
		y++;
	}
}

int	ft_get_texture_direction(t_ray *ray)
{
	if (ray->side == 1)
	{
		if (ray->raydiry > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
	else
	{
		if (ray->raydirx > 0)
			return (EAST);
		else
			return (WEST);
	}
}

void	ft_calc_texture_vars(t_ray *ray, int dir, int *tex_x,
		double *step_tex_pos)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = ray->posy + ray->perpwalldist * ray->raydiry;
	else
		wall_x = ray->posx + ray->perpwalldist * ray->raydirx;
	wall_x -= floor(wall_x);
	*tex_x = (int)(wall_x * ray->textures[dir].width);
	if ((ray->side == 0 && ray->raydirx > 0) || (ray->side == 1
			&& ray->raydiry < 0))
		*tex_x = ray->textures[dir].width - *tex_x - 1;
	*step_tex_pos = (double)ray->textures[dir].height / ray->lineheight;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:17:22 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/16 12:23:45 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	ft_draw_wall(t_ray *ray, int x, int dir)
{
	int		tex_x;
	double	tex_pos;
	double	step;

	ft_calc_texture_vars(ray, dir, &tex_x, &step);
	tex_pos = (ray->drawStart - ray->size_y / 2
			+ ray->lineHeight / 2) * step;
	ft_draw_wall_loop(ray, x, dir, tex_x, tex_pos, step);
}

void	ft_draw_wall_loop(t_ray *ray, int x, int dir, int tex_x, double tex_pos, double step)
{
	int				y;
	int				tex_y;
	char		*pixel;
	unsigned int		color;

	y = ray->drawStart;
	while (y < ray->drawEnd)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= ray->textures[dir].height)
			tex_y = ray->textures[dir].height - 1;
		color = *(unsigned int *)(ray->textures[dir].addr \
				+ (tex_y * ray->textures[dir].line_length \
					+ tex_x * (ray->textures[dir].bpp / 8)));
		pixel = ray->img->addr + (y * ray->img->line_length \
				+ x * (ray->img->bpp / 8));
		*(unsigned int *)pixel = color;
		tex_pos += step;
		y++;
	}
}

void	ft_draw_floor(t_ray *ray, int x)
{
	int		y;
	char	*pixel;

	y = ray->drawEnd;
	while (y < ray->size_y)
	{
		pixel = ray->img->addr + (y * ray->img->line_length
				+ x * (ray->img->bpp / 8));
		*(unsigned int *)pixel = ray->f_color;
		y++;
	}
}

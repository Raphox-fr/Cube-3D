/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:17:22 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/16 12:41:42 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	ft_draw_wall(t_ray *ray, int x, int dir)
{
	int		tex_x;
	double	step;
	t_draw	draw;

	ft_calc_texture_vars(ray, dir, &tex_x, &step);
	draw.x = x;
	draw.dir = dir;
	draw.tex_x = tex_x;
	draw.step = step;
	draw.tex_pos = (ray->drawStart - ray->size_y / 2
			+ ray->lineHeight / 2) * step;
	ft_draw_wall_loop(ray, draw);
}

void	ft_draw_wall_loop(t_ray *ray, t_draw draw)
{
	int		y;
	int		tex_y;
	char	*pixel;
	unsigned int color;

	y = ray->drawStart;
	while (y < ray->drawEnd)
	{
		tex_y = (int)draw.tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= ray->textures[draw.dir].height)
			tex_y = ray->textures[draw.dir].height - 1;
		color = *(unsigned int *)(ray->textures[draw.dir].addr
				+ (tex_y * ray->textures[draw.dir].line_length
					+ draw.tex_x * (ray->textures[draw.dir].bpp / 8)));
		pixel = ray->img->addr + (y * ray->img->line_length
				+ draw.x * (ray->img->bpp / 8));
		*(unsigned int *)pixel = color;
		draw.tex_pos += draw.step;
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

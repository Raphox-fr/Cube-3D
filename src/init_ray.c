/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:53:33 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/16 12:45:14 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	init_struct_ray(t_ray *ray)
{
	ray->posx = (double)ray->mapp.x_player + 0.5;
	ray->posy = (double)ray->mapp.y_player + 0.5;
	ray->key_w = 0;
	ray->key_a = 0;
	ray->key_s = 0;
	ray->key_d = 0;
	ray->key_l = 0;
	ray->key_r = 0;
	if (init_player(ray) == -1)
		return (display_error("init_player\n"), -1);
	ray->h = ray->height;
	return (0);
}

int	init_img(t_ray *ray)
{
	ray->img = malloc(sizeof(t_img));
	if (!ray->img)
		return (display_error("malloc img\n"), -1);
	ray->img->img = mlx_new_image(ray->mlx, ray->width, ray->height);
	if (!ray->img->img)
		return (display_error("mlx_new_image\n"), -1);
	ray->img->addr = mlx_get_data_addr(ray->img->img, \
			&ray->img->bpp, &ray->img->line_length, &ray->img->endian);
	if (!ray->img->addr)
		return (display_error("mlx_get_data_addr\n"), -1);
	ray->img->width = ray->width;
	ray->img->height = ray->height;
	return (0);
}

int	init_player(t_ray *ray)
{
	ray->axe = ray->mapp.player_directions;
	if (ray->axe == 'N')
		ft_init_player_n(ray);
	else if (ray->axe == 'S')
		ft_init_player_s(ray);
	else if (ray->axe == 'E')
	{
		ray->dirx = 1;
		ray->diry = 0;
		ray->planeX = 0;
		ray->planeY = -0.66;
	}
	else if (ray->axe == 'W')
	{
		ray->dirx = -1;
		ray->diry = 0;
		ray->planeX = 0;
		ray->planeY = 0.66;
	}
	else
		return (printf("Error\ninvalid orientation '%c'\n", ray->axe), -1);
	return (0);
}

void	ft_init_player_n(t_ray *ray)
{
	ray->dirx = 0;
	ray->diry = -1;
	ray->planeX = 0.66;
	ray->planeY = 0;
}

void	ft_init_player_s(t_ray *ray)
{
	ray->dirx = 0;
	ray->diry = 1;
	ray->planeX = -0.66;
	ray->planeY = 0;
}

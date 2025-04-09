/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpm_to_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:19:52 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/09 16:55:26 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_xpm_to_img(t_ray *ray)
{
	ray->textures[NORTH].img = mlx_xpm_file_to_image(ray->mlx, ray->mapp->no_txture,
		&ray->textures[NORTH].width, &ray->textures[NORTH].height);
	if (!ray->textures[NORTH].img)
		return (printf("Error loading NORTH texture\n"), -1);
	ray->textures[NORTH].addr = mlx_get_data_addr(ray->textures[NORTH].img,
		&ray->textures[NORTH].bpp, &ray->textures[NORTH].line_length,
		&ray->textures[NORTH].endian);

	ray->textures[SOUTH].img = mlx_xpm_file_to_image(ray->mlx, ray->mapp->so_txture,
		&ray->textures[SOUTH].width, &ray->textures[SOUTH].height);
	if (!ray->textures[SOUTH].img)
		return (printf("Error loading SOUTH texture\n"), -1);
	ray->textures[SOUTH].addr = mlx_get_data_addr(ray->textures[SOUTH].img,
		&ray->textures[SOUTH].bpp, &ray->textures[SOUTH].line_length,
		&ray->textures[SOUTH].endian);

	ray->textures[EAST].img = mlx_xpm_file_to_image(ray->mlx, ray->mapp->ea_txture,
		&ray->textures[EAST].width, &ray->textures[EAST].height);
	if (!ray->textures[EAST].img)
		return (printf("Error loading EAST texture\n"), -1);
	ray->textures[EAST].addr = mlx_get_data_addr(ray->textures[EAST].img,
		&ray->textures[EAST].bpp, &ray->textures[EAST].line_length,
		&ray->textures[EAST].endian);

	ray->textures[WEST].img = mlx_xpm_file_to_image(ray->mlx, ray->mapp->we_txture,
		&ray->textures[WEST].width, &ray->textures[WEST].height);
	if (!ray->textures[WEST].img)
		return (printf("Error loading WEST texture\n"), -1);
	ray->textures[WEST].addr = mlx_get_data_addr(ray->textures[WEST].img,
		&ray->textures[WEST].bpp, &ray->textures[WEST].line_length,
		&ray->textures[WEST].endian);

	return (0);
}

void	ft_free_textures(t_ray *ray)
{
	int i = 0;
	while (i < 4)
	{
		if (ray->textures[i].img)
			mlx_destroy_image(ray->mlx, ray->textures[i].img);
		i++;
	}
}


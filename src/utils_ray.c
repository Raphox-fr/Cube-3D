/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:54:59 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/16 11:41:17 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	get_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_map_width(char **map)
{
	int	max_width;
	int	tmp;
	int	i;

	max_width = 0;
	i = 0;
	while (map[i])
	{
		tmp = ft_strlen(map[i]);
		if (tmp > max_width)
			max_width = tmp;
		i++;
	}
	return (max_width);
}

void	init_all_zero(t_ray *ray)
{
	int	i;

	ray->img = NULL;
	ray->win = NULL;
	ray->mlx = NULL;
	i = 0;
	while (i < 4)
	{
		ray->textures[i].img = NULL;
		i++;
	}
}

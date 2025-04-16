/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:03:33 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/16 11:47:00 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	main(int argc, char **argv)
{
	t_ray	ray;

	ray.mapp = parsing(argc, argv);
	if (ray.mapp.error == -1)
		return (-1);
	if (!ft_launch(&ray))
		return (display_error(""), 1);
	return (0);
}
// if (parsing(argc, argv) == -1)
//     return (-1);
// printf("mapp->x_player = %d\n", ray.mapp.x_player);
// printf("mapp->y_player = %d\n", ray.mapp.y_player);

// return (-1);
// printf("mapp->x_player = %d\n", ray.mapp.x_player);
// printf("mapp->y_player = %d\n", ray.mapp.y_player);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:48:03 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/14 15:30:55 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	free_struct_map(t_struct *map)
{
	free_split(map->map_table);
	free_split(map->map_only);
	free_split(map->map_dis);
	if (map->no_txture != NULL)
		free(map->no_txture);
	if (map->so_txture != NULL)
		free(map->so_txture);
	if (map->we_txture != NULL)
		free(map->we_txture);
	if (map->ea_txture != NULL)
		free(map->ea_txture);
	if (map->map_brut)
		free(map->map_brut);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	display_error(char *str_error)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	while (str_error[i])
	{
		ft_putchar_fd(str_error[i], 2);
		i++;
	}
}

void	free_split(char **cmd)
{
	int	i;

	i = 0;
	if (cmd == NULL)
		return ;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

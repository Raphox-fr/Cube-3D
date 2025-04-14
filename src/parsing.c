/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:55:02 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/14 12:53:54 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

t_struct	parsing(int argc, char **argv)
{
	t_struct	map;

	init_struct_map(&map);
	if (check_input(argc, argv) == -1)
		map.error = -1;
	if (check_map(&map, argv[1]) == -1)
		map.error = -1;
	return (map);
}

int	check_input(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
		return (display_error("No map selected, please choose a map.\n"), -1);
	if (argc >= 3)
		return (display_error("Only one map is accepted\n"), -1);
	if (check_name_map(argv[1]) == -1)
	{
		display_error("Incorrect format, check map format\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (display_error("File doesn't exist or check permissions.\n"), -1);
	close(fd);
	return (1);
}

int	check_name_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i >= 1 && str[i] == '.' && str[i + 1] == 'c' && str[i + 2] == 'u'
			&& str[i + 3] == 'b' && str[i + 4] == '\0')
			return (1);
		i++;
	}
	return (-1);
}

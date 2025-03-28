/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:55:02 by rafaria           #+#    #+#             */
/*   Updated: 2025/03/28 20:15:53 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cube.h"




int parsing(int argc, char **argv, char **envp)
{
	t_struct map;
	init_struct_map(&map);
    if (check_input(argc, argv) == -1)
		return (-1);
	if (check_map(&map, argv[1]) == -1);
		return (-1);
	return (0);
}




int check_input(int argc, char **argv)
{
    int fd;
	if (argc == 1)
		return (printf("Error : No map selected, please choose a map.\n"), -1);
	if (argc >= 3)
		return (printf("Error : Only one map is accepted\n"), -1);
	if (check_name_map(argv[1]) == -1)
		return (printf("Error : incorrect format, check map format (only .cub accepted)\n"), -1);
	fd = open(argv[1], O_RDONLY);
    if (fd < 0)
		return (printf("Error : File does not exist, or check permissions.\n"), -1);
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
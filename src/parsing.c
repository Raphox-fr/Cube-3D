/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:55:02 by rafaria           #+#    #+#             */
/*   Updated: 2025/03/27 18:54:52 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cube.h"
#include "../includes/get_next_line.h"



int parsing(int argc, char **argv, char **envp)
{
	t_struct game;
	if (argc == 1)
		return (printf("Error : No map selected, please choose a map.\n"), -1);
    if (argc >= 3)
		return (printf("Error : Only one map is accepted\n"), -1);
	if (check_name_map(argv[1]) == -1)
		return (printf("Error : incorrect format, check map format (only .cub accepted)\n"), -1);
	
	
		
	return 0;
}



char *read_file(char *filename)
{
	int		fd;
	char	*content;
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror("open"), NULL);
	content = malloc(9999);
	if (content == NULL)
		return (perror("malloc"), close(fd), NULL);
	bytes_read = read(fd, content, 9999);
	if (bytes_read == -1)
		return (perror("read"), free(content), close(fd), NULL);
	content[bytes_read] = '\0';
	close(fd);
	return (content);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:55:02 by rafaria           #+#    #+#             */
/*   Updated: 2025/03/27 13:26:34 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cube.h"
#include "../includes/get_next_line.h"



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

int parsing(int argc, char **argv, char **envp)
{
    if (argc == 1)
        printf("Error : No map selected, please choose a map.\n");
    if (argc >= 3)
        printf("Error : Only one map is accepted\n");    
    printf ("%s", read_file(argv[1]));
        return 0;
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:17:35 by raphox            #+#    #+#             */
/*   Updated: 2025/03/28 14:49:11 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_all_line(char *line, int fd)
{
	char	*buffer;
	int		curseur;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	curseur = 1;
	while (!ft_strchr(line, '\n') && curseur != 0)
	{
		curseur = read(fd, buffer, BUFFER_SIZE);
		if (curseur == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[curseur] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_res_line(char *line)
{
	int		i;
	char	*res_line;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] != '\n' && line[i])
		i++;
	res_line = malloc((i + 2) * sizeof(char));
	i = 0;
	while (line[i] != '\n' && line[i])
	{
		res_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		res_line[i] = line[i];
		i++;
	}
	res_line[i] = '\0';
	return (res_line);
}

char	*get_leftover_line(char *line)
{
	int		i;
	int		j;
	char	*stock_leftover;

	j = 0;
	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == 0)
	{
		free(line);
		return (NULL);
	}
	stock_leftover = malloc(sizeof(char) * (ft_strlen_size_t(line) - i + 1));
	if (!stock_leftover)
		return (NULL);
	i++;
	while (line[i])
	{
		stock_leftover[j++] = line[i++];
	}
	stock_leftover[j] = '\0';
	free(line);
	return (stock_leftover);
}

char	*get_next_line(int fd)
{
	char		*resleft_line;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = get_all_line(line, fd);
	if (!line)
		return (NULL);
	resleft_line = get_res_line(line);
	line = get_leftover_line(line);
	return (resleft_line);
}

// int	main(void)
// {
// 	int fd;
// 	char *next_line;
// 	int count;

// 	count = 0;
// 	fd = open("example.txt", O_RDONLY);

//     next_line = get_next_line(fd);

//     printf("\n");
//     printf("resultat : ");
//     printf("%s", next_line);
//     printf("\n");

//     free(next_line);
// 	close(fd);
//     return (0);
// }
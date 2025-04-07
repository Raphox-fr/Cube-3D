/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:20:49 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/07 21:12:23 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	ft_strlen_cub(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strdup_pimp(const char *src)
{
	int		i;
	int		j;
	int		countstr;
	char	*dest;

	i = 0;
	j = 0;
	countstr = ft_strlen_spaces_tabs(src);
	dest = malloc((sizeof(char)) * (countstr + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		if (src[i] != ' ')
		{
			dest[j] = src[i];
			j++;
		}
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

int	ft_strlen_spaces_tabs(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			count++;
		i++;
	}
	return (count);
}

int	count_size_y(int x, char **map_table)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (map_table[i])
	{
		i++;
	}
	return (i);
}

int	count_size_x(int y, char **str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[y][i] && str[y])
	{
		i++;
	}
	return (i);
}

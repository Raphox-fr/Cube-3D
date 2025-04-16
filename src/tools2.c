/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:16:03 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/16 12:20:11 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	verify_syntax_rgb(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return (-1);
		i++;
	}
	return (1);
}

int	count_number(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i]) >= '0' && str[i] <= '9')
			count++;
		i++;
	}
	if (count >= 4)
		return (-1);
	return (count);
}

int	count_characters(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i]) == c)
			count++;
		i++;
	}
	if (count != 2)
		return (-1);
	return (1);
}

int	count_size_y(char **map_table)
{
	int	i;

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

	i = 0;
	while (str[y][i] && str[y])
	{
		i++;
	}
	return (i);
}

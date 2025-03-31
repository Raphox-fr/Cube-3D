/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:20:49 by rafaria           #+#    #+#             */
/*   Updated: 2025/03/31 16:03:48 by rafaria          ###   ########.fr       */
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
    int j;
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
        if (src[i] != ' ' && src[i] != '\t')
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
    int count;

	i = 0;
    count = 0;
	while (str[i])
	{
        if (str[i] != ' ' && str[i] != '\t') 
            count++;
		i++;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:46:45 by raphox            #+#    #+#             */
/*   Updated: 2025/04/10 15:03:48 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>



int	ft_countwords(const char *str, char set)
{
	int	i;
	int	count;

	count = 0;
	i = 1;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == set && str[i - 1] != set)
			count++;
		i++;
	}
	if (str[i - 1] != set)
		count++;
	return (count);
}

char	*ft_strempli(const char *s, char set)
{
	int		i;
	int		countstr;
	char	*dest;

	i = 0;
	countstr = 0;
	while (s[countstr] != set && s[countstr] != '\0')
		countstr++;
	dest = malloc((sizeof(char)) * (countstr + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i] != set && s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_fill(char **tab, int countwords, const char *s, char set)
{
	int	mot;
	int	start;

	mot = 0;
	start = 0;
	while (mot < countwords)
	{
		while (s[start] == set)
			start++;
		tab[mot] = ft_strempli(&s[start], set);
		if (tab[mot] == NULL)
		{
			while (mot >= 0)
			{
				free(tab[mot]);
				mot--;
			}
			free(tab);
			return (NULL);
		}
		start = start + ft_strlen(tab[mot]);
		mot++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		countwords;

	countwords = ft_countwords(s, c);
	if (countwords == 0)
	{
		tab = malloc(sizeof(char *) * 1);
		tab[0] = 0;
		return (tab);
	}
	tab = malloc(sizeof(char *) * (countwords + 1));
	if (tab == NULL)
		return (NULL);
	tab = ft_fill(tab, countwords, s, c);
	if (tab == NULL)
		return (NULL);
	tab[countwords] = 0;
	return (tab);
}

// 8 9 14 15
// int        main(void)
// {
// 	int i;
// 	int y;

// 	i = 0;
// 	y = 0;
//     char **tab;
//     tab = ft_split("bonjour    va", ' ');

// 	while(tab[i] != 0)
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
// }
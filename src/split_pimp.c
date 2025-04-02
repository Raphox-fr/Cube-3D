/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pimp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:46:45 by raphox            #+#    #+#             */
/*   Updated: 2025/04/02 18:53:00 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"



int	ft_count_level(const char *str, char set)
{
	int	i;
	int	count;

	count = 0;
	i = 1;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == set)
			count++;
		i++;
	}
	return (count);
}

char	*ft_strempli_pimp(const char *s, char set)
{
	int		i;
	int		countstr;
	char	*dest;

	i = 0;
	countstr = 0;

	if (s[countstr] == set && s[countstr + 1] == '\0')
	{
		dest = malloc((sizeof(char)) * 2);
		if (dest == NULL)
			return (NULL);
		dest[0] = set;
		dest[1] = '\0';
		return (dest);
	}
	while (s[countstr] != set && s[countstr] != '\0')
		countstr++;
	dest = malloc((sizeof(char)) * (countstr + 1));
	if (dest == NULL)
		return (NULL);
	while (i < countstr)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


char	**ft_fill_pimp(char **tab, int countwords, const char *s, char set)
{
	int	mot;
	int	start;

	mot = 0;
	start = 0;
	while (mot < countwords)
	{
		tab[mot] = ft_strempli_pimp(&s[start], set);
		start = start + ft_strlen(tab[mot]);
		mot++;
	}
	return (tab);
}

char	**ft_split_pimp(char const *s, char c)
{
	char	**tab;
	int		countwords;

	countwords = ft_count_level(s, c);
	if (countwords == 0)
	{
		tab = malloc(sizeof(char *) * 1);
		tab[0] = 0;
		return (tab);
	}
	tab = malloc(sizeof(char *) * (countwords + 1));
	if (tab == NULL)
		return (NULL);
	tab = ft_fill_pimp(tab, countwords, s, c);
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
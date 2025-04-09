/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:14:13 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/09 17:01:01 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	check_extension_xpm(char *file_path)
{
	int	i;

	i = 0;
	while (file_path[i])
	{
		if (i >= 1 && file_path[i] == '.' && file_path[i + 1] == 'x'
			&& file_path[i + 2] == 'p' && file_path[i + 3] == 'm' && file_path[i
				+ 4] == '\0')
		{
			return (1);
		}
		i++;
	}
	display_error("Invalid extension, only .xpm accepted\n");
	return (-1);
}

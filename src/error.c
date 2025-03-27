/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:48:03 by rafaria           #+#    #+#             */
/*   Updated: 2025/03/27 17:55:21 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void display_error(char *str_error)
{
    int i;
    i = 0;

    write(2, "Error\n", 6);
    while (str_error[i])
    {
        ft_putchar_fd(str_error[i], 2);
        i++;
    }
}
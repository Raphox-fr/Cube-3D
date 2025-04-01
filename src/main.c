/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:03:33 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/01 14:51:27 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cube.h"

int main(int argc, char **argv, char **envp)
{
    t_ray ray;	
    if (parsing(argc, argv,  envp) == -1)
        return (-1);
    // if (!ft_launch(&ray))
    //     return (printf("CA NE MARCHE PAS\n"), 1);
    return (0);
}
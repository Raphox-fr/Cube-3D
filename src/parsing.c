/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:55:02 by rafaria           #+#    #+#             */
/*   Updated: 2025/03/27 12:55:05 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cube.h"
#include "../includes/get_next_line.h"





int parsing(int argc, char **argv, char **envp)
{
    
    if (argc == 1)
        printf("Error : No map selected, please choose a map.\n");
    if (argc >= 3)
        printf("Error : Only one map is accepted\n");    
    return 0;
}

int read_file(char *file)
{
    int fd;
    read(fd, )
}


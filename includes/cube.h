/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:39:02 by rafaria           #+#    #+#             */
/*   Updated: 2025/03/28 16:21:44 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "stdbool.h"
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>


typedef struct s_ray
{
    int posX;
    int posY;
    int dirX;
    int dirY;
    int planeX;
    int planeY;
    double time;
    double oldTime;
    double cameraX;
    double rayDirX;
    double rayDirY;
    int mapX;
    int mapY;
    double sideDistX;
    double sideDistY;
    double deltaDistX;
    double deltaDistY;
    double perpWallDist;
    int stepX;
    int stepY;
    int hit;
    int side;
    int lineHeight;
    int drawStart;
    int drawEnd;
    int color;
    int x;
    int y;
    int texNum;
    double wallX;
    int texX;
    int texY;
    double step;
    double texPos;
    int texWidth;
    int texHeight;
    int texColor;
    int *texture;
    double floorXWall;
    double floorYWall;
    double distWall;
    double distPlayer;
    double currentDist;
    void *mlx;
    void *win;
    int width;
    int height;
    int **map;
    int moveSpeed;
    int rotSpeed;
    int key[300];
    double oldDirX;
    double oldPlaneX;
    double oldDirY;
    double oldPlaneY;
    int key_w;
    int key_a;
    int key_s;
    int key_d;
    int key_left;
    int key_right;
    int key_esc;
}   t_ray;


// PARSING |

int parsing(int argc, char **argv, char **envp);

char *read_file(char *filename);



// DISPLAY
int ft_launch(t_ray *ray);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:39:02 by rafaria           #+#    #+#             */
/*   Updated: 2025/03/31 19:00:01 by aneumann         ###   ########.fr       */
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

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
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
    int moveSpeed;//faire un define variable globale
    int rotSpeed;//same 
    int key[300];
    double oldDirX;
    double oldPlaneX;
    double oldDirY;
    double oldPlaneY;
    int key_left;
    int key_right;
    int key_esc;
    int key_up;
    int key_down;
    int key_w;
    int key_a;
    int key_s;
    int key_d;
}   t_ray;


// PARSING |

int parsing(int argc, char **argv, char **envp);

char *read_file(char *filename);



// DISPLAY
int ft_launch(t_ray *ray);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:39:02 by rafaria           #+#    #+#             */
/*   Updated: 2025/03/28 19:34:49 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
// # include "mlx/mlx.h"

# include "../includes/get_next_line.h"
# include "../libft/libft.h"
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

# define WALL '1'
# define AIR '0'

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESCAPE 65307

// # define PLAYER 'W'
// # define REALUP 65362
// # define REALDOWN 65364
// # define REALLEFT 65361
// # define REALRIGHT 65363

typedef struct t_start
{
	char	*file_path;
	char	**map;
	char	**map_table;

	char	player;
	char	*no_txture;
	char	*so_txture;
	char	*we_txture;
	char	*ea_txture;
	int floor_color[3];   // 255,255,255 RGB
	int ceiling_color[3]; // 255,255,255 RGB

}			t_struct;

// -----------------------
// PARSING

int			parsing(int argc, char **argv, char **envp);

char		*read_file(char *filename);
int			check_name_map(char *str);
void		ft_putchar_fd(char c, int fd);
void		display_error(char *str_error);
int			check_input(int argc, char **argv);
int			check_map(t_struct *map, char *file_path);
int			ft_strcmp(char *s1, char *s2);
char		*read_file_into_string(char *file_path);
void		free_struct_map(t_struct *map);

int			check_parsing_direction(t_struct *map, char *map_string,
				char *directions);
int			find_directions(t_struct *map, char **map_table, char *directions);
int			find_every_txture_in_map(t_struct *map, char **map_table,
				char *str);
int			init_struct_map(t_struct *map);
// DISPLAY

// fonctions here

#endif
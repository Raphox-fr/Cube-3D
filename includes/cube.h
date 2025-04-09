/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:15:35 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/09 12:41:18 by rafaria          ###   ########.fr       */
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
# include <limits.h>
# include <math.h>
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
# define MOVE_SPEED 0.05
# define ROT_SPD 0.05

typedef struct s_ray
{
	void	*mlx;
	void	*win;
	char	*axe;

	int		key_l;
	int		key_r;
	int		key_w;
	int		key_a;
	int		key_s;
	int		key_d;

	int		x;
	int		y;
	int		width;
	int		height;
	char	**map;

	int		size_x;
	int		size_y;
	int		posX;
	int		posY;
	int		dirX;
	int		dirY;
	int		planeX;
	int		planeY;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		h;
	double	wallX;
	double	step;
	double	oldDirX;
	double	oldPlaneX;
	int		texx;
	int		texy;
	int		f_color;
	int		c_color;
	// t_struct *map;
}			t_ray;

typedef struct t_start
{
	char	*file_path;
	char	**map;
	char	**map_table;
	char	**map_only;

	int		x_player;
	int		y_player;
	char	player_directions;

	int		x_zero;
	int		y_zero;

	char	*no_txture;
	char	*so_txture;
	char	*we_txture;
	char	*ea_txture;
	int		floor[3];
	int		ceiling[3];
	int		first_line_after_infos;
	int		first_line_map;
	int		hex_floor;
	int		hex_ceiling;

	// BRUT MAP
	char	*ceiling_brut;
	char	*map_brut;
	char	*brut_map_only;

	int		first_line_brut_map;

}			t_struct;

// -----------------------
// PARSING

int			rgb_to_hex(int r, int g, int b);

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

int			check_found_txture(t_struct *map, char *map_string,
				char *directions);
int			find_txture(t_struct *map, char **map_table, char *directions);
int			find_every_txture_in_map(t_struct *map, char **map_table,
				char *str);
int			init_struct_map(t_struct *map);
void		free_split(char **cmd);
int			ft_strlen_cub(const char *str);

int			ft_strlen_spaces_tabs(const char *str);
char		*ft_strdup_pimp(const char *src);

int			count_size_y(int x, char **map_table);
int			count_size_x(int y, char **str);

// Textures
int			check_access_every_txture(t_struct *map);
int			check_access_txture(char *path_txture);
int			check_extension_xpm(char *file_path);
int			check_last_part_txture_found(char *path_txture);
int			check_end_textures(char *str);

// Floor ceiling
int			check_floor_ceiling_in_map(t_struct *map, char **map_table);
int			find_floor_ceiling(t_struct *map, char **map_table,
				char *directions);
int			save_rgb(t_struct *map, char *map_string, char *letter);
int			verify_rgb(t_struct *map, char *map_string, char *letter);
int			check_value_syntax_rgb(char *str);
int			count_characters(char *str, char c);
int			count_number(char *str);
int			verify_syntax_rgb(char *str);

// Check Map Layout

int			check_map_layout(t_struct *map);
int			check_invalid_char_after_first_line_after_infos(t_struct *map);
int			find_player(t_struct *map);
int			find_first_line_map(t_struct *map);

// Verify_map

int			verify_map(t_struct *map);
int			check_udlr(t_struct *map);
int			find_zero(t_struct *map);
int			display_map(t_struct *map);
int			display_map_simple(char **map);

// SPLIT PIMP
int			ft_count_level(const char *str, char set);
char		*ft_strempli_pimp(const char *s, char set);
char		**ft_fill_pimp(char **tab, int countwords, const char *s, char set);
char		**ft_split_pimp(char const *s, char c);

// check newline map

int			check_newline_map(t_struct *map);
int			find_last_elements(t_struct *map);
int			check_no_newline(t_struct *map);

void		replace_space_with_wall(t_struct *map);

int			transform_player_to_zero(t_struct *map);

// DISPLAY
// launch.c

int			ft_launch(t_ray *ray);

// move.c
void		ft_move(t_ray *ray);
void		ft_rotate_left(t_ray *ray);
void		ft_rotate_right(t_ray *ray);

// move_bis.c
void		ft_move_forward(t_ray *ray);
void		ft_move_back(t_ray *ray);
void		ft_move_left(t_ray *ray);
void		ft_move_right(t_ray *ray);

// draw.c
int			ft_draw(t_ray *ray);

// init.c
int			init_struct_ray(t_ray *ray);
int			init_player(t_ray *ray);
void		ft_init_player_N(t_ray *ray);
void		ft_init_player_S(t_ray *ray);
#endif

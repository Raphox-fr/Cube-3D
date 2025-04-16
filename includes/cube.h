/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:15:35 by rafaria           #+#    #+#             */
/*   Updated: 2025/04/16 14:03:23 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../includes/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
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

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65363
# define KEY_RIGHT 65361
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define MOVE_SPEED 0.19
# define MARG 0.15
# define ROT_SPD 0.098

typedef struct s_draw
{
	int			x;
	int			dir;
	int			tex_x;
	double		tex_pos;
	double		step;
}				t_draw;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct t_start
{
	char		*file_path;
	char		**map;
	char		**map_table;
	char		**map_only;
	char		**map_dis;

	int			x_player;
	int			y_player;
	char		player_directions;

	int			x_zero;
	int			y_zero;

	char		*no_txture;
	char		*so_txture;
	char		*we_txture;
	char		*ea_txture;
	int			floor[3];
	int			ceiling[3];
	int			first_line_after_infos;
	int			first_line_map;
	int			hex_floor;
	int			hex_ceiling;
	int			error;
	char		*ceiling_brut;
	char		*map_brut;
	char		*brut_map_only;

	int			err_malloc;

	int			first_line_brut_map;

}				t_struct;

typedef struct s_ray
{
	void		*mlx;
	void		*win;
	char		axe;

	int			key_l;
	int			key_r;
	int			key_w;
	int			key_a;
	int			key_s;
	int			key_d;

	int			x;
	int			y;
	int			width;
	int			height;
	char		**map;
	double		size_x;
	double		size_y;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			h;
	double		step;
	double		olddirx;
	double		oldplanex;
	int			texx;
	int			texy;
	int			f_color;
	int			c_color;
	int			side;
	t_struct	mapp;
	t_img		textures[4];
	t_img		*img;
}				t_ray;

// -----------------------
// PARSING

int				rgb_to_hex(int r, int g, int b);
t_struct		parsing(int argc, char **argv);
char			*read_file(char *filename);
int				check_name_map(char *str);
void			ft_putchar_fd(char c, int fd);
void			display_error(char *str_error);
int				check_input(int argc, char **argv);
int				check_map(t_struct *map, char *file_path);
int				ft_strcmp(char *s1, char *s2);
char			*read_file_into_string(char *file_path);
void			free_struct_map(t_struct *map);
int				check_found_txture(t_struct *map, char *map_string,
					char *directions);
int				find_txture(t_struct *map, char **map_table, char *directions);
int				find_every_txture_in_map(t_struct *map, char **map_table);
void			init_struct_map(t_struct *map);
void			free_split(char **cmd);
int				ft_strlen_cub(const char *str);

int				ft_strlen_spaces_tabs(const char *str);
char			*ft_strdup_pimp(const char *src, t_struct *map);
void			init_v2(t_struct *map);

int				count_size_y(char **map_table);
int				count_size_x(int y, char **str);

// Textures
int				check_access_every_txture(t_struct *map);
int				check_access_txture(char *path_txture);
int				check_extension_xpm(char *file_path);
int				check_last_part_txture_found(char *path_txture);
int				check_end_textures(char *str);

// Floor ceiling
int				check_floor_ceiling_in_map(t_struct *map, char **map_table);
int				find_floor_ceiling(t_struct *map, char **map_table,
					char *directions);
int				save_rgb(t_struct *map, char *map_string, char *letter);
int				verify_rgb(t_struct *map, char *map_string, char *letter);
int				check_value_syntax_rgb(char *str);
int				count_characters(char *str, char c);
int				count_number(char *str);
int				verify_syntax_rgb(char *str);

// Check Map Layout

int				check_map_layout(t_struct *map);
int				check_invalid_char_after_first_line_after_infos(t_struct *map);
int				find_player(t_struct *map);
int				find_first_line_map(t_struct *map);
void			find_player_extension(t_struct *map, int x, int y);

// Verify_map

int				verify_map(t_struct *map);
int				check_udlr(t_struct *map);
int				find_zero(t_struct *map);
int				display_map(t_struct *map);
int				display_map_simple(char **map);

// SPLIT PIMP
int				ft_count_level(const char *str, char set);
char			*ft_strempli_pimp(const char *s, char set);
char			**ft_fill_pimp(char **tab, int countwords, const char *s,
					char set);
char			**ft_split_pimp(char const *s, char c);

// check newline map

int				check_newline_map(t_struct *map);
int				find_last_elements(t_struct *map);
int				check_no_newline(t_struct *map);

void			replace_space_with_wall(t_struct *map);

int				transform_player_to_zero(t_struct *map);

// DISPLAY
// launch.c
int				ft_key_press(int keycode, t_ray *ray);
int				ft_key_release(int keycode, t_ray *ray);
int				close_window(t_ray *ray);
int				ft_loop(t_ray *ray);
int				ft_launch(t_ray *ray);
int				get_map_height(char **map);
int				get_map_width(char **map);
void			init_all_zero(t_ray *ray);
// move.c
void			ft_move(t_ray *ray);
void			ft_rotate_left(t_ray *ray);
void			ft_rotate_right(t_ray *ray);

// move_bis.c
void			ft_move_forward(t_ray *ray);
void			ft_move_back(t_ray *ray);
void			ft_move_left(t_ray *ray);
void			ft_move_right(t_ray *ray);

// ft_xpm_to_img.c
int				ft_xpm_to_img(t_ray *ray);
void			ft_free_textures(t_ray *ray);
int				ft_xpm_to_img_one(t_ray *ray);

// raycsating.c
void			ft_raycast(t_ray *ray);
void			ft_distance(t_ray *ray);
void			ft_dda(t_ray *ray);
void			ft_advance_ray(t_ray *ray);
void			ft_check_hit(t_ray *ray);
void			ft_calc_perp_dist(t_ray *ray);
void			ft_height(t_ray *ray);

// draw.c
void			ft_display(t_ray *ray, int x);
void			ft_draw_floor(t_ray *ray, int x);
void			ft_draw_wall(t_ray *ray, int x, int dir);
void			ft_draw_wall_loop(t_ray *ray, t_draw draw);
void			ft_calc_texture_vars(t_ray *ray, int dir, int *tex_x,
					double *step_tex_pos);
void			ft_draw_ceiling(t_ray *ray, int x);
int				ft_get_texture_direction(t_ray *ray);

// init.c
int				init_struct_ray(t_ray *ray);
int				init_player(t_ray *ray);
void			ft_init_player_n(t_ray *ray);
void			ft_init_player_s(t_ray *ray);
int				init_img(t_ray *ray);

#endif

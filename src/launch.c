/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:15:14 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/14 12:51:09 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"
int get_map_height(char **map)
{
	int i = 0;
	while (map[i])
		i++;
	return (i);
}

int get_map_width(char **map)
{
	int max_width = 0;
	int tmp;
	for (int i = 0; map[i]; i++)
	{
		tmp = strlen(map[i]);
		if (tmp > max_width)
			max_width = tmp;
	}
	return (max_width);
}

void	init_all_zero(t_ray *ray)
{
	ray->img = NULL;
	ray->win = NULL;
	ray->mlx = NULL;
	int i;
	i = 0;
	while (i < 4)
	{
		ray->textures[i].img = NULL;
		i++;
	}
}

int	ft_launch(t_ray *ray)
{
	init_all_zero(ray);
	ray->mlx = mlx_init();
	if (!ray->mlx)
		return (close_window(ray), display_error("mlx\n"),	0);
	if (init_struct_ray(ray) == -1)
		return (close_window(ray), display_error("init_struct_ray\n"), 0 );
	ray->map = ray->mapp.map_only;
	ray->size_y = get_map_height(ray->map);
	ray->size_x = get_map_width(ray->map);
	mlx_get_screen_size(ray->mlx, &ray->width, &ray->height);
	ft_xpm_to_img(ray);
	ray->win = mlx_new_window(ray->mlx, ray->width, ray->height, "Cub3D");
	if (!ray->win)
		return (close_window(ray),display_error("mlx_new_window\n"), 0);
	if (init_img(ray) == -1)
		return (close_window(ray), display_error("init_img\n"), -1);
	mlx_hook(ray->win, 2, 1L << 0, &ft_key_press, ray);
	mlx_hook(ray->win, 3, 1L << 1, &ft_key_release, ray);
	mlx_hook(ray->win, 17, 1L << 17, close_window, ray);
	mlx_loop_hook(ray->mlx, ft_loop, ray);
	mlx_loop(ray->mlx);
	return (1);
}

int	ft_loop(t_ray *ray)
{
	ft_move(ray);
	ft_memset(ray->img->addr, 0, ray->img->width * ray->img->height * sizeof(int));
	ft_raycast(ray);
	mlx_put_image_to_window(ray->mlx, ray->win, ray->img->img, 0, 0);
	return (0);
}

int	ft_key_press(int keycode, t_ray *ray)
{
	if (keycode == KEY_ESC)
		close_window(ray);
	if (keycode == KEY_W || keycode == KEY_UP)
		ray->key_w = 1;
	if (keycode == KEY_A)
		ray->key_a = 1;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		ray->key_s = 1;
	if (keycode == KEY_D)
		ray->key_d = 1;
	if (keycode == KEY_LEFT)
		ray->key_l = 1;
	if (keycode == KEY_RIGHT)
		ray->key_r = 1;
	return (0);
}

int	ft_key_release(int keycode, t_ray *ray)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		ray->key_w = 0;
	if (keycode == KEY_A)
		ray->key_a = 0;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		ray->key_s = 0;
	if (keycode == KEY_D)
		ray->key_d = 0;
	if (keycode == KEY_LEFT)
		ray->key_l = 0;
	if (keycode == KEY_RIGHT)
		ray->key_r = 0;
	return (0);
}

int	close_window(t_ray *ray)
{
	int i;
	
	i = 0;
	free_struct_map(&ray->mapp);
	while (i < 4)
	{
		if (ray->textures[i].img)
			mlx_destroy_image(ray->mlx, ray->textures[i].img);
		i++;
	}
	if (ray->img)
	{
		if (ray->img->img)
			mlx_destroy_image(ray->mlx, ray->img->img);
		free(ray->img);
	}
	if (ray->win)
		mlx_destroy_window(ray->mlx, ray->win);
	if (ray->mlx)
	{
		mlx_destroy_display(ray->mlx);
		free(ray->mlx);
	}
	exit(1);
	return (0);
}




//fonction launch : memset + mlx_put_image_to_window
//ft_xpm_to_img

// if (!ray->img || !ray->img->addr)
// {
// 	printf("Error: img or img->addr is NULL\n");
// 	return (-1);
// }
// if (ray->img->width <= 0 || ray->img->height <= 0)
// {
// 	printf("Error: invalid image size (width=%d, height=%d)\n",
// 		ray->img->width, ray->img->height);
// 	return (-1);
// }
// if (ray->img->bpp <= 0 || ray->img->bpp > 128)
// {
// 	printf("Error: invalid bpp value: %d\n", ray->img->bpp);
// 	return (-1);
// }

// void	print_img_info(t_img *img)
// {
// 	if (!img)
// 	{
// 		printf("Image pointer is NULL\n");
// 		return;
// 	}
// 	printf("Image structure info:\n");
// 	printf("  img pointer      : %p\n", img->img);
// 	printf("  addr pointer     : %p\n", img->addr);
// 	printf("  bits per pixel   : %d\n", img->bpp);
// 	printf("  line length      : %d\n", img->line_length);
// 	printf("  endian           : %d\n", img->endian);
// 	printf("  width            : %d\n", img->width);
// 	printf("  height           : %d\n", img->height);
// }
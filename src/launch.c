/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:15:14 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/09 17:16:24 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_launch(t_ray *ray)
{
	if (init_struct_ray(ray) == -1)
		return (printf("Error\ninit_struct_ray\n"), free_exit(ray),	0);
	if (!ray->mlx)
		return (printf("Error\nmlx\n"), free_exit(ray),	0);
	ft_xpm_to_img(ray); //A FAIRE ***
	if (!ray->win)
	{
		printf("Error\nmlx_new_window\n");
		//ft_free_image(ray);  ***
		mlx_destroy_display(ray->mlx);
		free(ray->mlx);
		return (free_exit(ray), 0);
	}
	mlx_hook(ray->win, 2, 1L << 0, ft_key_press, ray);
	mlx_hook(ray->win, 3, 1L << 1, ft_key_release, ray);
	mlx_hook(ray->win, 17, 1L << 17, close_window, ray);
	mlx_loop_hook(ray->mlx, ft_loop, ray);
	mlx_loop(ray->mlx);
	return (1);
}

void	ft_key_press(int keycode, t_ray *ray)
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
}

void	ft_key_release(int keycode, t_ray *ray)
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
}

int	close_window(t_ray *ray)
{
	mlx_destroy_window(ray->mlx, ray->win);
	exit(0);
	return (0);
}

int	ft_loop(t_ray *ray)
{
	ft_move(ray);
	ft_memset(ray->img->addr, 0, ray->img->width * ray->img->height * sizeof(int));
	ft_raycast(ray);
	mlx_put_image_to_window(ray->mlx, ray->win, ray->img->img, 0, 0);
	return (0);
}

//fonction launch : memset + mlx_put_image_to_window
//ft_xpm_to_img
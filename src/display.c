/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:14:21 by aneumann          #+#    #+#             */
/*   Updated: 2025/04/11 13:10:43 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"
void ft_display(t_ray *ray, int x)
{
    int             y;
    char            *pixel;
    unsigned int    color;
    int             dir;
// Supposons que tes couleurs sont dans mapp.ceiling[3] et mapp.floor[3]
ray->c_color = (ray->mapp.ceiling[0] << 16 | ray->mapp.ceiling[1] << 8 | ray->mapp.ceiling[2]);
ray->f_color = (ray->mapp.floor[0] << 16 | ray->mapp.floor[1] << 8 | ray->mapp.floor[2]);

    // Vérifie que c_color et f_color sont initialisées
    if (!ray->c_color || !ray->f_color)
    {
        printf("Erreur : couleurs sol/plafond non initialisées.\n");
        exit(1);
    }

    // Plafond
    y = 0;
    while (y < ray->drawStart)
    {
        pixel = ray->img->addr + (y * ray->img->line_length + x * (ray->img->bpp / 8));
        *(unsigned int *)pixel = ray->c_color;
        y++;
    }

    // Direction de la texture
    if (ray->side == 1)
        dir = (ray->rayDirY > 0) ? SOUTH : NORTH;
    else
        dir = (ray->rayDirX > 0) ? EAST : WEST;

    // Calcul de wallX
    double wallX = (ray->side == 0)
        ? ray->posY + ray->perpWallDist * ray->rayDirY
        : ray->posX + ray->perpWallDist * ray->rayDirX;
    wallX -= floor(wallX);

    int texX = (int)(wallX * ray->textures[dir].width);
    if ((ray->side == 0 && ray->rayDirX > 0) || (ray->side == 1 && ray->rayDirY < 0))
        texX = ray->textures[dir].width - texX - 1;

    double step = 1.0 * ray->textures[dir].height / ray->lineHeight;
    double texPos = (ray->drawStart - ray->size_y / 2 + ray->lineHeight / 2) * step;

    // Mur
    y = ray->drawStart;
    while (y < ray->drawEnd)
    {
        int texY = (int)texPos;
        if (texY < 0)
            texY = 0;
        if (texY >= ray->textures[dir].height)
            texY = ray->textures[dir].height - 1;
        texPos += step;

        color = *(unsigned int *)(ray->textures[dir].addr
            + (texY * ray->textures[dir].line_length
            + texX * (ray->textures[dir].bpp / 8)));

        pixel = ray->img->addr + (y * ray->img->line_length + x * (ray->img->bpp / 8));
        *(unsigned int *)pixel = color;
        y++;
    }

    // Sol
    while (y < ray->size_y)
    {
        pixel = ray->img->addr + (y * ray->img->line_length + x * (ray->img->bpp / 8));
        *(unsigned int *)pixel = ray->f_color;
        y++;
    }
	printf("\nhello world\n ");
}

// void ft_display(t_ray *ray, int x)
// {
// 	int				y;
// 	char			*pixel;
// 	unsigned int	color;
// 	int				dir;
	
// 	// Supposons que tes couleurs sont dans mapp.ceiling[3] et mapp.floor[3]
// ray->c_color = (ray->mapp.ceiling[0] << 16 | ray->mapp.ceiling[1] << 8 | ray->mapp.ceiling[2]);
// ray->f_color = (ray->mapp.floor[0] << 16 | ray->mapp.floor[1] << 8 | ray->mapp.floor[2]);

// 	// Plafond
// 	y = 0;
// 	while (y < ray->drawStart)
// 	{
// 		pixel = ray->img->addr + (y * ray->img->line_length + x * (ray->img->bpp / 8));
// 		*(unsigned int *)pixel = ray->c_color;
// 		y++;
// 	}

// 	// Direction de la texture
//     if (ray->side == 1)
//     {
//         if (ray->rayDirY > 0)
//             dir = SOUTH;
//         else
//             dir = NORTH;
//     }
//     else
//     {
//         if (ray->rayDirX > 0)
//             dir = EAST;
//         else
//             dir = WEST;
//     }
// 	// Calcul des infos pour la texture murale
// 	double wallX;
//     if (ray->side == 0)
// 	    wallX = ray->posY + ray->perpWallDist * ray->rayDirY;
//     else
// 	    wallX = ray->posX + ray->perpWallDist * ray->rayDirX;
// 	wallX -= floor(wallX);

// 	int texX = (int)(wallX * ray->textures[dir].width); // voir si texX ici et pas structure 
// 	if ((ray->side == 0 && ray->rayDirX > 0) || (ray->side == 1 && ray->rayDirY < 0))
// 		texX = ray->textures[dir].width - texX - 1;

// 	double step = 1.0 * ray->textures[dir].height / ray->lineHeight;
// 	double texPos = (ray->drawStart - ray->size_y / 2 + ray->lineHeight / 2) * step;

// 	// Mur
// 	y = ray->drawStart;
// 	while (y < ray->drawEnd)
// 	{
// 		// int texY = (int)texPos & (ray->textures[dir].height - 1);
// 		int texY = (int)texPos;
// 		if (texY < 0)
// 			texY = 0;
// 		if (texY >= ray->textures[dir].height)
// 			texY = ray->textures[dir].height - 1;
// 		texPos += step;

// 		color = *(unsigned int *)(ray->textures[dir].addr
// 			+ (texY * ray->textures[dir].line_length
// 			+ texX * (ray->textures[dir].bpp / 8)));

// 		pixel = ray->img->addr + (y * ray->img->line_length + x * (ray->img->bpp / 8));
// 		*(unsigned int *)pixel = color;
// 		y++;
// 	}

// 	// Sol
// 	while (y < ray->size_y)
// 	{
// 		pixel = ray->img->addr + (y * ray->img->line_length + x * (ray->img->bpp / 8));
// 		*(unsigned int *)pixel = ray->f_color;
// 		y++;
// 	}
// }

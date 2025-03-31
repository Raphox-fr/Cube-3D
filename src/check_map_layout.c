/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_layout.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:28:52 by rafaria           #+#    #+#             */
/*   Updated: 2025/03/31 18:02:23 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"
// line map valid = '1', '0', 'N', 'S', 'E', 'W', ' '

int check_map_layout(t_struct *map)
{
    if (last_is_map(map) == -1)
        return (-1);
    
    return 1;
}

int last_is_map(t_struct *map)
{
    int i;
    int j;
    int valid;

    j = 0;
    i = count_level(map->map_table) - 1;
    valid = 0;
    printf("Count Level=%d\n", i);
    printf("last string of map table=%s\n", map->map_table[i]);

    while (i > 0)
    {
        j = 0;
        while (map->map_table[i][j] != '\0')
        {
            if (map->map_table[i][j] != '1' && map->map_table[i][j] != '0'  && map->map_table[i][j] != 'N' && map->map_table[i][j] != 'S' &&
            map->map_table[i][j] != 'E' && map->map_table[i][j] != 'W' && map->map_table[i][j] != ' ' && map->map_table[i][j] != '\0' && valid == 0)
            {
                printf("map pas valide la\n");
                return (-1); 
            }
            valid = 1;
            j++;
        }
        i--;
    }
    
    return 1;

    
        
}

// Salut,
// Voici la fonction qui permet de verifie un xpm si un xpm est valide
// (cas ou l'xpm serait erroner) =

t_img	new_sprite(t_struct *game, void *mlx, char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	if (!img.ptr)
		ft_close_free(game);
	return (img);
}

MAP COMMENCER A 0 
EXEMPLE = 
11 111111 11111 11111111
1N1000001000000000001
111111111111111111111
ICI le N se situe a (1,1);


MAP REMPLACEMENT
0 = SOL
1 = MUR
N | S | E | W = PLAYER
' ' | vide = remplacer par 1



Brouillon de code
int check_udlr(t_struct *map)
{
	int x;
	int y;
	int size_x;
	int size_y;

	x = map->x_zero;
	y = map->y_zero;
	
	size_x = count_size_x(y, map->map_only);
	size_y = count_size_y(map->map_only) - 1;
	printf("y %d\n", y);
	printf("size_y = %d\n", size_y);
	
		
		if (x == 0 || y == 0)
			return (-1);
	
	if (y == size_y || x == size_x)
		return (-1);
	
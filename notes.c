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

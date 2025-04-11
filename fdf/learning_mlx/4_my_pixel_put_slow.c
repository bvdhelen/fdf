#include "../mlx_linux/mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>

#define MALLOC_ERROR	1
#define SIDE_LEN		800

typedef unsigned char	byte;

int	encode_rgb(byte red, byte green, byte blue)
{
	return (red << 16 | green << 8 | blue);
}

typedef struct s_var
{
	void	*mlx;
	void	*win;
}	t_var;

void	color_screen(t_var *data, int color)
{
	for (int y = 0; y < SIDE_LEN; y++)
	{
		for (int x = 0; x < SIDE_LEN; x++)
		{
			mlx_pixel_put(data->mlx, //mlx_ptr:
						data->win, //win_ptr:
						x,
						y,
						color);
		}
	}
}

int	f(int keysym, t_var *data)
{
	if (keysym == XK_r)
		color_screen(data, encode_rgb(255, 0, 0)); //color: red: green: blue:
	else if (keysym == XK_g)
		color_screen(data, encode_rgb(0, 0xff, 0)); //color: red: green: blue:
	else if (keysym == XK_b)
		color_screen(data, encode_rgb(0, 0, 0xff)); //color: red: green: blue:
	return (0);
}

int	main (void)
{
	t_var	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, //mlx_ptr:
							SIDE_LEN, //size_x:
							SIDE_LEN, //size_y:
							"My window"); //title:
	mlx_key_hook(data.win, f, &data); //win_ptr: funct_ptr: param:
	mlx_loop(data.mlx); //mlx_ptr:
}

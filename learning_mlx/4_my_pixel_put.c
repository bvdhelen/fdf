#include "../mlx_linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>

#define MALLOC_ERROR	1
#define SIDE_LEN		800

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_var
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_var;

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

void	color_screen(t_var *data, int color)
{
	for (int y = 0; y < SIDE_LEN; y++)
	{
		for (int x = 0; x < SIDE_LEN; x++)
		{
			my_pixel_put(&data->img, //img:
						x,
						y,
						color);
		}
	}
}

int	f(int keysym, t_var *data)
{
	if (keysym == XK_r)
		color_screen(data, 0xff0000); //color:
	else if (keysym == XK_g)
		color_screen(data, 0x00ff00); //color:
	else if (keysym == XK_b)
		color_screen(data, 0x0000ff); //color:
	else if (keysym == XK_Escape)
		exit(1); //status:
	mlx_put_image_to_window(data->mlx, //mlx_ptr:
							data->win, //win_ptr:
							data->img.img_ptr, //img_ptr:
							0, 0); //x: y:
	return (0);
}

int	main(void)
{
	t_var	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, //mlx_ptr:
							SIDE_LEN, //size_x:
							SIDE_LEN, //size_y:
							"My window"); //tittle:
	vars.img.img_ptr = mlx_new_image(vars.mlx, //mlx_ptr:
									SIDE_LEN, //width:
									SIDE_LEN); //height:
	vars.img.img_pixels_ptr = mlx_get_data_addr(vars.img.img_ptr, //img_ptr:
												&vars.img.bits_per_pixel, //bits_per pixel:
												&vars.img.line_len, //size_line:
												&vars.img.endian); //endian:
	printf("Line_len %d <-> SIDE_LEN %d\n" //format:
			"bpp %d\n"
			"endian %d\n", vars.img.line_len, SIDE_LEN, vars.img.bits_per_pixel, vars.img.endian);
	mlx_key_hook(vars.win, //win_ptr:
				f, //funct_ptr:
				&vars); //param:
	mlx_loop(vars.mlx); //mlx_ptr:
}

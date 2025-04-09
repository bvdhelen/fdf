#include "../mlx_linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>

#define MALLOC_ERROR 1
#define SIDE_LEN 1000

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

// Swap endianness for RGB values
int	swap_endian(int color)
{
	unsigned char r = (color >> 16) & 0xFF;
	unsigned char g = (color >> 8) & 0xFF;
	unsigned char b = color & 0xFF;
	return (b << 16 | g << 8 | r);
}

// Paint left half with original color, right half with swapped color
void	color_screen_compare(t_var *data, int color)
{
	int	swapped = swap_endian(color);

	for (int y = 0; y < SIDE_LEN; y++)
	{
		for (int x = 0; x < SIDE_LEN / 2; x++)
			my_pixel_put(&data->img, x, y, color); // left side normal
		for (int x = SIDE_LEN / 2; x < SIDE_LEN; x++)
			my_pixel_put(&data->img, x, y, swapped); // right side swapped
	}
}

int	f(int keysym, t_var *data)
{
	if (keysym == XK_r)
		color_screen_compare(data, 0xFF0000); // red
	else if (keysym == XK_g)
		color_screen_compare(data, 0x00FF00); // green
	else if (keysym == XK_b)
		color_screen_compare(data, 0x0000FF); // blue
	else if (keysym == XK_Escape)
		exit(0);

	mlx_put_image_to_window(data->mlx,
							data->win,
							data->img.img_ptr,
							0, 0);
	return (0);
}

int	main(void)
{
	t_var	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx,
							  SIDE_LEN,
							  SIDE_LEN,
							  "Endian Test Window");

	vars.img.img_ptr = mlx_new_image(vars.mlx,
									 SIDE_LEN,
									 SIDE_LEN);
	vars.img.img_pixels_ptr = mlx_get_data_addr(vars.img.img_ptr,
												&vars.img.bits_per_pixel,
												&vars.img.line_len,
												&vars.img.endian);

	printf("Line_len %d <-> SIDE_LEN %d\n"
		   "bpp %d\n"
		   "endian %d\n",
		   vars.img.line_len, SIDE_LEN,
		   vars.img.bits_per_pixel, vars.img.endian);

	mlx_key_hook(vars.win, f, &vars);
	mlx_loop(vars.mlx);
}

#include "../mlx_linux/mlx.h"
#include <X11/X.h>
#include <unistd.h>
#include <stdio.h>


//MIRA A VER QUE PASA QUE NO FUNCIONA

typedef struct sdata
{
	void	*mlx;
	void	*win;
	int		color;
}	tdata;

int	f(int keysym, tdata *data)
{
	printf("Pressed %d\n", keysym); //format:
	sleep(1); //seconds:
	return (1);
}

int	change_color(tdata *data)
{
	mlx_string_put(data->mlx,
				data->win,
				150,
				150,
				data->color,
				"Color Changing Window!"); //mlx_ptr: win_ptr: x: y: color: string:
	if (data->color == 0xFF0000)
		data->color = 0x00FF00;
	else if (data->color == 0x00FF00)
		data->color = 0x0000FF;
	else
		data->color = 0xFF0000;
	return (0);
}

int	main(void)
{
	tdata	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, //mlx_ptr:
							400, //size_x:
							400, //size_y:
							"Sample Window"); //tittle:
	data.color = 0xFF0000;
	mlx_key_hook(data.win, //win_ptr:
				f, //funct_ptr:
				&data); //param:
	mlx_loop(data.mlx); //mlx_ptr:
	return (0);
}

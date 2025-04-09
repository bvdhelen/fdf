#include "../mlx_linux/mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>

#define MLX_ERROR		1
#define WINDOW_WIDTH	400
#define WINDOW_HEIHT	400

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_data;

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym); //format:
		mlx_destroy_window(data->mlx_ptr, data->win_ptr); //mlx_ptr: win_ptr:
		mlx_destroy_display(data->mlx_ptr); //mlx_ptr:
		free(data->mlx_ptr); //ptr:
		exit(1); //status:
	}
	printf("The %d key has been pressed\n\n", keysym); //format:
	return (0);
}

int	main(void)
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, //mlx_ptr:
								WINDOW_WIDTH, //size_x:
								WINDOW_HEIHT, //size_y:
								"My first window!"); //tittle:
	if (data.win_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr); //mlx_ptr:
		free(data.mlx_ptr); //ptr:
		return (MLX_ERROR);
	}
	mlx_key_hook(data.win_ptr, //win_ptr:
				handle_input, //funct_ptr:
				&data); //param:
	mlx_loop(data.mlx_ptr); //mlx_ptr:
}

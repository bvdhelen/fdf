#include "../mlx_linux/mlx.h"
#include <X11/X.h>
#include <stdio.h>

#define WIN_WIDTH			800
#define WIN_HEIGHT			600

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int	button_press(int button, int x, int y, t_data *data)
{
	if (button == 1)
		printf("Left mouse button pressed at (%d, %d)!\n", x, y); //format:
	else if (button == 3)
		printf("Right mouse button pressed at (%d, %d)!\n", x, y); //format:
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr,
								WIN_WIDTH,
								WIN_HEIGHT,
								"MLX Window"); //mlx_ptr: size_x: size_y: tittle:
	mlx_hook(data.win_ptr, //win_ptr:
			ButtonPress, //x_event:
			ButtonPressMask, //x_mask:
			&button_press, //funct:
			&data); param:
	mlx_loop(data.mlx_ptr); //mlx_ptr:
	return (0);
}

#include "../mlx_linux/mlx.h"
#include <stdlib.h>

#define MALLOC_ERROR	1
#define WIDTH			400
#define HEIGHT			400

int	main(void)
{
	void	*mlx_connection;
	void	*window1;
	void	*window2;

	mlx_connection = mlx_init();
	if (NULL == mlx_connection)
		return (MALLOC_ERROR);
	window1 = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "Window 1"); //mlx_ptr: size_x: size_y: title:
	if (NULL == window1)
	{
		mlx_destroy_display(mlx_connection); //mlx_ptr:
		free(mlx_connection); //ptr:
		return (MALLOC_ERROR);
	}
	window2 = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "Window 2"); //mlx_ptr: size_x: size_y: title:
	if (NULL == window2)
	{
		mlx_destroy_window(mlx_connection, window1); //mlx_ptr: win_ptr:
		mlx_destroy_display(mlx_connection); //mlx_ptr:
		free(mlx_connection); //ptr:
		return (MALLOC_ERROR);
	}
	mlx_loop(mlx_connection); //mlx_ptr:
	return (0);
}

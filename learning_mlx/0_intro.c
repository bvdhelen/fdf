#include <stdlib.h>
#include <stddef.h>
#include "../mlx_linux/mlx.h"

int	main(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (NULL == mlx_ptr)
		return (1);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr); //ptr:
}

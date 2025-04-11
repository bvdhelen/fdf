#include "fdf.h"

int	deal_key(int key, void *data)
{
	(void)data;
	ft_printf("%d", key);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	int	i;
	int	j;

	(void)argc;
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			ft_printf("%3d", data->z_matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

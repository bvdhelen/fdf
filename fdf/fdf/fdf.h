#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "../mlx_linux/mlx.h"

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

void	read_file(char *file_name, t_fdf *data);

#endif

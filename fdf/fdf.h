#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}		t_fdf;

void	read_file(char *file_name, fdf *data);

#endif

#include <fcntl.h> // Para open()
#include <stdio.h> // Para printf() y perror()
#include <unistd.h> // Para close()
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;

	fd1 = open("tests/el_principito.txt", 0);
	if (fd1 == 0)
		return (0);
	fd2 = open("tests/4lines.txt", 0);
	if (fd2 == 0)
		return (0);
	fd3 = open("tests/l3c.txt", 0);
	if (fd3 == 0)
		return (0);
	while ((line = get_next_line(fd1)) || (line = get_next_line(fd2)) || (line = get_next_line(fd3)))
	{
		printf("%s", line);
		free (line);
	}
	close (fd1);
	close (fd2);
	close (fd3);
	return (0);
}

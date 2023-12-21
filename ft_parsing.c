#include "so_long.h"

char		valid_map(int fd)
{
	int		bytes;
	void	*char_check;

	bytes = 1;
	fd = open("/maps/...", O_RDONLY);
	read(fd, char_check, 1);
	return ((char)char_check);
}

int		ft_parsing(int fd, char c)
{
	while (valid_map(fd))
	{
		if ()
	}
}
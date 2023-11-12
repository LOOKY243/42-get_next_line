#include "ft_get_next_line.h"

char	*get_next_line(int fd)
{
	int		fdes;
	int		bytes;
	char	c;

	fdes = open(fd, O_RDONLY);
	if (fdes == -1)
		return (NULL);
	bytes = res(fd, &c, 1);
	while (bytes)
	{
		bytes 
		ft_add_letter(c);
	}
}

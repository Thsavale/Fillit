#include "fillit.h"

int			count(char *path)
{
	int		fd;
	int		ret;
	int		i;
	char	buf[1];

	i = 1;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	ret = read (fd, buf, 1);
	while (ret)
	{
		ret = read(fd, buf, 1);
		i++;
	}
	if (close(fd) == -1)
		return (0);
	return (i);
}

char		*record_file(char *path)
{
	int		fd;
	char	*str;
	int		i;
	char	buf[1];

	i = 0;
	str = malloc(sizeof(char) * (count(path) + 1));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, buf, 1))
	{
		str[i] = buf [0];
		i++;
	}
	str[i] = 0;
	if (close(fd == -1))
		return (0);
	return (str);
}

#include "../includes/cub.h"

int	ft_west(double angle)
{
	if (M_PI / 2 <= angle && angle < M_PI * 1.5)
		return (1);
	else
		return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (1)
	{
		if (*s1 != *s2++)
		{
			--s2;
			if (*s1 < 0 || *s2 < 0)
				return (unsigned char)(*s1 - *s2);
			return (*s1 - *s2);
		}
		if (*s1++ == 0)
			break ;
		if (--n == 0)
			break ;
	}
	return (0);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n--)
		*str++ = c;
	return (s);
}

int	get_next_line(int fd, char **line)
{
	char	buf;
	int		i;

	if (read(fd, 0, 0) == -1)
		return (-1);
	if (!(*line = malloc(MAX_LINE)))
		return (-1);
	i = 0;
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
		{
			(*line)[i] = '\0';
			return (1);
		}
		(*line)[i++] = buf;
	}
	(*line)[i] = '\0';
	return (0);
}
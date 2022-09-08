#include "get_next_line.h"

void	get_after_nl(char *buf)
{
	char	*str;
	int		c;

	c = 0;
	while (buf[c] != '\0' && buf[c] != '\n')
		c++;
	if (buf[c] == '\0' || (buf[c] == '\n' && buf[c + 1] == '\0'))
	{
		ft_zero(buf);
		return ;
	}	
	c++;
	str = ft_strdup(&buf[c]);
	if (!str)
		return ;
	ft_zero(buf);
	c = 0;
	while (str[c] != '\0')
	{
		buf[c] = str[c];
		c++;
	}
	buf[c] = '\0';
	free (str);
}

void	ft_zero(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		buf[i] = '\0';
		i++;
	}
}

char	*join_and_free(char *str, char *buf)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(tmp, buf);
	if (tmp)
		free(tmp);
	return (str);
}

char	*read_file(int file_d)
{
	int			last;
	static char	buf[BUFFER_SIZE + 1];
	char		*ret;

	ret = NULL;
	if (check_nl(buf) == 1)
		return (get_before_nl(buf, 1));
	if (buf[0] != '\0')
		ret = ft_strjoin(ret, buf);
	ft_zero(buf);
	last = read(file_d, buf, BUFFER_SIZE);
	while (last > 0)
	{
		ret = join_and_free(ret, buf);
		if (check_nl(buf) == 1)
		{
			get_after_nl(buf);
			break ;
		}
		ft_zero(buf);
		last = read(file_d, buf, BUFFER_SIZE);
	}
	return (ret);
}

char	*get_next_line(int file_d)
{
	char	*str;

	str = NULL;
	if (file_d < 0 || file_d >= OPEN_MAX || BUFFER_SIZE < 0 || read(file_d, str, 0) < 0)
		return (NULL);
	str = read_file(file_d);
	if (str == NULL)
		return (NULL);
	return (str);
}

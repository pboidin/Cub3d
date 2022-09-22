#include "../includes/cub.h"

int	ft_strisdigit(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	ft_strchr_f(const char *s, int c)
{
	int	count;

	count = 0;
	if (s == 0)
		return (0);
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count);
}

char	*ft_strcpy(char *dst, const char *src)
{
	char *ret;

	ret = dst;
	while ((*dst++ = *src++) != '\0')
		;
	return (ret);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*ret;

	if (!s)
	{
		if (!(ret = malloc(1)))
			return (0);
		*ret = 0;
		return (ret);
	}
	len = ft_strlen(s) + 1;
	if (!(ret = malloc(len * sizeof(char))))
		return (0);
	ft_strcpy(ret, s);
	return (ret);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2++)
		if (*s1++ == 0)
			return (0);
	return (*s1 - *--s2);
}
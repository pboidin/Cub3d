#include "../includes/cub.h"

void	*ft_realloc(void *p, size_t old_s, size_t new_s)
{
	void	*new_p;

	new_p = 0;
	if (new_s == 0)
		free(p);
	else if (!p)
	{
		if (!(new_p = malloc(new_s)))
			return (0);
	}
	else if (new_s <= old_s)
		return (p);
	else if (p && new_s > old_s)
	{
		if (!(new_p = malloc(new_s)))
			return (0);
		ft_memcpy(new_p, p, old_s);
		free(p);
	}
	return (new_p);
}

void	free_str(char **str)
{
	while (*str)
		free(*str++);
}

static int	is_max(long long nb, int len)
{
	int	i;

	i = 0;
	if (len >= 18 && nb >= 922337203685477580)
		i = 1;
	else if (len >= 18 && nb <= -922337203685477580)
		i = 1;
	return (i);
}

long long	ft_atoi(const char *str)
{
	long long	nbr;
	int			i;
	int			len;

	nbr = 0;
	i = 1;
	len = 0;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			i *= -1;
	while ('0' <= *str && *str <= '9')
	{
		if (is_max(nbr, len))
			return (0);
		nbr *= 10;
		nbr += (int)(*str - '0');
		str++;
		len++;
	}
	return (i * nbr);
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
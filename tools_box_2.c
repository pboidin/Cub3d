#include "cub.h"

int	ft_atoi(char *str, int *i)
{
	int	ret;

	ret = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		ret = ret * 10 + (str[*i] - 48);
		(*i)++;
	}
	(*i) += 1;
	return (ret);
}

void	init_var(int *i1, int *i2)
{
	(*i1) = 0;
	(*i2) = 0;
}

#include "../includes/cub.h"

static int	find_length(char *str, char *cstr)
{
	int count;

	count = 0;
	while (*str)
		if (!ft_strchr(cstr, *str++))
			count++;
	return (count);
}

static void	import_str(char **dst, char *src, int start, int end)
{
	if (!(*dst = malloc(((end - start + 1) * sizeof(char)))))
		return ;
	ft_strncpy(*dst, src, end - start);
	(*dst)[end - start] = '\0';
}

char	*ft_strncpy(char *dst, char *src, size_t n)
{
	char *sav_dst;
	char *sav_src;

	sav_dst = dst;
	sav_src = src;
	if (n != 0)
	{
		while (1)
		{
			if ((*sav_dst++ = *sav_src++) == 0)
			{
				while (--n != 0)
					*sav_dst++ = 0;
				break ;
			}
			if (--n == 0)
				break ;
		}
	}
	return (dst);
}

char		**ft_split(char *str, char *cstr)
{
	char	**strs;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (str == 0)
		return (0);
	if (!(strs = malloc((find_length(str, cstr) + 1) * sizeof(char *))))
		return (0);
	while (str[j] != '\0')
	{
		i = j;
		while (!ft_strchr(cstr, str[j]) && str[j] != '\0')
			j++;
		if (i != j)
			import_str(&strs[k++], &str[i], i, j);
		else
			j++;
	}
	strs[k] = 0;
	return (strs);
}
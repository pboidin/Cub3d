#include "../includes/cub.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

int	check_nl(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	if (s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1 && s2)
		return (get_before_nl(s2, 0));
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
	{
		printf("Error\nMalloc Fail.\n");
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (s1[++i] != '\0')
		ret[i] = s1[i];
	j = -1;
	i--;
	while (s2[++j] != '\0' && s2[j] != '\n')
		ret[++i] = s2[j];
	if (s2[j] == '\n')
		ret[++i] = '\n';
	ret[++i] = '\0';
	return (ret);
}

char	*get_before_nl(char *buf, int opt)
{
	int		i;
	char	*ret;

	i = ft_strlen(buf);
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (!ret)
	{
		printf("Error\nMalloc Fail.\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		ret[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		ret[i] = '\n';
		i++;
	}
	ret[i] = '\0';
	if (opt == 1)
		get_after_nl(buf);
	return (ret);
}

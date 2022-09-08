#include "cub.h"

char	*ft_strdup(char *str)
{
	int	i;
	char	*ret;

	i = 0;
	while (str[i] != '\0')
		i++;
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (!ret)
		malloc_err();
	i = 0;
	while (str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

// Remove the NL
char	*delete_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	str[i] = '\0';
	return (str);
}

// Fonction en cas d'erreur sur le malloc
void	malloc_err(void)
{
	printf("Error\nMalloc Error\n");
	exit(EXIT_FAILURE);
}

// Fonciton pour sauter les espaces, plus 1
void	ft_skip_spaces(char *str, int *i)
{
	(*i) += 1;
	skip_spaces(str, i);
}

// Fonction pour sauter les espaces
void	skip_spaces(char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
}

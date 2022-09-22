#include "../includes/cub.h"

char	**ft_tabs_in_spaces(char **str, int wid, int hei)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (++i < hei)
	{
		j = -1;
		len = ft_strlen(str[i]);
		if (len < wid)
			ft_realloc_protec((void **)&str[i], len + 1, wid + 1);
		while (++j < wid)
		{
			if (str[i][j] == '\t')
			{
				ft_memmove(&str[i][j + 4], &str[i][j + 1], len - j + 2);
				ft_strncpy(&str[i][j], "    ", 4);
				len += 4;
			}
			else if (j >= len)
				str[i][j] = ' ';
		}
		str[i][j] = '\0';
	}
	return (str);
}
	

size_t	ft_save_width(char **str) // La largeur de la carte est déterminée par la plus longue chaîne du tableau.
{
	size_t	max_len;
	size_t	len;
	int		i;
	int		j;

	max_len = 0;
	i = 0;
	while (str[i])
	{
		len = 0;
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '\t')
				len += 4;
			else
				len++;
			j++;
		}
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}

char	**ft_save_map(int fd, char *line, int *hei) // Extrait la carte du fichier .cub
{
	int		i;
	char	**str;

	i = 0;
	str = malloc(sizeof(char *)); // l'allocation du premier caractère * pour pouvoir utiliser realloc dans la boucle ** do. boucle do... while (do... while maison mais quand même)
	if (!str)
		exit(EXIT_SUCCESS);
	while (1) // J'ai dû utiliser un do... while à cause du cas limite où nous n'avons qu'une seule ligne dans la carte, j'ai eu des fuites de mémoire Ici, je boucle et stocke dans un tableau de chaînes la carte. Chaque fois que chaque fois que je trouve une nouvelle ligne, j'augmente la taille du tableau d'une unité.
	{
		str = ft_realloc(str,
				(i + 1) * sizeof(char *),
				(i + 2) * sizeof(char *));
		if (!str)
			exit(EXIT_SUCCESS);
		str[i++] = ft_strdup(line);
		free(line);
		if (!get_next_line(fd, &line) && *line == 0)
			break ;
	}
	free(line);
	str[i] = 0;
	*hei = i;
	return (str);
}

void	ft_take_map(int fd, char *line, t_map *map) // Récupère la carte du fichier .cub
{
	map->map = ft_save_map(fd, line, &map->height); // Extrait la carte du fichier .cub sans changer le format et la stocke dans un tableau de chaînes.
	map->width = ft_save_width(map->map); // La carte doit être facile à analyser pour vérifier si elle est valide et pour la rendre. Le changement effectué ici est d'avoir toutes les lignes de la même taille remplies d'espaces lorsque cela est nécessaire.
	map->map = ft_tabs_in_spaces(map->map, map->width, map->height); // Les tabulations sont converties en espaces (1 tabulation = 4 espaces)
}

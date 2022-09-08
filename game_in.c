#include "cub.h"

int		ft_strlen_p(char **src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

void	ft_message(char **src)
{
	int	i;

	i = -1;
	if (src != NULL)
	{
		while (src[++i] != NULL)
			free(src[i]);
		free(src);
	}
	printf("Error\nFile don't match to parse.\n");
	exit(EXIT_FAILURE);
}

int		num_corr_1(char *file, int *i)
{
	int	val;

	val = 0;
	while (file[*i] != '\0')
	{
		if (!(file[*i] >= '0' && file[*i] <= '9'))
		{
			skip_spaces(file, i);
			if (file[*i] == '\n' && file[*i + 1] == '\0')
				break ;
			else
				return (-1);
		}
		val = val * 10 + (file[*i] - 48);
		(*i)++;
	}
	return (val);
}

int		num_corr_2(char *file, char **src, int *i)
{
	int	val;

	val = 0;
	while (file[*i] != '\0')
	{
		if (!(file[*i] >= '0' && file[*i] <= '9')
			&& (file[*i] != ','))
			return (-1);
		if (file[*i] == ',' && file[*i + 1] != '\0')
		{
			(*i)++;
			if (file[*i] == ',')
				ft_message(src);
			break ;
		}
		val = val * 10 + (file[*i] - 48);
		(*i)++;
	}
	return (val);
}

int		num_corr(char *file, char **src, int *i, int key)
{
	int	val;

	val = 0;
	if (key == 1)
	{
		val = num_corr_1(file, i);
		if (val == -1)
			return (0);
	}
	else
	{
		val = num_corr_2(file, src, i);
		if (val == -1)
			return (0);
	}
	if (val >= 0 && val <= 255)
		return (1);
	return (0);
}

void	che_cel_flo_3(char *file, char **src, int *i)
{
	(*i)++;
	skip_spaces(file, i);
	if (file[*i] == ',')
		ft_message(src);
}

int		che_cel_flo_2(char *src, int i)
{
	if (src[i] != 'F' && src[i] != 'C'
		&& (!((src[i] == 'N' && src[i + 1] == '0')
			|| (src[i] == 'S' && src[i + 1] == 'O')
			|| (src[i] == 'W' && src[i + 1] == 'E')
			|| (src[i] == 'E' && src[i + 1] == 'A'))))
		return (1);
	return (0);
}

int		che_cel_flo(char *file, char **src)
{
	int		i;
	int		val;
	char	c;

	write(1, "enter che\n", 10);
	i = 0;
	val = 0;
	c = 'C';
	skip_spaces(file, &i);
	if (che_cel_flo_2(file, i) == 1)
		ft_message(src);
	if (file[i] == 'F')
		c = 'F';
	else if (file[i] != 'C')
		return (0);
	che_cel_flo_3(file, src, &i);
	if (num_corr(file, src, &i, 0) && num_corr(file, src, &i, 0)
			&& num_corr(file, src, &i, 1))
	{
		if (c == 'F')
			return (1);
		else if (c == 'C')
			return (2);
	}
	ft_message(src);
	write(1, "leave che\n", 10);
	return (0);
}

int		checker_text(char *file, char **src)
{
	int	i;

	i = 0;
	skip_spaces(file, &i);
	if (!((file[i] == 'N' && file[i + 1] == 'O')
			|| (file[i] == 'S' && file[i + 1] == 'O')
			|| (file[i] == 'W' && file[i + 1] == 'E')
			|| (file[i] == 'E' && file[i + 1] == 'A'))
			&& file[i] != 'F' && file[i] != 'A')
		ft_message(src);
	if (file[i] == 'C' || file[i] == 'F')
		return (0);
	i += 2;
	skip_spaces(file, &i);
	if (file[i] == '.' && file[i + 1] == '/' && file[i + 2] == '\n')
		return (1);
	ft_message(src);
	return (0);
}

int		text_info(char *file)
{
	int	i;

	i = 0;
	skip_spaces(file, &i);
	if (file[i] == 'N' && file[i + 1] == 'O')
		return (3);
	if (file[i] == 'W' && file[i + 1] == 'E')
		return (2);
	if (file[i] == 'E' && file[i + 1] == 'A')
		return (1);
	return (4);
}


void	game_in2(char *file, char **src, t_mapCheck *ch_game)
{
	write(1, "enter here\n", 11);
	if (che_cel_flo(file, src) == 1)
		ch_game->flo_col += 1;
	else if (che_cel_flo(file, src) == 2)
		ch_game->flo_col += 1;
	else if (checker_text(file, src) && text_info(file) == 1)
		ch_game->ea_tex += 1;
	else if (checker_text(file, src) && text_info(file) == 2)
		ch_game->we_tex += 1;
	else if (checker_text(file, src) && text_info(file) == 3)
		ch_game->no_tex += 1;
	else if (checker_text(file, src) && text_info(file) == 4)
		ch_game->so_tex += 1;
	write(1, "Quit here\n", 10);
}

void	init_game(t_mapCheck *game)
{
	game->cel_col = 0;
	game->flo_col = 0;
	game->no_tex = 0;
	game->so_tex = 0;
	game->we_tex = 0;
	game->ea_tex = 0;
}

int		check_one(t_mapCheck *game)
{
	if (game->cel_col == 1 && game->ea_tex == 1
			&& game->flo_col == 1 && game->no_tex == 1
			&& game->so_tex == 1 && game->we_tex == 1)
		return (1);
	return (0);
}

void	struc_checker(t_mapCheck *game, char **src)
{
	if (!(game->cel_col == 1 && game->flo_col == 1
			&& game->no_tex == 1 && game->so_tex == 1
			&& game->we_tex == 1 && game->ea_tex == 1))
		ft_message(src);
}

char	**ft_dupdouble_p(char **file, int i)
{
	char	**ret;
	int		j;

	j = 0;
	while (file[i][0] == '\n')
		i++;
	ret = malloc(sizeof(char *) * (ft_strlen_p(&file[i]) + 1));
	if (!ret)
	{
		printf("Malloc Error.\n");
		exit(EXIT_FAILURE);
	}
	while (file[i] != NULL)
	{
		ret[j] = ft_strdup(file[i]);
		j++;
		i++;
	}
	ret[j] = NULL;
	return (ret);
}

char    **game_in(char **file)
{
    int			i;
	t_mapCheck	ch_game;

	i = 0;
	init_game(&ch_game);
	while (file[i] != NULL)
	{
		if (file [i][0] != '\n')
			game_in2(file[i], file, &ch_game);
		if (check_one(&ch_game))
			break;
		i++;
	}
	struc_checker(&ch_game, file);
	return (ft_dupdouble_p(file, i + 1));
}
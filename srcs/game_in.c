#include "../includes/cub.h"

int		ft_strlen_p(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

int		num_corr_1(char *str, int *i)
{
	int	ret;

	ret = 0;
	while (str[*i] != '\0')
	{
		if (!(str[*i] >= '0' && str[*i] <= '9'))
		{
			skip_spaces(str, i);
			if (str[*i] == '\n' && str[*i + 1] == '\0')
				break ;
			else
				return (-1);
		}
		ret = ret * 10 + (str[*i] - 48);
		(*i)++;
	}
	return (ret);
}

int		num_corr_2(char *str, char **file, int *i)
{
	int	val;

	val = 0;
	while (str[*i] != '\0')
	{
		if (!(str[*i] >= '0' && str[*i] <= '9')
			&& (str[*i] != ','))
			return (-1);
		if (str[*i] == ',' && str[*i + 1] != '\0')
		{
			(*i)++;
			if (str[*i] == ',')
				ft_message_exit(file);
			break ;
		}
		val = val * 10 + (str[*i] - 48);
		(*i)++;
	}
	return (val);
}

int		num_corr(char *str, char **file, int *i, int key)
{
	int	val;

	val = 0;
	if (key == 1)
	{
		val = num_corr_1(str, i);
		if (val == -1)
			return (0);
	}
	else
	{
		val = num_corr_2(str, file, i);
		if (val == -1)
			return (0);
	}
	if (val >= 0 && val <= 255)
		return (1);
	return (0);	
}

void	che_cel_flo_3(char *str, char **file, int *i)
{
	(*i)++;
	skip_spaces(str, i);
	if (str[*i] == ',')
		ft_message_exit(file);
}

int		che_cel_flo_2(char *str, int i)
{
	if (str[i] != 'F' && str[i] != 'C'
		&& (!((str[i] == 'N' && str[i + 1] == 'O')
				|| (str[i] == 'S' && str[i + 1] == 'O')
				|| (str[i] == 'W' && str[i + 1] == 'E')
				|| (str[i] == 'E' && str[i + 1] == 'A'))))
		return (1);
	return (0);
}

int		che_cel_flo(char *str, char **file)
{
	int		i;
	char	c;

	i = 0;
	c = 'C';
	skip_spaces(str, &i);
	if (che_cel_flo_2(str, i) == 1)
		ft_message_exit(file);
	if (str[i] == 'F')
		c = 'F';
	else if (str[i] != 'C')
		return (0);
	che_cel_flo_3(str, file, &i);
	if (num_corr(str, file, &i, 0) && num_corr(str, file, &i, 0)
			&& num_corr(str, file, &i, 1))
	{
		if (c == 'F')
			return (1);
		else if (c == 'C')
			return (2);
	}
	ft_message_exit(file);
	return (0);
}

int		checker_text(char *str, char **file)
{
	int	i;

	i = 0;
	skip_spaces(str, &i);
	if (!((str[i] == 'N' && str[i + 1] == 'O')
			|| (str[i] == 'S' && str[i + 1] == 'O')
			|| (str[i] == 'W' && str[i + 1] == 'E')
			|| (str[i] == 'E' && str[i + 1] == 'A'))
		&& str[i] != 'F' && str[i] != 'C')
		ft_message_exit(file);
	if (str[i] == 'C' || str[i] == 'F')
		return (0);
	i += 2;
	skip_spaces(str, &i);
	if (str[i] == '.' && str[i + 1] == '/' && str[i + 2] != '\n')
		return (1);
	ft_message_exit(file);
	return (0);
}

int		text_info(char *str)
{
	int	i;

	i = 0;
	skip_spaces(str, &i);
	if (str[i] == 'N' && str[i + 1] == 'O')
		return (3);
	if (str[i] == 'W' && str[i + 1] == 'E')
		return (2);
	if (str[i] == 'E' && str[i + 1] == 'A')
		return (1);
	return (4);
}

void	game_in2(char *str, char **file, t_mapCheck *ch_game)
{
	if (che_cel_flo(str, file) == 1)
		ch_game->flo_col += 1;
	else if (che_cel_flo(str, file) == 2)
		ch_game->cel_col += 1;
	else if (checker_text(str, file) && text_info(str) == 1)
		ch_game->ea_tex += 1;
	else if (checker_text(str, file) && text_info(str) == 2)
		ch_game->we_tex += 1;
	else if (checker_text(str, file) && text_info(str) == 3)
		ch_game->no_tex += 1;
	else if (checker_text(str, file) && text_info(str) == 4)
		ch_game->so_tex += 1;
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

void	struc_checker(t_mapCheck *game, char **file)
{
	if (!(game->cel_col == 1 && game->flo_col == 1
			&& game->no_tex == 1 && game->so_tex == 1
			&& game->we_tex == 1 && game->ea_tex == 1))
		ft_message_exit(file);
}

char	**ft_dup_double_p(char **file, int i)
{
	char	**ret;
	int		j;

	j = 0;
	while (file[i][0] == '\n')
		i++;
	ret = malloc(sizeof(char *) * (ft_strlen_p(&file[i]) + 1));
	if (!ret)
		malloc_err();
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
	return (ft_dup_double_p(file, i + 1));
}
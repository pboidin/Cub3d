#include "../includes/cub.h"

void	get_color(char *str, t_colo *color)
{
	int		i;
	char	**strs;

	if (color->r != -1)
	{
		color->r = -1;
		return ;
	}
	if (ft_strchr_f(str, ',') != 2)
		return ;
	strs = ft_split(str, ",");
	if (!strs)
		return ;
	i = 0;
	while (strs[i] && ft_strisdigit(strs[i]))
		i++;
	if (i == 3)
	{
		color->r = ft_atoi(strs[0]);
		color->g = ft_atoi(strs[1]);
		color->b = ft_atoi(strs[2]);
	}
	free_str(strs);
	free(strs);
}

void	get_texture(char *path, t_text *text)
{
	if (!text->path)
		text->path = ft_strdup(path);
	else
		text->path = 0;
}

void	ft_data(char **str, t_disp *disp)
{
	if (str[0] == 0)
		return ;
	else if (!ft_strcmp(str[0], "NO") && str[1] != 0 && str[2] == 0)
		get_texture(str[1], &disp->NO_tex);
	else if (!ft_strcmp(str[0], "SO") && str[1] != 0 && str[2] == 0)
		get_texture(str[1], &disp->SO_tex);
	else if (!ft_strcmp(str[0], "WE") && str[1] != 0 && str[2] == 0)
		get_texture(str[1], &disp->WE_tex);
	else if (!ft_strcmp(str[0], "EA") && str[1] != 0 && str[2] == 0)
		get_texture(str[1], &disp->EA_tex);
	else if (!ft_strcmp(str[0], "F") && str[1] != 0 && str[2] == 0)
		get_color(str[1], &disp->floor);
	else if (!ft_strcmp(str[0], "C") && str[1] != 0 && str[2] == 0)
		get_color(str[1], &disp->ceilling);
	else if (str[0][0] != '\n')
	{
		printf("Error\nUnknown identifier: %s", str[0]);
		exit(EXIT_SUCCESS);
	}
}

int		is_map(char *line) // Vérifie si la ligne suit le modèle d'une nouvelle ligne
{
	int	check;

	check = 0;
	while (*line)
	{
		if (!ft_strchr("01NSWE \n\t\v\f\r", *line))
			return (0);
		else if (*line == '1')
			check = 1;
		line++;
	}
	return (check);
}

void	ft_init_struct(int fd, t_disp *disp)
{
	char	*line;
	char	**str;

	ft_memset(disp, 0, sizeof(t_disp)); // La structure de la scène doit être initialisée proprement afin que je puisse vérifier plus tard si certains champs ont été laissés vides ou non. Ainsi, j'ai empêche de trouver des valeurs inutiles
	ft_memset(&disp->floor, -1, sizeof(t_colo));
	ft_memset(&disp->ceilling, -1, sizeof(t_colo));
	line = 0;
	while (get_next_line(fd, &line)) // La fonction get_next_line renvoie 1 quand elle a trouvé une nouvelle ligne, 0 quand elle a atteint la fin du fichier et -1 quand une erreur s'est produite
	{
		if (!is_map(line))
		{
			str = ft_split(line, " \n\t\v\f\r");
			ft_data(str, disp);
			free_str(str);
			free(str);
			free(line);
		}
		else
			ft_take_map(fd, line, &disp->map);	
	}
	free(line);
}
#include "cub.h"

int	is_c_or_f(char *str)
{
	int	i;

	i = 0;
	skip_spaces(str, &i); 
	if (str[i] == 'C' || str[i] == 'F')
		return (1);
	return (0);
}

void	init_rgb(info_t *info, char *str)
{
	char	c;
	int	i;

	i = 0;
	skip_spaces(str, &i);
	c = str[i];
	ft_skip_spaces(str, &i);
	if (c == 'C')
	{
		info->CE_col = (int *)malloc(sizeof(int) * 3);
		if (!(info->CE_col))
			malloc_err();
		info->CE_col[0] = ft_atoi(str, &i);
		info->CE_col[1] = ft_atoi(str, &i);
		info->CE_col[2] = ft_atoi(str, &i);
	}
	else if (c == 'F')
	{
		info->FL_col = (int *)malloc(sizeof(int) * 3);
		if (!(info->FL_col))
			malloc_err();
		info->FL_col[0] = ft_atoi(str, &i);
		info->FL_col[1] = ft_atoi(str, &i);
		info->FL_col[2] = ft_atoi(str, &i);
	}
}

int	is_tex(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] =='W' || str[i] == 'E')
			return (1);
		i++; 
	}
	return (0);
}

void	init_tex(info_t *info, char *str)
{
	char	c;
	int	i;

	i = 0;
	skip_spaces(str, &i);
	c = str[i];
	i += 2;
	skip_spaces(str, &i);
	i += 2;
	if (c == 'N')
		info->NO_tex = delete_nl(ft_strdup(&str[i]));
	else if (c == 'S')
		info->SO_tex = delete_nl(ft_strdup(&str[i]));
	else if (c == 'W')
		info->WE_tex = delete_nl(ft_strdup(&str[i]));
	else if (c == 'E')
		info->EA_tex = delete_nl(ft_strdup(&str[i]));
}

void	info_init(info_t *info, char **file)
{
	int	i;

	i = -1;
	while (file[++i] != NULL)
	{
		if (file[i][0] != '\n' && is_c_or_f(file[i]))
			init_rgb(info, file[i]);
		else if (file[i][0] != '\n' && is_tex(file[i]))
			init_tex(info, file[i]);
	}
	i = -1;
	while (file[++i] != NULL)
		free(file[i]);
	free(file);
}

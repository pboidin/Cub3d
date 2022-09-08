#include "cub.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	c;

	c = 0;
	while ((s1[c] != '\0' || s2[c] != '\0') && c < n)
	{
		if (s1[c] != s2[c])
			return (((unsigned char)s1[c] - (unsigned char)s2[c]));
		c++;
	}
	return (0);
}

int		ft_str_len(char *str)
{
	if (*str == '\0')
		return (0);
	return (ft_str_len(str + 1) + 1);
}

void	ft_check_argc(int argc)
{
	if (argc == 1)
		printf("ERROR\nNeed 2 Arguments\n");
	else if (argc > 2)
		printf("ERROR\nToo many Arguments\n");
	if (argc == 1 || argc > 2)
		exit(EXIT_FAILURE);
}

void	ft_check_file_name(char *argv)
{
	int	i;

	i = ft_str_len(argv) - 1;
	if (argv[0] == '.' && argv[1] != '.' && argv[1] != '/')
	{
		printf("ERROR\nAFormat Mistake\n");
		exit(EXIT_FAILURE);
	}
	while (i >= 0)
	{
		if (argv[i] == '.')
		{
			if (ft_strncmp(&argv[i], ".cub", 4) == 0 && argv[i + 4] == '\0')
				return ;
		}
		i--;
	}
	printf("ERROR\n");
	printf("Map needs to ending by a .cub extension");
	exit(EXIT_FAILURE);
}

void	ft_check_permission_file(char *argv)
{
	int	file_d;

	file_d = open(argv, O_RDONLY);
	if (file_d < 0)
	{
		perror(argv);
		printf("ERROR\n");
		exit(EXIT_FAILURE);
	}
}

char	**push_str2(char *tmp)
{
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * 2);
	if (!ret)
		malloc_err();
	ret[0] = ft_strdup(tmp);
	ret[1] = NULL;
	return (ret);
}

char	**push_str(char **ret_val, char *tmp)
{
	char	**ret;
	int		i;

	if (ret_val == NULL)
		return (push_str2(tmp));
	i = 0;
	while (ret_val[i] != NULL)
		i++;
	ret = (char **)malloc(sizeof(char *) * (i + 2));
	if (!ret)
		malloc_err();
	i = 0;
	while (ret_val[i] != NULL)
	{
		ret[i] = ft_strdup(ret_val[i]);
		free(ret_val[i]);
		i++;
	}
	ret[i] = ft_strdup(tmp);
	ret[i + 1] = NULL;
	free(ret_val);
	return (ret);
}

char	**dispatch_file_arr(char *argv)
{
	char	*tmp_char;
	char	**ret;
	int		file_d;

	file_d = open(argv, O_RDONLY);
	ret = NULL;
	tmp_char = NULL;
	tmp_char = get_next_line(file_d);
	while (tmp_char != NULL)
	{
		ret = push_str(ret, tmp_char);
		free(tmp_char);
		tmp_char = get_next_line(file_d);
	}
	return (ret);
}

int		ft_len_ptr(char **ptr)
{
	int	i;

	i = 0;
	while(ptr[i] != NULL)
		i++;
	return (i);
}

void	ft_message_exit(char **ptr)
{
	int	i;

	i = -1;
	if (ptr != NULL)
	{
		while (ptr[++i] != NULL)
			free(ptr[i]);
		free(ptr);
	}
	printf("ERROR\nDFon't succeed to parse.\n");
	exit(EXIT_FAILURE);
}

char	**ft_check_args(int argc, char **argv)
{
	char	**p;

	p = NULL;
	ft_check_argc(argc); // Check if 2 arguments or too many arguments
	ft_check_file_name(argv[1]); // Check if it's a .cub file
	ft_check_permission_file(argv[1]); // Check if we can open the file
	p = dispatch_file_arr(argv[1]); // Dispatch the arguments on a tab
	if (p == NULL || ft_len_ptr(p) < 9) // If ptr is NULL or if len put message exit
		ft_message_exit(p);
	return (p);
}
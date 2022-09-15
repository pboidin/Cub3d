#include "cub.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (1)
	{
		if (*s1 != *s2++)
		{
			--s2;
			if (*s1 < 0 || *s2 < 0)
				return (unsigned char)(*s1 - *s2);
			return (*s1 - *s2);
		}
		if (*s1++ == 0)
			break ;
		if (--n == 0)
			break ;
	}
	return (0);
}

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int		check_extension(char *file, char *extension)
{
	int	len_file;
	int	len_ext;

	len_file = ft_strlen(file);
	len_ext = ft_strlen(extension);
	if (len_file <= len_ext)
		return (0);
	else if (!ft_strncmp(&file[len_file - len_ext], extension, len_ext + 1))
		return (1);
	else
		return (0);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char *saved;

	saved = dest;
	while ((*dest++ = *src++) != '\0')
		;
	return (saved);
}

void	check_arguments(int argc, char **argv)
{
	if ((argc == 2 || argc == 3) && !check_extension(argv[1], ".cub"))
	{
		printf("Error\nScene description file with wrong extention.\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("Error\nWrong number of arguments.\n");
		exit(EXIT_SUCCESS);
	}
}
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

int		check_nl(char *str);
int		ft_strlen(char *str);
char	*get_next_line(int file_d);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*read_file(int file_d);
char	*get_before_nl(char *buf, int opt);
char	*join_and_free(char *ret, char *buf);
void	get_after_nl(char *buf);
void	ft_zero(char *buf);

#endif

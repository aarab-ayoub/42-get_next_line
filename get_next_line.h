
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*read_and_save(int fd, char *store);
char	*save(char *store);
char	*ft_line(char *store);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

#endif
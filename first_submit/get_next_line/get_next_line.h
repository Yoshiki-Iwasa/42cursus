#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
// BUFFER_SIZE は8384698 がmax だということがわかった。
// #define BUFFER_SIZE 8384698
#define MAX_FD 8200
int get_next_line(int fd, char **line);
char	*ft_strdup(const char *src);
size_t		ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int ch);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
#endif
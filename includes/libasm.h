#ifndef LIBASM_H
# define LIBASM_H

ssize_t	ft_read(int fd, char const *buffer, size_t n);
int	ft_strcmp(char const *s1, char const *s2);
char	*ft_strcpy(char *dest, char const *src);
char	*ft_strdup(char const *s);
size_t	ft_strlen(char const *s);
ssize_t	ft_write(int fd, char const *buffer, size_t n);

#endif

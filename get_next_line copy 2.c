#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 33
#endif

size_t	ft_strlcpy(char *d, char *s, int len)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && (int)i < len - 1)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (i);
}

size_t	dist(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_slf(char *dest, char *src, size_t len, int f)
{
	char	*t;

	if (!dest || !src)
		return ((void *) 0);
	if (len == 0 || len >= dist(src, '\0'))
		t = malloc(sizeof(char) * (dist(dest, '\0') + dist(src, '\0') + 1));
	else
		t = malloc(sizeof(char) * (dist(dest, '\0') + len + 2));
	if (!t)
		return ((void *) 0);
	ft_strlcpy(t, dest, dist(dest, '\0') + 1);
	if (len == 0 || len >= dist(src, '\0'))
		ft_strlcpy(t + dist(dest, '\0'), src, dist(src, '\0') + 1);
	else
		ft_strlcpy(t + dist(dest, '\0'), src, len + 1);
	if (f == 1 || f == 3)
	{
		free(dest);
		dest = ((void *)0);
	}
	if (f == 2 || f == 3)
	{
		free(src);
		src = ((void *)0);
	}
	return (t);
}

char *ft_divide(char *line, char *re, char c)
{
	line = ft_slf(line, re, dist(re, c), 1);
	ft_strlcpy(re, &re[dist(re, c) + 1], dist(&re[dist(re, c)], '\0'));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	re[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	line = ft_slf("", "", 0, 0);
	i = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (dist(re, '\n') != dist(re, '\0'))
		return (ft_divide(line, re, '\n'));
	if (re[0] != '\0')
		line = ft_slf(line, re, 0, 1);
	while (i && dist(re, '\n') == dist(re, '\0'))
	{
		i = read(fd, re, BUFFER_SIZE);
		if (i < 0)
			return (NULL);
		re[i] = '\0';
		line = ft_slf(line, re, dist(re, '\n') + 1, 1);
	}
	if (i == 0 && re[0] == '\0' && line[0] == '\0')
		return (NULL);
	ft_strlcpy(re, &re[dist(re, '\n') + 1], dist(&re[dist(re, '\n')], '\0'));
	return (line);
}

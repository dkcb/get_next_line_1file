#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
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

char	*ret(char *d, int code)
{
	if (code < 0)
	{
		free (d);
		d = (void *)0;
		return (d);
	}
	return (d);
}

size_t	dc(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_jsf(char *s1, char *s2, int f)
{
	char	*t;

	if (!s1 || !s2)
		return ((void *) 0);
	t = malloc(
			sizeof(char) * (dc(s1, '\0') + dc(s2, '\0') + 1));
	if (!t)
		return ((void *) 0);
	ft_strlcpy(t, s1, dc(s1, '\0') + 1);
	ft_strlcpy(t + dc(s1, '\0'), s2, dc(s2, '\0') + 1);
	if (f == 1 || f == 3)
	{
		free(s1);
		s1 = ((void *)0);
	}
	if (f == 2 || f == 3)
	{
		free(s2);
		s2 = ((void *)0);
	}
	return (t);
}

char	*get_next_line(int fd)
{
	static char	re[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	line = NULL;
	i = 1;
	line = ft_jsf("", "", 0);
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (ret(line, -1));
	if (dc(re, '\n') != dc(re, '\0'))
	{
		ft_strlcpy(line, re, dc(re, '\n') + 1);
		ft_strlcpy(re, &re[dc(re, '\n') + 1], dc(&re[dc(re, '\n')], '\0'));
		return (line);
	}
	if (re[0] != '\0')
		ft_strlcpy(line, re, dc(re, '\0'));
	while (i && dc(re, '\n') == dc(re, '\0'))
	{
		i = read(fd, re, BUFFER_SIZE);
		if (i < 0)
			return (ret(line, -1));
		re[i] = '\0';
		line = ft_jsf(line, re, 1);
		line[dc(line, '\n') + 1] = '\0';
	}
	if (i == 0 && re[0] == '\0' && line[0] == '\0')
		return (ret(line, -1));
	ft_strlcpy(re, &re[dc(re, '\n') + 1], dc(&re[dc(re, '\n')], '\0'));
	return (line);
}

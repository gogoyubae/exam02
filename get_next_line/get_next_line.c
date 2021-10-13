#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	int len1 = ft_strlen(s1);
	int len2 = ft_strlen(s2);
	char *str;
	char *tmp;

	str = malloc(len1 + len2 + 1);
	tmp = str;
	while (*s1 != '\0')
		*str++ = *s1++;
	while (*s2 != '\0')
		*str++ = *s2++;
	*str = '\0';
	return (tmp);
}

int get_next_line(char **line)
{
	char buf[2];
	char *result;
	int	read_size;

	buf[1] = 0;
	result = malloc(1);
	*result = 0;
	while ((read_size = read(0, buf, 1)))
	{
		if (read_size < 0)
			return (-1);
		if (buf[0] == '\n')
		{
			*line = result;
			return (1);
		}
		else
			result = ft_strjoin(result, buf);
	}
	*line = result;
	return (0);
}

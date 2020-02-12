/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicisner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:45:26 by dicisner          #+#    #+#             */
/*   Updated: 2020/02/12 13:46:04 by dicisner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_if_newline(char *s)
{
	int		len;
	char	*line;
	int		i;

	len = 0;
	i = 0;
	if (s == 0)
		return (0);
	while (s[len] != '\n')
	{
		if (s[len] == 0)
			return (0);
		len++;
	}
	line = malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		line[i] = s[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

int		set_remain(char **s, int fd, char *buf)
{
	int		len;
	char	*news;

	len = 0;
	free(buf);
	while (s[fd][len] != '\n')
		len++;
	news = ft_strdup(s[fd] + len + 1);
	free(s[fd]);
	s[fd] = news;
	return (1);
}

int		return_if_last_line(char **str, char **line, int fd, char *buf)
{
	if ((*line = check_if_newline(str[fd])) != 0)
		return (set_remain(str, fd, buf));
	free(buf);
	if (str[fd] == 0 || str[fd][0] == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
	{
		*line = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = 0;
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	static char	*s[FD_SIZE];
	char		*tmp;
	char		*buf;
	int			n;

	if (fd < 0 || fd >= FD_SIZE || line == 0 || BUFFER_SIZE < 1)
		return (-1);
	buf = malloc(sizeof(char ) * (BUFFER_SIZE + 1));
	while ((n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[n] = 0;
		if (s[fd] != 0)
			tmp = strjoin(s[fd], buf);
		else
			tmp = ft_strdup(buf);
		free(s[fd]);
		s[fd] = ft_strdup(tmp);
		free(tmp);
		if ((*line = check_if_newline(s[fd])) != 0)
			return (set_remain(s, fd, buf));
	}
	if (n < 0)
		return (-1);
	return (return_if_last_line(s, line, fd, buf));
}

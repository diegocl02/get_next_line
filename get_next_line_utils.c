/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicisner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:26:12 by dicisner          #+#    #+#             */
/*   Updated: 2020/02/12 13:56:49 by dicisner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(char *s)
{
	int		len;
	char	*new;
	int		i;

	i = 0;
	len = 0;
	while (s[len] != 0)
		len++;
	new = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	*strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*res;
	int		i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc((len1 + len2 + 1) * sizeof(char));
	i = 0;
	while (*s1)
	{
		res[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		res[i] = *s2;
		s2++;
		i++;
	}
	res[i] = 0;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicisner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:17:51 by dicisner          #+#    #+#             */
/*   Updated: 2020/02/12 13:45:17 by dicisner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define FD_SIZE 4096

int		get_next_line(int fd, char **line);
char	*strjoin(char *s0, char *s2);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);

#endif

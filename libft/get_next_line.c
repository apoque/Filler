/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 13:51:55 by apoque            #+#    #+#             */
/*   Updated: 2018/03/19 14:57:12 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fillstk(char *stkfd, int ret, char *buf)
{
	char	*tp;

	buf[ret] = '\0';
	tp = stkfd;
	if (!(stkfd = ft_strjoin(stkfd, buf)))
		return (0);
	ft_strdel(&tp);
	return (stkfd);
}

char	*ft_retpositif(char *stkfd, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (stkfd[i] != '\n' && stkfd[i])
		i++;
	if (!(*line = ft_strsub(stkfd, 0, i)))
		return (0);
	tmp = stkfd;
	if (stkfd[i] == '\0')
		i--;
	if (!(stkfd = ft_strdup(stkfd + i + 1)))
		return (0);
	ft_strdel(&tmp);
	return (stkfd);
}

int		get_next_line(const int fd, char **line)
{
	t_gnl		s;
	static char	*stk[OPEN_MAX];

	if (read(fd, 0, 0) < 0 || fd > OPEN_MAX || line == 0)
		return (-1);
	ft_bzero(&s, sizeof(t_gnl));
	if (!stk[fd])
		if (!(stk[fd] = ft_strnew(0)))
			return (-1);
	while ((ft_strchr(stk[fd], '\n') == 0) &&
			(s.ret = read(fd, s.buf, BUFF_SIZE)) > 0)
		if (!(stk[fd] = ft_fillstk(stk[fd], s.ret, s.buf)))
			return (-1);
	if (s.ret < 0)
		return (-1);
	if (s.ret == 0 && *stk[fd] == '\0')
	{
		ft_strdel(&stk[fd]);
		return (0);
	}
	if (!(stk[fd] = ft_retpositif(stk[fd], line)))
		return (-1);
	return (1);
}

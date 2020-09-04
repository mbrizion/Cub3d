/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:52:41 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/04 04:23:50 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_join_this(char **line, char *buff)
{
	char	*tmp2;
	char	*tmp;

	tmp = ft_substr(buff, 0, (ft_strchr(buff, '\n') - buff));
	if (!(tmp2 = ft_strjoin(*line, tmp)) || !tmp)
	{
		free(*line);
		free(tmp);
		return (-1);
	}
	free(*line);
	*line = tmp2;
	free(tmp);
	return (1);
}

int		save_buff(char *buff)
{
	if (!ft_strchr(buff, '\n'))
	{
		buff[0] = 0;
		return (0);
	}
	ft_strlcpy(buff, buff + (ft_strchr(buff, '\n') - buff) + 1,
					BUFFER_SIZE + 1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		buff[BUFFER_SIZE + 1] = "";
	int				ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buff, 0))
		return (-1);
	*line = 0;
	free(*line);
	if (!(*line = ft_substr(buff, 0, (ft_strchr(buff, '\n') - buff))))
		return (-1);
	if (!ft_strchr(buff, '\n'))
		while (((ret = read(fd, buff, BUFFER_SIZE)) > 0))
		{
			buff[ret] = '\0';
			if (ft_join_this(line, buff) <= 0)
				return (-1);
			if (ft_strchr(buff, '\n'))
				break ;
		}
	return (save_buff(buff));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:41:23 by olabrecq          #+#    #+#             */
/*   Updated: 2021/06/29 13:45:25 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_clean_line(char *save, char **line, int r)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			break ;
		i++;
	}
	if (i < strlen(save))
	{
		*line = ft_substr(save, 0, i);
		tmp = ft_substr(save, i + 1, ft_strlen(save));
		free(save);
		save = ft_strdup(tmp);
		free(tmp);
	}
	else if (r == 0)
	{
		*line = save;
		save = NULL;
	}
	return (save);
}

static char	*ft_join_cp_save(char *buffer, char *save)
{
	char			*tmp;

	if (save)
	{
		tmp = ft_strjoin(save, buffer);
		free(save);
		save = ft_strdup(tmp);
		free(tmp);
	}
	else
		save = ft_strdup(buffer);
	return (save);
}

static int	world_war_norminette(int fd, char *buffer, int buf_size, int *r)
{
	*r = read(fd, buffer, buf_size);
	return (*r);
}

int	get_next_line(int fd, char **line)
{
	static char		*save_str[4];
	char			buf_str[BUFFER_SIZE + 1];
	int				nb_bytes;

	while ((world_war_norminette(fd, buf_str, BUFFER_SIZE, &nb_bytes)))
	{
		if (nb_bytes == -1)
			return (-1);
		buf_str[nb_bytes] = '\0';
		save_str[fd] = ft_join_cp_save(buf_str, save_str[fd]);
		if (ft_strchr(buf_str, '\n'))
			break ;
	}
	if (nb_bytes <= 0 && !save_str[fd])
	{
		*line = ft_strdup("");
		return (nb_bytes);
	}
	save_str[fd] = ft_clean_line(save_str[fd], line, nb_bytes);
	if (nb_bytes <= 0 && !save_str[fd])
		return (nb_bytes);
	return (1);
}

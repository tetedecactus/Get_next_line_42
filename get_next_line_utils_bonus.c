/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:42:13 by olabrecq          #+#    #+#             */
/*   Updated: 2021/06/29 13:45:03 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char			*s2;
	size_t			l;
	unsigned int	i;

	l = ft_strlen(s1);
	s2 = (char *)malloc(l + 1);
	i = 0;
	if (s2)
	{
		while (s1[i] != '\0' && i < l)
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	else
		return (0);
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*sjoin;

	if (!s1 || !s2)
		return (NULL);
	sjoin = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!sjoin)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		sjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		sjoin[i + j] = s2[j];
		j++;
	}
	sjoin[i + j] = '\0';
	return (sjoin);
}

char	*ft_strchr(const char *str, int ch)
{
	while (*str != ch)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return ((char *) str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*subs;

	i = 0;
	j = 0;
	subs = malloc(sizeof(char) * (len + 1));
	if (!s || !subs)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			subs[j] = s[i];
			j++;
		}
		i++;
	}
	subs[j] = '\0';
	return (subs);
}

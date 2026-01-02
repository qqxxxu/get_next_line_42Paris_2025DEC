/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qixu <qixu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:54:01 by qixu              #+#    #+#             */
/*   Updated: 2025/12/25 22:36:36 by qixu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	slen;

	slen = ft_strlen(s1);
	tmp = malloc(slen + 1);
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, s1, slen + 1);
	return (tmp);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i ++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*tmp;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	tmp = malloc(len_s1 + len_s2 +1);
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, s1, len_s1);
	ft_memcpy(tmp + len_s1, s2, len_s2);
	tmp[len_s1 + len_s2] = '\0';
	return (tmp);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (n == 0)
		return (dst);
	if (dst == NULL || src == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *) src;
	while (n > 0)
	{
		*d = *s;
		d ++;
		s ++;
		n --;
	}
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *)s);
		s ++;
	}
	if ((char) c == '\0')
		return ((char *)s);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qixu <qixu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:53:47 by qixu              #+#    #+#             */
/*   Updated: 2025/12/27 12:39:21 by qixu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*create_stash(char *stash, char *buf)
{
	char	*new_stash;

	if (!stash)
		return (ft_strdup(buf));
	new_stash = ft_strjoin(stash, buf);
	if (!new_stash)
	{
		free (stash);
		stash = NULL;
		return (NULL);
	}
	free (stash);
	stash = NULL;
	return (new_stash);
}

// precondition: stash != NULL && stash[0] != '\0'
static char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i ++;
	if (stash[i] == '\n')
		i ++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, stash, i);
	line [i] = '\0';
	return (line);
}

static char	*trim_stash(char *stash)
{
	char	*find_new_line;
	char	*trimmed_stash;
	char	*start;
	int		i;

	i = 0;
	find_new_line = ft_strchr(stash, '\n');
	if (!find_new_line)
		return (free(stash), stash = NULL, NULL);
	if (*(find_new_line + 1) != '\0')
	{
		start = find_new_line + 1;
		i = ft_strlen(start);
		trimmed_stash = malloc (i + 1);
		if (!trimmed_stash)
			return (free(stash), stash = NULL, NULL);
		ft_memcpy(trimmed_stash, start, i + 1);
		return (free(stash), stash = NULL, trimmed_stash);
	}
	else
		return (free(stash), stash = NULL, NULL);
}

static char	*read_to_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), stash = NULL, NULL);
	bytes = 1;
	while (bytes > 0 && (stash == NULL || ft_strchr(stash, '\n') == NULL))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buf), buf = NULL, NULL);
		buf[bytes] = '\0';
		if (bytes > 0)
		{
			stash = create_stash(stash, buf);
			if (!stash)
				return (free(buf), buf = NULL, NULL);
		}
	}
	return (free(buf), buf = NULL, stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = read_to_stash(fd, stash);
	if (!stash || stash [0] == '\0')
	{
		free (stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = trim_stash(stash);
	return (line);
}

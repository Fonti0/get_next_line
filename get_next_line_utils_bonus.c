/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfontive <dfontive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:59:23 by dfontive          #+#    #+#             */
/*   Updated: 2025/02/03 11:46:07 by dfontive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (0);
	if (c == '\0')
		return (str + ft_strlen(str));
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!str1)
	{
		str1 = malloc(sizeof(char) * 1);
		str1[0] = '\0';
	}
	if (!str2)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
		result[j++] = str1[i++];
	i = 0;
	while (str2[i])
		result[j++] = str2[i++];
	result[j] = '\0';
	free (str1);
	return (result);
}

char	*ft_get_line(int fd, char *str)
{
	ssize_t	i;
	char	*buff;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	i = 1;
	while (ft_strchr(str, '\n') == 0 && i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free (buff);
			free (str);
			return (NULL);
		}
		buff[i] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*ft_cut_line(char *str)
{
	size_t	i;
	char	*final_line;

	if (!str || str[0] == 0)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	final_line = malloc(sizeof(char) * (i + 2));
	if (!final_line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		final_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		final_line[i++] = '\n';
	final_line[i] = '\0';
	return (final_line);
}

char	*ft_remove_past_line(char *line)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	new_str = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!new_str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		new_str[j++] = line[i++];
	new_str[j] = '\0';
	free(line);
	return (new_str);
}

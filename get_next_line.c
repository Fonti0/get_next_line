/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfontive <dfontive@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:52:13 by dfontive          #+#    #+#             */
/*   Updated: 2025/01/29 23:49:41 by dfontive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free (str);
		str = NULL;
		return (NULL);
	}
	str = ft_get_line(fd, str);
	if (!str || !*str)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	line = ft_cut_line(str);
	str = ft_remove_past_line(str);
	return (line);
}

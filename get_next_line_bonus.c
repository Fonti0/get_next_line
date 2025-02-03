/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfontive <dfontive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:41:56 by dfontive          #+#    #+#             */
/*   Updated: 2025/02/03 11:46:56 by dfontive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*str[MAX_FD];

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free (str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	str[fd] = ft_get_line(fd, str[fd]);
	if (!str[fd] || !*str[fd])
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	line = ft_cut_line(str[fd]);
	str[fd] = ft_remove_past_line(str[fd]);
	return (line);
}

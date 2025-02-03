/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfontive <dfontive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:55:29 by dfontive          #+#    #+#             */
/*   Updated: 2025/02/03 11:45:48 by dfontive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif /*BUFFER_SIZE*/

# ifndef MAX_FD
#  define MAX_FD 1024
# endif /*MAX_FD*/

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_get_line(int fd, char *str);
char	*ft_cut_line(char *str);
char	*ft_remove_past_line(char *line);

#endif
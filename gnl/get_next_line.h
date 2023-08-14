/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:39:26 by ctasar            #+#    #+#             */
/*   Updated: 2023/07/24 13:12:23 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 22
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <stdio.h>

char	*get_next_line(int fd);
char	*read_all(int fd, char *all);
char	*get_first_line(char *all);

int		ft_strlen(char *s);
int		check_nl(char *all);
char	*ft_strjoin(char *all, char *buff);

#endif
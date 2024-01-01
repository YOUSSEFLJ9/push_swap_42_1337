/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:30:15 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/01 02:59:07 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# define BUFFER_SIZE 100000
# include "../push_swap.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/* FUNCTIONS */
void	trate_command(t_stack **stack_a, t_stack **stack_b, char *line);
char	*read_and_getline(char *buf, int fd, char *line);
void	free_it(char *str);
char	*ft_strjoin(char *line, char *buf);
void	shift(char *buf, size_t endl);
int		ft_strlen(char *s);
int		ft_strchr_1( char *s, int readit);
char	*get_next_line(int fd);
#endif
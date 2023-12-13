/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:39:33 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/13 21:16:00 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_INT 214748364
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
/* STRUCT */
typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				num;
}	t_stack;

/* FUNCTIONS */
void	error_input(void);
int		ft_atoi(const char *str, int *check);
int		pop_stack(t_stack **stack);
int		push_stack(t_stack **stack, int num);
t_stack	*new_node(int num);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:39:33 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/15 17:52:12 by ymomen           ###   ########.fr       */
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
char	**freet(char **ptr, int i);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
int		ft_strchr(const char *s, int c);
void	error_input(t_stack **stack);
int		ft_atoi(const char *str, t_stack **stack);
/* STACK_ */
int		pop_stack(t_stack **stack);
int		push_stack(t_stack **stack, int num);
t_stack	*new_node(int num);
/* COMMANDS */
void	swap(t_stack **stack);
void	push(t_stack **to, t_stack **from);

#endif
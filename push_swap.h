/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:39:33 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/22 21:56:12 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_INT 214748364

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
/* STRUCT */
typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				num;
	int				index;
	bool			lis;
}	t_stack;

/* FUNCTIONS */
int		LIS(t_stack *stack, int elements);
int		ft_is_sorted(t_stack *stack);
int		ft_init_stack_a(t_stack **stack_a, char **av);
char	**freet(char **ptr, int i);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
int		ft_strchr(const char *s, int c);
int		ft_atoi(const char *str, t_stack **stack);
/* STACK_ */
int		pop_stack(t_stack **stack);
int		push_stack(t_stack **stack, int num);
int		search_wrong_input(char **av);
void	error_and_exit(t_stack **stack);
t_stack	*new_node(int num);
/* COMMANDS */
void	swap(t_stack **stack);
void	push(t_stack **to, t_stack **from);
void	retate(t_stack **stack);
void	rev_retate(t_stack **stack);

#endif
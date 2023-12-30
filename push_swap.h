/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:39:33 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/30 16:23:24 by ymomen           ###   ########.fr       */
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
	struct s_stack	*target;	
	int				num;
	int				index;
	int				price_to_push;
	bool			is_sheap;
	bool			lis;
	bool			uphealf;
}	t_stack;

/* FUNCTIONS */
int		maxm(int a, int b);
char	**freet(char **ptr, int i);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
int		ft_strchr(const char *s, int c);
void	freesplit(t_stack **stack, char **str);
int		ft_atoi(const char *str, t_stack **stack, char **spt);
int		search_wrong_input(char **av);
/* STACK_ */
t_stack	*biggest(t_stack *stack);
t_stack	*smallest(t_stack *stack);
int		set_index(t_stack *stack);
int		ft_is_sorted(t_stack *stack);
int		ft_init_stack_a(t_stack **stack_a, char **av);
int		pop_stack(t_stack **stack);
int		push_stack(t_stack **stack, int num, char **spt);
void	error_and_exit(t_stack **stack);
/* COMMANDS */
void	ss(t_stack **stack_a, t_stack **stack_b, bool print);
void	sb(t_stack **stack_b, bool print);
void	sa(t_stack **stack_a, bool print);
void	pb(t_stack **stack_b, t_stack **stack_a, bool print);
void	pa(t_stack **stack_a, t_stack **stack_b, bool print);
void	rr(t_stack **stack_a, t_stack **stack_b, bool print);
void	rb(t_stack **stack_b, bool print);
void	ra(t_stack **stack_a, bool print);
void	rrr(t_stack **stack_a, t_stack **stack_b, bool print);
void	rrb(t_stack **stack_b, bool print);
void	rra(t_stack **stack_a, bool print);
/* ALGO */
void	sort_three(t_stack **stack);
void	sort_sheapest_target(t_stack **stack_a,
			t_stack **stack_b, t_stack *sheap);
void	lis(t_stack *stack, int elements);
void	push_if_not_lis(t_stack **stack_a, t_stack **stack_b, int length);
void	sort_4_20(t_stack **stack_a, t_stack **stack_b, int length);
void	push_swap(t_stack **stack_a, t_stack **stack_b, int length);

#endif
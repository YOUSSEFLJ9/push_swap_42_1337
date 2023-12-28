/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:30:17 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/27 16:19:41 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack **stack)
{
	t_stack	*a;
	t_stack	*b;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	a = *stack;
	b = (*stack)->next;
	a->next = b->next;
	b->next = a;
	a->prev = b;
	b->prev = NULL;
	*stack = b;
	return (1);
}

void	sa(t_stack **stack_a, bool print)
{
	swap(stack_a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, bool print)
{
	swap(stack_b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, bool print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		write(1, "ss\n", 3);
}

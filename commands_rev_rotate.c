/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rev_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:25:36 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/24 18:41:44 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*rev_rot;
	t_stack	*iter;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	rev_rot = *stack;
	iter = *stack;
	while (iter->next->next)
		iter = iter->next;
	rev_rot = iter->next;
	iter->next = NULL;
	rev_rot->prev = NULL;
	rev_rot->next = *stack;
	*stack = rev_rot;
}

void	rra(t_stack **stack_a, bool print)
{
	rev_rotate(stack_a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, bool print)
{
	rev_rotate(stack_b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, bool print)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (print)
		write(1, "rrr\n", 4);
}

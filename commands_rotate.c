/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:33:01 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/25 17:51:03 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack **stack)
{
	t_stack	*rot;
	t_stack	*iter;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	rot = *stack;
	iter = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	while (iter->next)
		iter = iter->next;
	iter->next = rot;
	rot->next = NULL;
	rot->prev = iter;
	return (1);
}

void	ra(t_stack **stack_a, bool print)
{
	if (rotate(stack_a) && print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, bool print)
{
	if (rotate(stack_b) && print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, bool print)
{
	if ((rotate(stack_a) ||rotate(stack_b)) && print)
		write(1, "rr\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:25:36 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/15 23:48:04 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*a;
	t_stack	*b;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	a = *stack;
	b = (*stack)->next;
	a->next = b->next;
	b->next = a;
	a->prev = b;
	b->prev = NULL;
	*stack = b;
}

void	push(t_stack **to, t_stack **from)
{
	t_stack	*from_frst;

	if (!from || !(*from))
		return ;
	from_frst = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	if (!*to)
	{
		from_frst->next = NULL;
		from_frst->prev = NULL;
		*to = from_frst;
	}
	else
	{
		from_frst->next = *to;
		(*to)->prev = from_frst;
		*to = from_frst;
	}
}

void	retate(t_stack **stack)
{
	t_stack	*rot;
	t_stack	*iter;

	if (!stack || !*stack || !(*stack)->next)
		return ;
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
}

void	rev_retate(t_stack **stack)
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

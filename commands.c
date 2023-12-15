/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:25:36 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/15 20:48:37 by ymomen           ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:31:41 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/25 17:46:44 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack **to, t_stack **from)
{
	t_stack	*from_frst;

	if (!from || !(*from))
		return (0);
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
	return (1);
}

void	pa(t_stack **stack_a, t_stack **stack_b, bool print)
{
	if (push(stack_a, stack_b) && print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_b, t_stack **stack_a, bool print)
{
	if (push(stack_b, stack_a) && print)
		write(1, "pb\n", 3);
}

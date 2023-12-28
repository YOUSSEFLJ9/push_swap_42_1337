/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_algo_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:57:01 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/28 15:37:21 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	loop_rr(t_stack **stack_a, t_stack **stack_b, t_stack *sheap)
{
	while (*stack_a != sheap->target && *stack_b != sheap)
		rr(stack_a, stack_b , 1);
	set_index(*stack_a);
	set_index(*stack_b);
}

static void	loop_rrr(t_stack **stack_a, t_stack **stack_b, t_stack *sheap)
{
	while (*stack_a != sheap->target && *stack_b != sheap)
		rrr(stack_a, stack_b , 1);
	set_index(*stack_a);
	set_index(*stack_b);
}
static void loop_ra_rra(t_stack **stack_a, t_stack *target)
{
	while(*stack_a != target)
	{
		if(target->uphealf)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
}

static void loop_rb_rrb(t_stack **stack_b, t_stack *sheap)
{
	while(*stack_b != sheap)
	{
		if(sheap->uphealf)
			rb(stack_b, 1);
		else
			rrb(stack_b, 1);
	}
}

void	sort_sheapest_target(t_stack **stack_a,t_stack **stack_b, t_stack *cheap)
{
	if ((cheap->uphealf) && (cheap->target->uphealf))
		loop_rr(stack_a, stack_b, cheap);
	else if (!(cheap->uphealf) && !(cheap->target->uphealf))
		loop_rrr(stack_a, stack_b, cheap);
	loop_rb_rrb(stack_b, cheap);	
	loop_ra_rra(stack_a, cheap->target);
	pa(stack_a, stack_b, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_algo_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:57:01 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/25 22:22:36 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	loop_rr(t_stack **stack_a, t_stack **stack_b, t_stack *sheap)
{
	while (stack_a != sheap->target && stack_b != sheap)
		rr(stack_a, stack_b , 1);
		
	
}

static void	loop_rrr(t_stack **stack_a, t_stack **stack_b, t_stack *sheap)
{
	while (stack_a != sheap->target && stack_b != sheap)
		rrr(stack_a, stack_b , 1);
	
	
}

void	sort_sheapest_target(t_stack **stack_a,t_stack **stack_b, t_stack *sheap)
{
	if ((sheap->upofmed) && (sheap->target->upofmed))
		loop_rr(stack_a, stack_b, sheap);
	else if (!(sheap->upofmed) && !(sheap->target->upofmed))
		loop_rr(stack_a, stack_b, sheap);

		pa(stack_b, stack_b, 1);
}
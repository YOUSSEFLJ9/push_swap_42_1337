/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:41:42 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/28 15:48:02 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	t_stack	*big;

	big = biggest(*stack_a);
	if (*stack_a == big)
		ra(stack_a, 1);
	else if ((*stack_a)->next == big)
		rra(stack_a, 1);
	if ((*stack_a)->num > (*stack_a)->next->num)
		sa(stack_a, 1);
}

void	sort_4_20(t_stack **stack_a, t_stack **stack_b, int length)
{
	t_stack	*tmp;
	
	tmp = *stack_a;
	while(length-- > 3)
	{
		pb(stack_b, &tmp, 1);
	}
	if (!ft_is_sorted(tmp))
		sort_three(&tmp);
	*stack_a = tmp;
}


int nextbegger(int index_a, t_stack *stack_a)
{
	int		nextbig;
	
	while(index_a != stack_a->index)
		stack_a = stack_a->next;
	nextbig = stack_a->num;
	while (stack_a)
	{
		if (stack_a->num > nextbig)
		{
			return (stack_a->num);		
		}
		stack_a = stack_a->next;
	}
	return(nextbig);		
}

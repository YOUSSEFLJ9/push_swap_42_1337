/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:41:42 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/27 19:39:52 by ymomen           ###   ########.fr       */
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
void min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
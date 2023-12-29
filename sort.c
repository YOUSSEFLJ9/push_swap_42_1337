/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:41:42 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/29 14:25:09 by ymomen           ###   ########.fr       */
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
	int		med;

	tmp = *stack_a;
	med = (biggest(*stack_a)->num + smallest(*stack_a)->num) / 2;
	while (length-- > 3)
	{
		pb(stack_b, &tmp, 1);
		set_index(*stack_a);
		if ((*stack_b)->num >= med)
			rb(stack_b, 1);
	}
	if (!ft_is_sorted(tmp))
		sort_three(&tmp);
	*stack_a = tmp;
}

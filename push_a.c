/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:50:14 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/24 22:11:43 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_if_not_lis(t_stack **stack_a, t_stack **stack_b, int length)
{
	t_stack	*tmp;
	int		i;


	i = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->lis == 0)
			pb(b, &tmp, 1);
		else
		{
			if (i < length)
				ra(&tmp, 1);
			else
				break ;
		}
		i++;
	}
	*a = tmp;
}

void	set_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*smallbigger;
	t_stack *tmp_a;

	smallbigger = stack_a;
	while (stack_b)
	{
		while (stack_a)
		{
			if (stack_b->num < )
		}
		stack_b = stack_b->next;
	}
}
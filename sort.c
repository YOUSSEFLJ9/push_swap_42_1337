/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:41:42 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/24 19:55:38 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*big;

	big = biggest(*stack);
	if (*stack == big)
		ra(stack, 1);
	else if ((*stack)->next == big)
		rra(stack, 1);
	if ((*stack)->num > (*stack)->next->num)
		sa(stack, 1);
}

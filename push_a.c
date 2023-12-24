/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:50:14 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/24 20:22:12 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_notlis(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		len;
	int		i;

	len = 0;
	i = 0;
	tmp = *a;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	tmp = *a;
	while (tmp)
	{
		if (tmp->lis == 0)
			push(b, &tmp, "pb\n", 3);
		else
		{
			if (i < len)
				retate(&tmp, "ra\n", 3);
			else
				break ;
		}
		i++;
	}
	*a = tmp;
}

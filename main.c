/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:24:51 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/29 13:29:42 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vv(void)
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		length;

	stack_a = NULL;
	stack_b = NULL;
	length = 0;
	//atexit(vv);
	if (ac == 1)
		return (0);
	length = ft_init_stack_a(&stack_a, ++av);
	if (!ft_is_sorted(stack_a))
	{
		if (length == 2)
			sa(&stack_a, 1);
		else if (length == 3)
			sort_three(&stack_a);
		else
			push_swap(&stack_a, &stack_b, length);
	}
	while (stack_a)
		pop_stack(&stack_a);
	return (0);
}

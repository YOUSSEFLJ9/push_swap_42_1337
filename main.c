/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:24:51 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/24 20:19:09 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vv(void)
{
	system("leaks stack");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		elements;

	stack_a = NULL;
	stack_b = NULL;
	elements = 0;
	atexit(vv);
	if (ac != 1)
		elements = ft_init_stack_a(&stack_a, ++av);
	if (ft_is_sorted(stack_a))
		printf("the stack sorted :)\n");
	else
	{
		printf("the stack not yet sorted :(\n");
		if (elements == 2)
			sa(&stack_a, 1);
		else if (elements == 3)
			sort_three(&stack_a);
		else
		{
			set_index(stack_a);
			lis(stack_a, elements);
			push_notlis(&stack_a, &stack_b);
		}
	}
	printf("the number of elemnt is :%d\n", elements);
	if (ft_is_sorted(stack_a))
		printf("the stack now is sorted :)\n");
	while (stack_a)
	{
		printf("|%d|--->", stack_a->num);
		pop_stack(&stack_a);
	}
	printf("\n_______________________________\n");
	while (stack_b)
	{
		printf("|%d|--->", stack_b->num);
		pop_stack(&stack_b);
	}
	return (0);
}

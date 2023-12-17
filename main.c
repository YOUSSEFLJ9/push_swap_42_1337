/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:24:51 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/16 19:59:42 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	//atexit(vv);
	if (ac != 1)
		elements = ft_init_stack_a(&stack_a, ++av);
	if (ft_is_sorted(stack_a))
		printf("the stack is sorted :)\n");
	else
		printf("the stack not yet sorted :(\n");
	printf("the number of elemnt is :%d\n", elements);
	while (stack_a)
	{
		printf("%d\n", stack_a->num);
		pop_stack(&stack_a);
	}
	return (0);
}

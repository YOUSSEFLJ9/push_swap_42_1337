/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:24:51 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/26 16:12:35 by ymomen           ###   ########.fr       */
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
	int		length;

	stack_a = NULL;
	stack_b = NULL;
	length = 0;
	//atexit(vv);
	if (ac == 1)
		return (0);
	length = ft_init_stack_a(&stack_a, ++av);
	if (ft_is_sorted(stack_a))
		exit(0);
	else
	{
		if (length == 2)
			sa(&stack_a, 1);
		else if (length == 3)
			{
				sort_three(&stack_a);
			}
		else
		{	
			lis(stack_a, length);
			push_swap(&stack_a, &stack_b, length);
		}
	}
	//printf("the number of elemnt is :%d\n", length);
	// if (ft_is_sorted(stack_a))
	// 	printf("the stack now is sorted :)\n");
	while (stack_a)
	{
		// printf("|%d|--->|%s|", stack_a->num, stack_a->upofmed ? "yes" : "no");
		pop_stack(&stack_a);
	}
	// printf("\n_______________________________\n");
	while (stack_b)
	{
		// printf("|%d|--->|%s|", stack_b->num, stack_b->upofmed ? "yes" : "no");
		pop_stack(&stack_b);
	}
	return (0);
}

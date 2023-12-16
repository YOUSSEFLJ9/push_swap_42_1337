/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacka.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:31:16 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/16 19:22:45 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_init_stack_a(t_stack **stack_a, char **av)
{
	int		i;
	char	**splited;
	int		elements;

	elements = 0;
	if (!search_wrong_input(av))
		error_and_exit(stack_a, "Error\n", 255);
	while (*av)
	{
		i = 0;
		if (ft_strchr(*av, ' ') && --elements)
		{
			splited = ft_split(*av, ' ');
			if (!splited)
				error_and_exit(stack_a, "not enough space to allocate\n", 1);
			while (splited[i])
				push_stack(stack_a, ft_atoi(splited[i++], stack_a));
			freet(splited, i);
		}
		else
			push_stack(stack_a, ft_atoi(*av, stack_a));
		elements += i + 1;
		av++;
	}
	return (elements);
}

int	ft_is_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (stack && stack->next)
	{
		stack = stack->next;
		if (current->num > stack->num)
			return (0);
		current = stack;
	}
	return (1);
}

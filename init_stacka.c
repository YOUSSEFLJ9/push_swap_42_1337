/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacka.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:31:16 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/16 16:19:12 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_stack **stack_a, char **av)
{
	int		i;
	char	**splited;

	if (!search_wrong_input(av))
		error_input(stack_a);
	while (*av)
	{
		i = 0;
		if (ft_strchr(*av, ' '))
		{
			splited = ft_split(*av, ' ');
			if (!splited)
			{
				write(2, "not enough space to allocate\n", 30);
				exit(EXIT_FAILURE);
			}
			while (splited[i])
				push_stack(stack_a, ft_atoi(splited[i++], stack_a));
			freet(splited, i);
		}
		else
			push_stack(stack_a, ft_atoi(*av, stack_a));
		av++;
	}
}

bool	is_sorted(t_stack *stack)
{
	(void)stack;
	return (1);
}

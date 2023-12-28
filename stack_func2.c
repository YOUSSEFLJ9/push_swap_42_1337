/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:31:16 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/28 18:40:59 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_wrong_input(char **av)
{
	int	i;
	int	j;

	i = 0;
	if (!av || !av[i])
		return (0);
	while (av[i])
	{
		j = 0;
		if (!ft_isdigit(av[i][j]) && !av[i][j + 1])
			return (0);
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] && av[i][j] != '+'
				&& av[i][j] != '-' && av[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_init_stack_a(t_stack **stack_a, char **av)
{
	int		i;
	char	**splited;
	int		elements;

	elements = 0;
	if (!search_wrong_input(av))
		error_and_exit(stack_a);
	while (*av)
	{
		i = 0;
		if (ft_strchr(*av, ' ') && --elements)
		{
			splited = ft_split(*av, ' ');
			if (!splited)
				error_and_exit(stack_a);
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

	if (!stack)
		return (1);
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

int	set_index(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp->index = i++;
		tmp = tmp->next;
	}
	while (stack)
	{
		if ((stack->index) <= (i / 2))
			stack->uphealf = 1;
		else
			stack->uphealf = 0;
		stack = stack->next;
	}
	return (i);
}

void	error_and_exit(t_stack **stack)
{
	while (pop_stack(stack) == 1)
		;
	write(2, "Error\n", 6);
	exit (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:42:07 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/13 22:58:57 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*new_node(int num)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->num = num;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	push_stack(t_stack **stack, int num)
{
	t_stack	*new;

	new = new_node(num);
	if (stack && new)
	{
		new->next = *stack;
		new->prev = NULL;
		if (*stack)
			(*stack)->prev = new;
		*stack = new;
		return (1);
	}
	return (-1);
}

int	pop_stack(t_stack **stack)
{
	t_stack	*next;

	next = *stack;
	if (!stack || !*stack)
		return (-1);
	*stack = next->next;
	free(next);
	return (1);
}

void	error_input(void)
{
	write(1, "error input!\n", 13);
	exit (-1);
}

void vv(void)
{
	system("leaks stack");
}

int	main(int ac, char **av)
{
	t_stack	*stack;
	int		check_nb;
	int		numb;

	atexit(vv);
	stack = NULL;
	check_nb = 1;
	if (ac != 1)
	{
		av++;
		while (*av)
		{
			numb = ft_atoi(*av, &check_nb);
			push_stack(&stack, numb);
			av++;
		}
	}
	while (stack)
	{
		printf("%d\n", stack->num);
		pop_stack(&stack);
	}
	return (0);
}

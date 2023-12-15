/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:42:07 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/16 00:02:57 by ymomen           ###   ########.fr       */
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
	t_stack	*head;

	head = *stack;
	while (head)
	{
		if (head->num == num)
			error_input(stack);
		head = head->next;
	}
	new = new_node(num);
	head = *stack;
	if (!new || !stack)
		return (-1);
	else if (!*stack)
		*stack = new;
	else
	{
		while (head->next)
			head = head->next;
		head->next = new;
		new->prev = head;
	}
	return (1);
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

void	error_input(t_stack **stack)
{
	while (pop_stack(stack) == 1)
		;
	write(1, "error input!\n", 13);
	exit (-1);
}

void	vv(void)
{
	system("leaks stack");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	char	**splited;

	//atexit(vv);
	stack_a = NULL;
	stack_b = NULL;
	if (ac != 1)
	{
		av++;
		while (*av)
		{
			i = 0;
			if (ft_strchr(*av, ' '))
			{
				splited = ft_split(*av, ' ');
				if (!splited)
					error_input(&stack_a);
				while (splited[i])
					push_stack(&stack_a, ft_atoi(splited[i++], &stack_a));
				freet(splited, i);
			}
			else
				push_stack(&stack_a, ft_atoi(*av, &stack_a));
			av++;
		}
	}
	swap(&stack_a);
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	retate(&stack_a);
	retate(&stack_b);
	rev_retate(&stack_a);
	rev_retate(&stack_b);
	swap(&stack_a);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);

	while (stack_a)
	{
		printf("%d\n", stack_a->num);
		pop_stack(&stack_a);
	}
	printf("\n--------------\n");
	while (stack_b)
	{
		printf("%d\n", stack_b->num);
		pop_stack(&stack_b);
	}
	return (0);
}

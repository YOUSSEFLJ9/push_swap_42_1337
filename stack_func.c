/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:42:07 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/24 18:47:12 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*new_node(int num)
{
	t_stack		*node;
	static int	index;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->num = num;
	node->next = NULL;
	node->prev = NULL;
	node->index = index;
	node->lis = 0;
	index++;
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
			error_and_exit(stack);
		head = head->next;
	}
	new = new_node(num);
	head = *stack;
	if (!new)
		error_and_exit(stack);
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

t_stack	*smallest(t_stack *stack)
{
	t_stack	*smallest_one;
	int		i;

	if (!stack)
		return (NULL);
	i = 2147483647;
	while (stack)
	{
		if (stack->num < i)
		{
			i = stack->num;
			smallest_one = stack;
		}
		stack = stack->next;
	}
	return (smallest_one);
}

t_stack	*biggest(t_stack *stack)
{
	t_stack	*biggest_one;
	int		i;

	if (!stack)
		return (NULL);
	i = -2147483648;
	while (stack)
	{
		if (stack->num > i)
		{
			i = stack->num;
			biggest_one = stack;
		}
		stack = stack->next;
	}
	return (biggest_one);
}

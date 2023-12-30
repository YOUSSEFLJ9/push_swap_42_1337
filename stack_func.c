/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:42:07 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/30 16:24:21 by ymomen           ###   ########.fr       */
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
	node->is_sheap = 0;
	node->index = index;
	node->lis = 0;
	node->price_to_push = 0;
	index++;
	return (node);
}

int	push_stack(t_stack **stack, int num, char **spt)
{
	t_stack	*new;
	t_stack	*head;

	head = *stack;
	while (head)
	{
		if (head->num == num)
			freesplit(stack, spt);
		head = head->next;
	}
	head = *stack;
	new = new_node(num);
	if (!new)
		freesplit(stack, spt);
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
		if (stack->num >= i)
		{
			i = stack->num;
			biggest_one = stack;
		}
		stack = stack->next;
	}
	return (biggest_one);
}

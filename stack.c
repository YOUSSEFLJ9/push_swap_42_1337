/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:42:07 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/16 16:30:24 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(2, "Error\n", 7);
	exit (255);
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:42:07 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/16 19:20:22 by ymomen           ###   ########.fr       */
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
			error_and_exit(stack, "Error\n", 255);
		head = head->next;
	}
	new = new_node(num);
	head = *stack;
	if (!new)
		error_and_exit(stack, "not enough space to allocate\n", 1);
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

void	error_and_exit(t_stack **stack, char *msg, int exitstatus)
{
	while (pop_stack(stack) == 1)
		;
	write(2, msg, ft_strlen(msg));
	exit (exitstatus);
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

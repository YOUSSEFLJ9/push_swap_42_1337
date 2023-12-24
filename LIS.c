/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:38:00 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/24 17:50:15 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	max_arr(int *ptr, int len)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	while (i < len)
	{
		if (max < ptr[i])
			max = ptr[i];
		i++;
	}
	return (max);
}

static void	belong_to_lis(t_stack *stack_a, int *ptr, int len)
{
	int		max;
	t_stack	*node;

	max = max_arr(ptr, len);
	while (--len >= 0)
	{
		if (ptr[len] == max && max >= 0)
		{
			node = stack_a;
			while (node)
			{
				if (node->index == len)
				{
					node->lis = 1;
					break ;
				}
				node = node->prev;
			}
			max--;
		}
	}
}

static int	*arrlis(int len, t_stack **stack)
{
	int		*ptr;
	int		i;

	ptr = (int *) malloc(len * sizeof(int));
	i = 0;
	if (!ptr)
		error_and_exit(stack);
	while (i < len)
		ptr[i++] = 1;
	return (ptr);
}

void	lis(t_stack *stack, int elements)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		j;
	int		*ptr;

	ptr = arrlis(elements, &stack);
	a = stack;
	b = stack;
	i = 0;
	while ((++i < elements) && a->next)
	{
		a = a->next;
		b = stack;
		j = 0;
		while (i > j)
		{
			if (b->num < a->num)
				ptr[i] = max(ptr[j] +1, ptr[i]);
			b = b->next;
			j++;
		}
	}
	belong_to_lis(a, ptr, elements);
	free(ptr);
}

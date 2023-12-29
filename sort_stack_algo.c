/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:50:14 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/29 13:30:50 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_if_not_lis(t_stack **stack_a, t_stack **stack_b, int length)
{
	int		i;
	int		med;

	i = 0;
	lis(*stack_a, length);
	med = (biggest(*stack_a)->num + smallest(*stack_a)->num) / 2;
	while (*stack_a)
	{
		if ((*stack_a)->lis == 0)
		{
			pb(stack_b, stack_a, 1);
			set_index(*stack_a);
			if ((*stack_b)->num >= med)
				rb(stack_b, 1);
		}
		else
		{
			if (i < length)
				ra(stack_a, 1);
			else
				break ;
		}
		i++;
	}
}

static void	set_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp_a;
	t_stack	*target;
	int		samllestbig_nb;

	while (stack_b)
	{
		samllestbig_nb = 2147483647;
		tmp_a = stack_a;
		while (tmp_a)
		{
			if (stack_b->num < tmp_a->num && tmp_a->num < samllestbig_nb)
			{
				samllestbig_nb = tmp_a->num;
				target = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (samllestbig_nb == 2147483647)
			stack_b->target = smallest(stack_a);
		else
			stack_b->target = target;
		stack_b = stack_b->next;
	}
}

static void	set_price(t_stack *stack_a, t_stack *stack_b)
{
	int	la;
	int	lb;

	la = set_index(stack_a);
	lb = set_index(stack_b);
	while (stack_b)
	{
		stack_b->price_to_push = stack_b->index;
		if (!stack_b->uphealf)
			stack_b->price_to_push = lb - stack_b->index;
		if (stack_b->target->uphealf)
			stack_b->price_to_push += stack_b->target->index;
		else
			stack_b->price_to_push += la - stack_b->target->index;
		stack_b = stack_b->next;
	}
}

static t_stack	*set_sheapest(t_stack *stack_b)
{
	int		cheap;
	t_stack	*the_one;

	cheap = 2147483647;
	the_one = NULL;
	while (stack_b)
	{
		if (stack_b->price_to_push < cheap)
		{
			the_one = stack_b;
			cheap = stack_b->price_to_push;
		}
		stack_b = stack_b->next;
	}
	if (the_one)
		the_one->is_sheap = 1;
	return (the_one);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int length)
{
	t_stack	*cheap;
	t_stack	*petit;

	if (length < 20)
		sort_4_20(stack_a, stack_b, length);
	else
		push_if_not_lis(stack_a, stack_b, length);
	while (*stack_b)
	{
		set_target(*stack_a, *stack_b);
		set_price(*stack_a, *stack_b);
		cheap = set_sheapest(*stack_b);
		sort_sheapest_target(stack_a, stack_b, cheap);
	}
	set_index(*stack_a);
	petit = smallest(*stack_a);
	while (*stack_a != petit)
	{
		if (petit->uphealf)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
}

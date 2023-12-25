/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:50:14 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/25 22:01:52 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_if_not_lis(t_stack **stack_a, t_stack **stack_b, int length)
{
	t_stack	*tmp;
	int		i;
	int		l;


	i = 0;
	l = length;
	tmp = *stack_a;
	while (tmp && l-- > 3)
	{
		if (tmp->lis == 0)
			pb(stack_b, &tmp, 1);
		else
		{
			if (i < length && tmp->next)
				ra(&tmp, 1); 
			else
				break ;
		}
		i++;
	}
	if (!ft_is_sorted(tmp))
		sort_three(&tmp);
	*stack_a = tmp;
}

void	set_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *tmp_a;
	int		samllestbig_nb;

	while (stack_b)
	{
		samllestbig_nb = 2147483647; 
		tmp_a = stack_a;
		while (tmp_a)
		{
			if (stack_b->num < tmp_a->num && tmp_a->num < samllestbig_nb)
			{
				samllestbig_nb =  tmp_a->num;
				stack_a->target = tmp_a;			
			}
			tmp_a = tmp_a->next;
		}
		if ( samllestbig_nb == 2147483647)
			stack_b->target = smallest(stack_a);
		stack_b = stack_b->next;
	}
}

void set_price(t_stack *stack_a, t_stack *stack_b)
{
	int	la;
	int lb;
	
	la = set_index(stack_a);
	lb = set_index(stack_b);
	while(stack_b)
	{
		stack_b->price_to_push = stack_b->index;
		if(!(stack_b->upofmed))
			stack_b->price_to_push = lb - stack_b->index;
		if(stack_b->target->upofmed)
			stack_b->price_to_push += stack_b->target->index;
		else
			stack_b->price_to_push += la - stack_b->target->index;
		stack_b = stack_b->next;
	} 
}

t_stack *set_sheapest(t_stack *satck_b)
{
	int sheap;
	t_stack *the_one;

	sheap = 2147483647;
	the_one = NULL;
	while( satck_b)
	{
		if (satck_b->price_to_push < sheap)
		{
			the_one = satck_b;
			sheap =satck_b->price_to_push;
		}
		satck_b->next;
	}
	if(the_one)
		the_one->is_sheap = 1;
	return (the_one);
	
}
void push_swap(t_stack **stack_a, t_stack **stack_b, int length)
{
	t_stack	*sheap;

	if(length == 5)
		sort_5();
	else
	{
		push_if_not_lis(stack_a, stack_b, length);
		while(stack_b)
		{
			set_target(*stack_a, *stack_b);
			set_price(stack_a,stack_b);
			sheap = set_sheapest(stack_b);
			sort_sheapest_target(stack_a, stack_b, sheap);
			
		}
	}
	
}
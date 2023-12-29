/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trate_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:51:13 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/29 23:17:02 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_strcmp(char *str, char *s2)
{
	int	i;
	
	i = 0;
	while(str[i] || s2[i])
	{
		if (str[i] != s2[i])
			return (str[i] - s2[i]);
		i++;
	}
	return (0);
}

static int	check_valid(t_stack **stack_a,t_stack **stack_b,char *line)
{
	if (!line || !line[0])
		return (0);
	if (ft_strcmp(line, "sa\n") == 0)
		return (sa(stack_a, 0), 1);
	else if (ft_strcmp(line, "sb\n") == 0)
		return (sb(stack_b, 0), 1);
	else if (ft_strcmp(line, "ss\n") == 0)
		return (ss(stack_a, stack_b, 0), 1);
	else if (ft_strcmp(line, "pa\n") == 0)
		return (pa(stack_a, stack_b, 0), 1);
	else if (ft_strcmp(line, "pb\n") == 0)
		return (pb(stack_b ,stack_a , 0), 1);
	else if (ft_strcmp(line, "ra\n") == 0)
		return (ra(stack_a, 0), 1);
	else if (ft_strcmp(line, "rb\n") == 0)
		return (rb(stack_b, 0), 1);
	else if (ft_strcmp(line, "rr\n") == 0)
		return (rr(stack_a, stack_b, 0), 1);
	else if (ft_strcmp(line, "rra\n") == 0)
		return (rra(stack_a, 0), 1);
		else if (ft_strcmp(line, "rrb\n") == 0)
		return (rrb(stack_b, 0), 1);
	else if (ft_strcmp(line, "rrr\n") == 0)
		return (rrr(stack_a, stack_b, 0), 1);
	return (0);
}
		
void	trate_command(t_stack **stack_a,t_stack **stack_b, char *line)
{
	if (check_valid(stack_a, stack_b, line) == 0)
	{
		free(line);
		while (pop_stack(stack_b) == 1)
		;
		error_and_exit(stack_a);
	}
	else
		free(line);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:27:02 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/29 23:11:06 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	// stack_a = NULL;
	// stack_b = NULL;
	if (ac == 1)
		return (0);
	ft_init_stack_a(&stack_a, ++av);
	line = get_next_line(0);
	while ((line))
	{
		trate_command(&stack_a, &stack_b, line);
		line = get_next_line(0);
	}
	if (!line)
	{
		if (ft_is_sorted(stack_a) && stack_b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	while (stack_a)
		pop_stack(&stack_a);
	while (stack_b)
		pop_stack(&stack_b);
	return (0);
}

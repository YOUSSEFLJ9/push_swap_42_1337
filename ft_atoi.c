/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:26:46 by ymomen            #+#    #+#             */
/*   Updated: 2023/12/30 17:03:34 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, t_stack **stack, char **spt)
{
	int	sing;
	int	nb;
	int	i;

	nb = 0;
	sing = 1;
	i = 0;
	if (!str || !str[0])
		freesplit(stack, spt);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sing *= -1;
	}
	while (str[i] >= 48 && str[i] <= 57 && str[i])
	{
		if (nb > MAX_INT || (nb == MAX_INT && str[i] - '0' > 7 && sing == 1)
			|| (nb == MAX_INT && str[i] - '0' > 8))
			freesplit(stack, spt);
		nb = (nb * 10) + (str[i++] - 48);
	}
	if ((nb == 0 && !(str[0] == '0' || str[0] == '+' || str[0] == '-'))
		|| (!ft_isdigit(str[i]) && str[i]))
		freesplit(stack, spt);
	return (nb * sing);
}

void	freesplit(t_stack **stack, char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	freet(str, i);
	error_and_exit(stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:56:25 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/06 23:14:09 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_movecost	find_min_cost(t_movecost *costs, int size)
{
	t_movecost	min_cost;
	int			i;

	min_cost = costs[0];
	i = 1;
	while (i < size)
	{
		if (costs[i].total_cost < min_cost.total_cost)
			min_cost = costs[i];
		i++;
	}
	return (min_cost);
}

int	abs_diff(int a, int b)
{
	int	result;

	result = 0;
	if (a > b)
		result = a - b;
	else
		result = b - a;
	return (result);
}

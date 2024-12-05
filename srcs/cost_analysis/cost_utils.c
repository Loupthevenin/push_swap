/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:56:25 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/05 21:38:46 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

MoveCost	find_min_cost(MoveCost *costs, int size)
{
	MoveCost	min_cost;
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

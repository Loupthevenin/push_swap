/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:56:25 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/05 09:08:38 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	move_on_top_a(int *tab_a, int size_a, int index)
{
	int	i;

	i = 0;
	if (index < 0 || index >= size_a)
		return ;
	if (size_a / 2 >= index)
	{
		while (i < index)
		{
			rule_rotate_a(tab_a, size_a, 1);
			i++;
		}
	}
	else
	{
		while (i < size_a - index)
		{
			rule_reverse_rotate_a(tab_a, size_a, 1);
			i++;
		}
	}
}

void	move_on_top_b(int *tab_b, int size_b, int index)
{
	int	i;

	i = 0;
	if (index < 0 || index >= size_b)
		return ;
	if (size_b / 2 >= index)
	{
		while (i < index)
		{
			rule_rotate_b(tab_b, size_b, 1);
			i++;
		}
	}
	else
	{
		while (i < size_b - index)
		{
			rule_reverse_rotate_b(tab_b, size_b, 1);
			i++;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:31:45 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/05 14:22:16 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_cost_info	init_info(int i)
{
	t_cost_info	result;

	result.index_a = -1;
	result.index_b = -1;
	result.size_a = -1;
	result.size_b = -1;
	result.i = i;
	return (result);
}

void	update_info(Arrays *tabs, int target, t_cost_info *cost_info,
		int is_closest_smaller)
{
	cost_info->index_a = cost_info->i;
	cost_info->index_b = target;
	cost_info->size_a = *tabs->size_a;
	cost_info->size_b = *tabs->size_b;
	if (!is_closest_smaller)
	{
		cost_info->index_a = target;
		cost_info->index_b = cost_info->i;
		cost_info->size_a = *tabs->size_b;
		cost_info->size_b = *tabs->size_a;
	}
}

void	update_costs(MoveCost *costs, t_cost_info *cost_info)
{
	if (cost_info->index_a <= cost_info->size_a / 2)
		costs[cost_info->i].cost_a = cost_info->index_a;
	else
		costs[cost_info->i].cost_a = cost_info->size_a - cost_info->index_a;
	if (cost_info->index_b <= cost_info->size_b / 2)
		costs[cost_info->i].cost_b = cost_info->index_b;
	else
		costs[cost_info->i].cost_b = cost_info->size_b - cost_info->index_b;
	costs[cost_info->i].index_a = cost_info->index_a;
	costs[cost_info->i].index_b = cost_info->index_b;
	costs[cost_info->i].total_cost = costs[cost_info->i].cost_a
		+ costs[cost_info->i].cost_b;
}

// Attention je ne prends pas en compte les rr rrr
// qui peuvent gagner enormement en cost;
void	calculate_costs(t_node *current_list, Arrays *tabs, MoveCost *costs,
		int is_closest_smaller)
{
	t_node		*current;
	int			target;
	int			i;
	t_cost_info	cost_info;

	current = current_list;
	i = 0;
	while (current)
	{
		cost_info = init_info(i);
		target = find_target(tabs, current->value, is_closest_smaller);
		update_info(tabs, target, &cost_info, is_closest_smaller);
		update_costs(costs, &cost_info);
		current = current->next;
		i++;
	}
}

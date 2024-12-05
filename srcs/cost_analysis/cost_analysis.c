/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:57:02 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/05 21:36:27 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	cost_analysis(Arrays *tabs, int is_closest_smaller)
{
	MoveCost	*costs;
	MoveCost	min_cost;
	t_node		*current_list;
	int			size_current;

	size_current = *tabs->size_a;
	if (!is_closest_smaller)
		size_current = *tabs->size_b;
	costs = (MoveCost *)malloc(sizeof(MoveCost) * size_current);
	if (!costs)
		return ;
	if (is_closest_smaller)
		current_list = tab_to_list(tabs->tab_a, *tabs->size_a);
	else
		current_list = tab_to_list(tabs->tab_b, *tabs->size_b);
	if (!current_list)
		return (free(costs));
	calculate_costs(current_list, tabs, costs, is_closest_smaller);
	min_cost = find_min_cost(costs, size_current);
	move_on_top(tabs, min_cost.index_a, min_cost.index_b);
	free(costs);
	free_list(current_list);
}

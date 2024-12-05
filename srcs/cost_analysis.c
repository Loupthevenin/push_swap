/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:57:02 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/05 10:48:31 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_target(Arrays *tabs, int value, int is_closest_smaller)
{
	int	i;
	int	index_target;
	int	check;
	int	diff;
	int	current_diff;
	int	*tab;
	int	size;

	i = 0;
	diff = -1;
	index_target = -1;
	tab = tabs->tab_b;
	size = *tabs->size_b;
	if (!is_closest_smaller)
	{
		tab = tabs->tab_a;
		size = *tabs->size_a;
	}
	while (i < size)
	{
		check = value > tab[i];
		current_diff = value - tab[i];
		if (!is_closest_smaller)
		{
			check = value < tab[i];
			current_diff = tab[i] - value;
		}
		if (check && (diff == -1 || current_diff < diff))
		{
			diff = current_diff;
			index_target = i;
		}
		i++;
	}
	if (index_target == -1)
	{
		if (is_closest_smaller)
			return (ft_max(tab, size));
		else
			return (ft_min(tab, size));
	}
	return (index_target);
}

// Attention je ne prends pas en compte les rr rrr qui peuvent gagner enormement en cost;
void	calculate_costs(t_node *current_list, Arrays *tabs, MoveCost *costs,
		int is_closest_smaller)
{
	t_node	*current;
	int		i;
	int		target;
	int		index_a;
	int		index_b;
	int		size_a;
	int		size_b;

	i = 0;
	current = current_list;
	while (current)
	{
		target = find_target(tabs, current->value, is_closest_smaller);
		index_a = i;
		index_b = target;
		size_a = *tabs->size_a;
		size_b = *tabs->size_b;
		if (!is_closest_smaller)
		{
			index_a = target;
			index_b = i;
			size_a = *tabs->size_b;
			size_b = *tabs->size_a;
		}
		if (index_a <= index_a / 2)
			costs[i].cost_a = index_a;
		else
			costs[i].cost_a = size_a - index_a;
		if (index_b <= index_b / 2)
			costs[i].cost_b = index_b;
		else
			costs[i].cost_b = size_b - index_b;
		costs[i].index_a = index_a;
		costs[i].index_b = index_b;
		costs[i].total_cost = costs[i].cost_a + costs[i].cost_b;
		current = current->next;
		i++;
	}
}

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
	/* ft_printf("index a phase 1 :%d\n", min_cost.index_a); */
	/* ft_printf("index b phase 1 :%d\n", min_cost.index_b); */
	move_on_top_a(tabs->tab_a, *tabs->size_a, min_cost.index_a);
	move_on_top_b(tabs->tab_b, *tabs->size_b, min_cost.index_b);
	free(costs);
	free_list(current_list);
}

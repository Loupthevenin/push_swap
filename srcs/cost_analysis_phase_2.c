/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis_phase_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:55:18 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/04 18:45:45 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_target_phase_2(int *tab, int size, int value)
{
	int	i;
	int	j;
	int	diff;

	i = 0;
	diff = -1;
	j = -1;
	while (i < size)
	{
		if (value < tab[i])
		{
			if (diff == -1 || diff > tab[i] - value)
			{
				diff = tab[i] - value;
				j = i;
			}
		}
		i++;
	}
	if (j == -1)
		return (ft_min(tab, size));
	return (j);
}

// Attention je ne prends pas en compte les rr rrr qui peuvent gagner enormement en cost;
void	calculate_costs_phase_2(t_node *b_list, int *tab_a, int size_a,
		MoveCost *costs)
{
	t_node	*current;
	int		i;
	int		j;
	int		size_b;

	current = b_list;
	size_b = count_size_node(current);
	i = 0;
	while (current)
	{
		j = find_target_phase_2(tab_a, size_a, current->value);
		if (i <= size_b / 2)
			costs[i].cost_b = i;
		else
			costs[i].cost_b = size_b - i;
		if (j <= size_a / 2)
			costs[i].cost_a = j;
		else
			costs[i].cost_a = size_a - j;
		costs[i].index_a = j;
		costs[i].index_b = i;
		costs[i].total_cost = costs[i].cost_a + costs[i].cost_b;
		current = current->next;
		i++;
	}
}

void	cost_analysis_phase_2(int *tab_a, int *tab_b, int size_a, int size_b)
{
	MoveCost	*costs;
	MoveCost	min_cost;
	t_node		*b_list;

	costs = (MoveCost *)malloc(sizeof(MoveCost) * size_b);
	if (!costs)
		return ;
	b_list = tab_to_list(tab_b, size_b);
	if (!b_list)
	{
		free(costs);
		return ;
	}
	calculate_costs_phase_2(b_list, tab_a, size_a, costs);
	min_cost = find_min_cost(costs, size_b);
	ft_printf("index b phase 2 :%d\n", min_cost.index_b);
	ft_printf("index a phase 2 :%d\n", min_cost.index_a);
	move_on_top_b(tab_b, size_b, min_cost.index_b);
	move_on_top_a(tab_a, size_a, min_cost.index_a);
	free(costs);
	free_list(b_list);
}

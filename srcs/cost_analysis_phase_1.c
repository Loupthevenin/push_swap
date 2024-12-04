/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis_phase_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:57:02 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/04 18:38:52 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_target_phase_1(int *tab, int size, int value)
{
	int	i;
	int	j;
	int	diff;

	i = 0;
	diff = -1;
	j = -1;
	while (i < size)
	{
		if (value > tab[i])
		{
			if (diff == -1 || diff > value - tab[i])
			{
				diff = value - tab[i];
				j = i;
			}
		}
		i++;
	}
	if (j == -1)
		return (ft_max(tab, size));
	return (j);
}

// Attention je ne prends pas en compte les rr rrr qui peuvent gagner enormement en cost;
void	calculate_costs_phase_1(t_node *a_list, int *tab_b, int size_b,
		MoveCost *costs)
{
	t_node	*current;
	int		i;
	int		j;
	int		size_a;

	current = a_list;
	size_a = count_size_node(current);
	i = 0;
	while (current)
	{
		j = find_target_phase_1(tab_b, size_b, current->value);
		if (i <= size_a / 2)
			costs[i].cost_a = i;
		else
			costs[i].cost_a = size_a - i;
		if (j <= size_b / 2)
			costs[i].cost_b = j;
		else
			costs[i].cost_b = size_b - j;
		costs[i].index_a = i;
		costs[i].index_b = j;
		costs[i].total_cost = costs[i].cost_a + costs[i].cost_b;
		current = current->next;
		i++;
	}
}

void	cost_analysis_phase_1(int *tab_a, int *tab_b, int size_a, int size_b)
{
	MoveCost	*costs;
	MoveCost	min_cost;
	t_node		*a_list;

	costs = (MoveCost *)malloc(sizeof(MoveCost) * size_a);
	if (!costs)
		return ;
	a_list = tab_to_list(tab_a, size_a);
	if (!a_list)
	{
		free(costs);
		return ;
	}
	calculate_costs_phase_1(a_list, tab_b, size_b, costs);
	min_cost = find_min_cost(costs, size_a);
	ft_printf("index a phase 1 :%d\n", min_cost.index_a);
	ft_printf("index b phase 1 :%d\n", min_cost.index_b);
	move_on_top_a(tab_a, size_a, min_cost.index_a);
	move_on_top_b(tab_b, size_b, min_cost.index_b);
	free(costs);
	free_list(a_list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:57:02 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/03 19:23:17 by ltheveni         ###   ########.fr       */
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

int	find_target(int *tab, int size, int value)
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
void	calculate_costs(t_node *a_list, int *tab_b, int size_b, MoveCost *costs)
{
	t_node	*current;
	int		i;
	int		j;
	int		size_a;

	current = a_list;
	size_a = 0;
	while (current)
	{
		size_a++;
		current = current->next;
	}
	current = a_list;
	i = 0;
	while (current)
	{
		j = find_target(tab_b, size_b, current->value);
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

void	cost_analysis(int *tab_a, int *tab_b, int size_a, int size_b)
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
	calculate_costs(a_list, tab_b, size_b, costs);
	min_cost = find_min_cost(costs, size_a);
	ft_printf("index a :%d\n", min_cost.index_a);
	ft_printf("index b :%d\n", min_cost.index_b);
	move_on_top_a(tab_a, size_a, min_cost.index_a);
	move_on_top_b(tab_b, size_b, min_cost.index_b);
	free(costs);
	free_list(a_list);
}

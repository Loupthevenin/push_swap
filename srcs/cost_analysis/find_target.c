/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:05:22 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/06 23:14:09 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_params(t_arrays *tabs, int is_closest_smaller, int **tab,
		int *size)
{
	if (is_closest_smaller)
	{
		*tab = tabs->tab_b;
		*size = *tabs->size_b;
	}
	else
	{
		*tab = tabs->tab_a;
		*size = *tabs->size_a;
	}
}

int	calculate_diff(int value, int tab_value, int is_closest_smaller)
{
	if (is_closest_smaller)
		return (value - tab_value);
	else
		return (tab_value - value);
}

int	check_closest(int value, int tab_value, int is_closest_smaller)
{
	if (is_closest_smaller)
		return (value > tab_value);
	else
		return (value < tab_value);
}

int	find_index(int *tab, int size, int value, int is_closest_smaller)
{
	int	i;
	int	index_target;
	int	diff;
	int	current_diff;
	int	check;

	i = 0;
	diff = -1;
	index_target = -1;
	while (i < size)
	{
		check = check_closest(value, tab[i], is_closest_smaller);
		current_diff = calculate_diff(value, tab[i], is_closest_smaller);
		if (check && (diff == -1 || current_diff < diff))
		{
			diff = current_diff;
			index_target = i;
		}
		i++;
	}
	return (index_target);
}

int	find_target(t_arrays *tabs, int value, int is_closest_smaller)
{
	int	index_target;
	int	*tab;
	int	size;

	init_params(tabs, is_closest_smaller, &tab, &size);
	index_target = find_index(tab, size, value, is_closest_smaller);
	if (index_target == -1)
	{
		if (is_closest_smaller)
			return (ft_max(tab, size));
		else
			return (ft_min(tab, size));
	}
	return (index_target);
}

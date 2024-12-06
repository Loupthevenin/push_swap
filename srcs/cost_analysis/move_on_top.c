/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_on_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:38:05 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/06 23:21:08 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_rr_or_rrr(t_arrays *tabs, int index_a, int index_b)
{
	int	top;
	int	bot;
	int	result;

	top = 0;
	bot = 0;
	if (index_a <= *tabs->size_a / 2)
		top++;
	else
		bot++;
	if (index_b <= *tabs->size_b / 2)
		top++;
	else
		bot++;
	if (top == 2)
		result = 1;
	else if (bot == 2)
		result = 2;
	else
		result = 0;
	return (result);
}

void	perform_rotation(int *tab, int size, int index, int is_a)
{
	int	i;

	i = 0;
	if (size / 2 >= index)
	{
		while (i < index)
		{
			if (is_a)
				rule_rotate_a(tab, size, 1);
			else
				rule_rotate_b(tab, size, 1);
			i++;
		}
	}
	else
	{
		while (i < size - index)
		{
			if (is_a)
				rule_reverse_rotate_a(tab, size, 1);
			else
				rule_reverse_rotate_b(tab, size, 1);
			i++;
		}
	}
}

void	move_rr(t_arrays *tabs, int *index_a, int *index_b)
{
	int	i;
	int	current_index;

	i = 0;
	if (*index_a <= *index_b)
		current_index = *index_a;
	else
		current_index = *index_b;
	while (i < current_index)
	{
		rule_rr(tabs->tab_a, tabs->tab_b, *tabs->size_a, *tabs->size_b);
		i++;
	}
	*index_a -= i;
	*index_b -= i;
}

void	move_rrr(t_arrays *tabs, int *index_a, int *index_b)
{
	int	i;
	int	current_index;
	int	max_size;

	i = 0;
	current_index = *index_b;
	max_size = *tabs->size_b;
	if (*tabs->size_a - *index_a <= *tabs->size_b - *index_b)
	{
		current_index = *index_a;
		max_size = *tabs->size_a;
	}
	while (i < max_size - current_index)
	{
		rule_rrr(tabs->tab_a, tabs->tab_b, *tabs->size_a, *tabs->size_b);
		i++;
	}
	*index_a += i;
	*index_b += i;
	if (*index_a >= *tabs->size_a)
		*index_a = 0;
	if (*index_b >= *tabs->size_b)
		*index_b = 0;
}

void	move_on_top(t_arrays *tabs, int index_a, int index_b)
{
	int	is_rr_rrr;

	is_rr_rrr = is_rr_or_rrr(tabs, index_a, index_b);
	if (index_a != 0 && index_b != 0 && is_rr_rrr != 0)
	{
		if (is_rr_rrr == 1)
			move_rr(tabs, &index_a, &index_b);
		else
			move_rrr(tabs, &index_a, &index_b);
	}
	if (index_a != 0)
		perform_rotation(tabs->tab_a, *tabs->size_a, index_a, 1);
	if (index_b != 0)
		perform_rotation(tabs->tab_b, *tabs->size_b, index_b, 0);
}

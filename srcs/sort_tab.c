/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:48:44 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/06 23:14:09 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_size_3a(int *tab_a)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = tab_a[0];
	j = 0;
	while (i < 3)
	{
		if (max < tab_a[i])
		{
			max = tab_a[i];
			j = i;
		}
		i++;
	}
	if (j == 0)
		rule_rotate_a(tab_a, 3, 1);
	else if (j == 1)
		rule_reverse_rotate_a(tab_a, 3, 1);
	if (tab_a[0] > tab_a[1])
		rule_swap_a(tab_a, 3, 1);
}

void	turk_sort(int *tab_a, int *tab_b, int *size_a, int *size_b)
{
	t_arrays	arg;
	int			i;

	i = 0;
	arg = (t_arrays){tab_a, tab_b, size_a, size_b};
	while (*size_a != 3)
	{
		if (i < 2)
			rule_push_b(tab_a, tab_b, size_a, size_b);
		else
		{
			cost_analysis(&arg, 1);
			rule_push_b(tab_a, tab_b, size_a, size_b);
		}
		i++;
	}
	sort_size_3a(tab_a);
	while (*size_b)
	{
		cost_analysis(&arg, 0);
		rule_push_a(tab_b, tab_a, size_b, size_a);
	}
	move_on_top(&arg, ft_min(tab_a, *size_a), 0);
}

void	sort_tab(int *tab_a, int size)
{
	int	*tab_b;
	int	size_a;
	int	size_b;

	tab_b = (int *)malloc(sizeof(int) * size);
	if (!tab_b)
		return ;
	size_a = size;
	size_b = 0;
	if (size == 2)
	{
		if (tab_a[0] > tab_a[1])
			rule_swap_a(tab_a, size_a, 1);
	}
	else if (size == 3)
		sort_size_3a(tab_a);
	else if (size > 3)
		turk_sort(tab_a, tab_b, &size_a, &size_b);
	free(tab_b);
}

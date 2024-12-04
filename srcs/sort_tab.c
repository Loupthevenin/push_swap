/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:48:44 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/04 18:42:59 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_tab(int *tab_a, int *tab_b, int size_tab_a, int size_tab_b)
{
	int	i;
	int	size;

	i = 0;
	if (size_tab_a < size_tab_b)
		size = size_tab_b;
	else
		size = size_tab_a;
	while (size - 1 >= i)
	{
		ft_printf("%d\t", tab_a[i]);
		if (i <= size_tab_b - 1)
			ft_printf("%d", tab_b[i]);
		ft_printf("\n");
		i++;
	}
	ft_printf("-\t-\n");
	ft_printf("a\tb\n");
}

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
	int	i;

	i = 0;
	while (*size_a != 3)
	{
		if (i < 2)
			rule_push_b(tab_a, tab_b, size_a, size_b);
		else
		{
			cost_analysis_phase_1(tab_a, tab_b, *size_a, *size_b);
			rule_push_b(tab_a, tab_b, size_a, size_b);
		}
		i++;
	}
	sort_size_3a(tab_a);
	while (*size_b)
	{
		cost_analysis_phase_2(tab_a, tab_b, *size_a, *size_b);
		rule_push_a(tab_b, tab_a, size_b, size_a);
	}
	move_on_top_a(tab_a, *size_a, ft_min(tab_a, *size_a));
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
	else
		turk_sort(tab_a, tab_b, &size_a, &size_b);
	free(tab_b);
}

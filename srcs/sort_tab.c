/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:48:44 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/02 20:04:11 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_tab(int *tab_a, int *tab_b, int size_tab_a, int size_tab_b)
{
	int	i;

	i = 0;
	while (size_tab_a - 1 >= i)
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

void	sort_size_3(int *tab, char c)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = tab[0];
	j = 0;
	while (i < 3)
	{
		if (max < tab[i])
		{
			max = tab[i];
			j = i;
		}
		i++;
	}
	if (j == 0)
	{
		ft_printf("r%c\n", c);
		rule_rotate(tab, 3);
	}
	else if (j == 1)
	{
		ft_printf("rr%c\n", c);
		rule_reverse_rotate(tab, 3);
	}
	if (tab[0] > tab[1])
	{
		ft_printf("s%c\n", c);
		rule_swap(tab, 3);
	}
}

void	cost_analysis(int *tab_a, int *tab_b, int size_a, int size_b)
{
	int	*cost;
	int	i;

	i = 0;
	cost = (int *)malloc(sizeof(int) * size_a);
	if (!cost)
		return ;
	while (size_a > i)
	{
		i++;
	}
	free(cost);
}

void	turk_sort(int *tab_a, int *tab_b, int *size_a, int *size_b)
{
	int	i;
	int	size;
	int	count_rotate;

	i = 0;
	size = *size_a;
	count_rotate = 0;
	while (*size_a != 3)
	{
		if (i < 2)
		{
			rule_push(tab_a, tab_b, size_a, size_b);
			ft_printf("pb\n");
		}
		else
		{
			cost_analysis(tab_a, tab_b, *size_a, *size_b);
			rule_push(tab_a, tab_b, size_a, size_b);
			ft_printf("pb\n");
		}
		i++;
	}
	sort_size_3(tab_a, 'a');
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
		{
			rule_swap(tab_a, size_a);
			ft_printf("sa\n");
		}
	}
	else if (size == 3)
		sort_size_3(tab_a, 'a');
	else
		turk_sort(tab_a, tab_b, &size_a, &size_b);
	print_tab(tab_a, tab_b, size_a, size_b);
}

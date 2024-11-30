/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:48:44 by ltheveni          #+#    #+#             */
/*   Updated: 2024/11/30 13:34:44 by ltheveni         ###   ########.fr       */
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
	/* rule_swap(tab_a, size_a); */
	/* rule_push(tab_a, tab_b, &size_a, &size_b); */
	/* rule_push(tab_a, tab_b, &size_a, &size_b); */
	/* rule_push(tab_a, tab_b, &size_a, &size_b); */
	/* rule_swap(tab_a, size_a); */
	/* rule_push(tab_b, tab_a, &size_b, &size_a); */
	/* rule_push(tab_b, tab_a, &size_b, &size_a); */
	/* rule_push(tab_b, tab_a, &size_b, &size_a); */
	print_tab(tab_a, tab_b, size_a, size_b);
}

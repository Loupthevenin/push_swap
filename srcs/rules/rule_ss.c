/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:49:16 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/03 13:44:40 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rule_swap_a(int *tab_a, int size_tab_a, int is_print)
{
	int	swap;

	if (size_tab_a <= 1)
		return (0);
	swap = tab_a[0];
	tab_a[0] = tab_a[1];
	tab_a[1] = swap;
	if (is_print)
		ft_printf("sa\n");
	return (1);
}

int	rule_swap_b(int *tab_b, int size_tab_b, int is_print)
{
	int	swap;

	if (size_tab_b <= 1)
		return (0);
	swap = tab_b[0];
	tab_b[0] = tab_b[1];
	tab_b[1] = swap;
	if (is_print)
		ft_printf("sb\n");
	return (1);
}

int	rule_ss(int *tab_a, int *tab_b, int size_tab_a, int size_tab_b)
{
	int	count;

	count = 0;
	count += rule_swap_a(tab_a, size_tab_a, 0);
	count += rule_swap_b(tab_b, size_tab_b, 0);
	if (count != 2)
		return (0);
	return (1);
}

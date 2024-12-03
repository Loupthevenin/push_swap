/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:21:09 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/03 15:56:11 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rule_reverse_rotate_a(int *tab_a, int size_tab_a, int is_print)
{
	int	swap;
	int	save;
	int	i;

	if (size_tab_a <= 1)
		return (0);
	save = tab_a[size_tab_a - 1];
	i = size_tab_a - 1;
	while (i > 0)
	{
		swap = tab_a[i];
		tab_a[i] = tab_a[i - 1];
		tab_a[i - 1] = swap;
		i--;
	}
	tab_a[0] = save;
	if (is_print)
		ft_printf("rra\n");
	return (1);
}

int	rule_reverse_rotate_b(int *tab_b, int size_tab_b, int is_print)
{
	int	swap;
	int	save;
	int	i;

	if (size_tab_b <= 1)
		return (0);
	save = tab_b[size_tab_b - 1];
	i = size_tab_b - 1;
	while (i > 0)
	{
		swap = tab_b[i];
		tab_b[i] = tab_b[i - 1];
		tab_b[i - 1] = swap;
		i--;
	}
	tab_b[0] = save;
	if (is_print)
		ft_printf("rrb\n");
	return (1);
}

int	rule_rrr(int *tab_a, int *tab_b, int size_tab_a, int size_tab_b)
{
	int	count;

	count = 0;
	count += rule_reverse_rotate_a(tab_a, size_tab_a, 0);
	count += rule_reverse_rotate_b(tab_b, size_tab_b, 0);
	if (count != 2)
		return (0);
	ft_printf("rrr\n");
	return (1);
}

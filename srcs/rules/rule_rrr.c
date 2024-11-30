/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:21:09 by ltheveni          #+#    #+#             */
/*   Updated: 2024/11/30 13:21:36 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rule_reverse_rotate(int *tab, int size_tab)
{
	int	swap;
	int	save;
	int	i;

	if (size_tab <= 1)
		return (0);
	save = tab[size_tab - 1];
	i = size_tab - 1;
	while (i > 0)
	{
		swap = tab[i];
		tab[i] = tab[i - 1];
		tab[i - 1] = swap;
		i--;
	}
	tab[0] = save;
	return (1);
}

int	rule_rrr(int *tab_a, int *tab_b, int size_tab_a, int size_tab_b)
{
	int	count;

	count = 0;
	count += rule_reverse_rotate(tab_a, size_tab_a);
	count += rule_reverse_rotate(tab_b, size_tab_b);
	return (count);
}

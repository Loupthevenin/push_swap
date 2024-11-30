/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:19:33 by ltheveni          #+#    #+#             */
/*   Updated: 2024/11/30 13:20:14 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rule_rotate(int *tab, int size_tab)
{
	int	swap;
	int	save;
	int	i;

	if (size_tab <= 1)
		return (0);
	save = tab[0];
	i = 0;
	while (i < size_tab - 1)
	{
		swap = tab[i];
		tab[i] = tab[i + 1];
		tab[i + 1] = swap;
		i++;
	}
	tab[size_tab - 1] = save;
	return (1);
}

int	rule_rr(int *tab_a, int *tab_b, int size_tab_a, int size_tab_b)
{
	int	count;

	count = 0;
	count += rule_rotate(tab_a, size_tab_a);
	count += rule_rotate(tab_b, size_tab_b);
	return (count);
}

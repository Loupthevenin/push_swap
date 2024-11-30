/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:49:16 by ltheveni          #+#    #+#             */
/*   Updated: 2024/11/30 13:22:26 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rule_swap(int *tab, int size_tab)
{
	int	swap;

	if (size_tab <= 1)
		return (0);
	swap = tab[0];
	tab[0] = tab[1];
	tab[1] = swap;
	return (1);
}

int	rule_ss(int *tab_a, int *tab_b, int size_tab_a, int size_tab_b)
{
	int	count;

	count = 0;
	count += rule_swap(tab_a, size_tab_a);
	count += rule_swap(tab_b, size_tab_b);
	return (count);
}

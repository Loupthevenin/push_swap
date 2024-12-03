/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:17:57 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/03 16:04:20 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rule_push_a(int *move_b, int *push_a, int *size_move_b, int *size_push_a)
{
	int	i;

	if (*size_move_b == 0)
		return (0);
	i = *size_push_a;
	while (i > 0)
	{
		push_a[i] = push_a[i - 1];
		i--;
	}
	push_a[0] = move_b[0];
	i = 0;
	while (*size_move_b - 1 > i)
	{
		move_b[i] = move_b[i + 1];
		i++;
	}
	*size_push_a += 1;
	*size_move_b -= 1;
	ft_printf("pa\n");
	return (1);
}

int	rule_push_b(int *move_a, int *push_b, int *size_move_a, int *size_push_b)
{
	int	i;

	if (*size_move_a == 0)
		return (0);
	i = *size_push_b;
	while (i > 0)
	{
		push_b[i] = push_b[i - 1];
		i--;
	}
	push_b[0] = move_a[0];
	i = 0;
	while (*size_move_a - 1 > i)
	{
		move_a[i] = move_a[i + 1];
		i++;
	}
	*size_push_b += 1;
	*size_move_a -= 1;
	ft_printf("pb\n");
	return (1);
}

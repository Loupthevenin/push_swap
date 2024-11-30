/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:17:57 by ltheveni          #+#    #+#             */
/*   Updated: 2024/11/30 13:18:36 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rule_push(int *move, int *push, int *size_move, int *size_push)
{
	int	i;

	if (move[0] == 0)
		return (0);
	i = *size_push;
	while (i > 0)
	{
		push[i] = push[i - 1];
		i--;
	}
	push[0] = move[0];
	i = 0;
	while (*size_move - 1 > i)
	{
		move[i] = move[i + 1];
		i++;
	}
	*size_push += 1;
	*size_move -= 1;
	return (1);
}

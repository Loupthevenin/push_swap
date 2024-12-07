/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:59:23 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/07 12:29:51 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_duplicate(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (size > i)
	{
		j = i;
		j--;
		while (j >= 0)
		{
			if (tab[j] == tab[i])
			{
				ft_printf("Error\n");
				return (0);
			}
			j--;
		}
		i++;
	}
	return (1);
}

long	ft_atoi_long(char *s)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * sign);
}

int	is_sorted(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] > tab[i + 1] && i + 1 < size)
			return (0);
		i++;
	}
	return (1);
}

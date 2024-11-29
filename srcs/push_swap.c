/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:48:18 by ltheveni          #+#    #+#             */
/*   Updated: 2024/11/29 11:50:46 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_nbr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != '-' && s[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	*tab_a;

	if (argc > 1)
	{
		i = 1;
		j = 0;
		tab_a = (int *)malloc(sizeof(int) * (argc - 1));
		if (!tab_a)
			return (1);
		while (i < argc)
		{
			if (!is_nbr(argv[i]))
			{
				free(tab_a);
				ft_printf("Error\n");
				return (1);
			}
			tab_a[j++] = ft_atoi(argv[i++]);
		}
		sort_tab(tab_a);
	}
	return (0);
}

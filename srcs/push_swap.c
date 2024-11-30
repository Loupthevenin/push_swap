/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:48:18 by ltheveni          #+#    #+#             */
/*   Updated: 2024/11/30 15:28:53 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_nbr(char *s)
{
	int		i;
	long	n;
	int		sign;

	i = 0;
	sign = 1;
	while (s[i])
	{
		while (s[i] && (s[i] == ' '))
			i++;
		if (s[i] == '-' || s[i] == '+')
		{
			if (s[i] == '-')
				sign = -1;
			i++;
		}
		n = 0;
		while (s[i] && s[i] >= '0' && s[i] <= '9')
		{
			n = n * 10 + (s[i] - '0');
			if ((sign * n) > 2147483647 || (sign * n) < -2147483648)
				return (0);
			i++;
		}
		while (s[i] && s[i] != ' ')
		{
			if (!ft_isdigit(s[i]) && s[i] != '-' && s[i] != '+' && s[i] != ' ')
				return (0);
			i++;
		}
	}
	return (1);
}

int	len_arg(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' '))
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != ' ')
			i++;
	}
	return (count);
}

int	check_string(int argc, char **argv)
{
	int	i;
	int	len_nbr;

	i = 1;
	len_nbr = 0;
	while (i < argc)
	{
		if (!is_nbr(argv[i]))
		{
			ft_printf("Error\n");
			return (-1);
		}
		len_nbr += len_arg(argv[i]);
		i++;
	}
	return (len_nbr);
}

int	*malloc_tab(int argc, char **argv, int size)
{
	int	i;
	int	j;
	int	k;
	int	*result;

	i = 1;
	k = 0;
	result = (int *)malloc(sizeof(int) * size);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] && argv[i][j] == ' ')
				j++;
			if (argv[i][j])
				result[k++] = ft_atoi(&argv[i][j]);
			while (argv[i][j] && argv[i][j] != ' ')
				j++;
		}
		i++;
	}
	return (result);
}

int	check_duplicate(int *tab)
{
	(void)tab;
	return (1);
}

int	main(int argc, char **argv)
{
	int	len_nbr;
	int	*tab_a;

	if (argc > 1)
	{
		len_nbr = check_string(argc, argv);
		if (len_nbr == -1)
			return (1);
		tab_a = malloc_tab(argc, argv, len_nbr);
		if (!tab_a)
			return (1);
		/* if (!check_duplicate(tab_a)) */
		/* 	return (1); */
		sort_tab(tab_a, len_nbr);
	}
	return (0);
}

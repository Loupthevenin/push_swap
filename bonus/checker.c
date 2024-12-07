/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:50:26 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/07 16:29:11 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_nbr(char *s)
{
	int		i;
	long	n;

	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		if ((s[i] == '-' || s[i] == '+') && !ft_isdigit(s[i + 1]))
			return (0);
		n = ft_atoi_long(&s[i]);
		if (n > 2147483647 || n < -2147483648)
			return (0);
		while (s[i] && s[i] != ' ' && s[i] != '\t')
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
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != ' ' && s[i] != '\t')
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
			while (argv[i][j] && (argv[i][j] == ' ' || argv[i][j] == '\t'))
				j++;
			if (argv[i][j])
				result[k++] = ft_atoi(&argv[i][j]);
			while (argv[i][j] && argv[i][j] != ' ' && argv[i][j] != '\t')
				j++;
		}
		i++;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	int	size;
	int	len_nbr;
	int	*tab_a;

	if (argc > 1)
	{
		size = check_string(argc, argv);
		if (size == -1)
			return (1);
		len_nbr = size;
		tab_a = malloc_tab(argc, argv, len_nbr);
		if (!tab_a || !check_duplicate(tab_a, len_nbr) || !rule_uses(tab_a,
				&len_nbr))
		{
			free(tab_a);
			return (1);
		}
		if (is_sorted(tab_a, len_nbr) && size == len_nbr)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free(tab_a);
	}
	return (0);
}

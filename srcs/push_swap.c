/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:48:18 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/05 15:18:41 by ltheveni         ###   ########.fr       */
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
		while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		n = ft_atoi_long(&s[i]);
		if (n > 2147483647 || n < -2147483648)
			return (0);
		while (s[i] && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
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
		while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
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
			while (argv[i][j] && (argv[i][j] == ' ' || argv[i][j] == '\n'
					|| argv[i][j] == '\t'))
				j++;
			if (argv[i][j])
				result[k++] = ft_atoi(&argv[i][j]);
			while (argv[i][j] && argv[i][j] != ' ' && argv[i][j] != '\n'
				&& argv[i][j] != '\t')
				j++;
		}
		i++;
	}
	return (result);
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
		if (!check_duplicate(tab_a, len_nbr))
			return (1);
		if (!is_sorted(tab_a, len_nbr))
			sort_tab(tab_a, len_nbr);
		free(tab_a);
	}
	return (0);
}

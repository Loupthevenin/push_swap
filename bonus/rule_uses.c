/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_uses.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:56:15 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/07 16:07:33 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_line(char *line, int size)
{
	if (!ft_strncmp(line, "sa", size))
		return (1);
	if (!ft_strncmp(line, "sb", size))
		return (2);
	if (!ft_strncmp(line, "ss", size))
		return (3);
	if (!ft_strncmp(line, "pa", size))
		return (4);
	if (!ft_strncmp(line, "pb", size))
		return (5);
	if (!ft_strncmp(line, "ra", size))
		return (6);
	if (!ft_strncmp(line, "rb", size))
		return (7);
	if (!ft_strncmp(line, "rr", size))
		return (8);
	if (!ft_strncmp(line, "rra", size))
		return (9);
	if (!ft_strncmp(line, "rrb", size))
		return (10);
	if (!ft_strncmp(line, "rrr", size))
		return (11);
	return (0);
}

void	set_rules(int index_rule, t_arrays *tabs)
{
	if (index_rule == 1)
		rule_swap_a_bonus(tabs->tab_a, *tabs->size_a, 0);
	if (index_rule == 2)
		rule_swap_b_bonus(tabs->tab_b, *tabs->size_b, 0);
	if (index_rule == 3)
		rule_ss_bonus(tabs->tab_a, tabs->tab_a, *tabs->size_a, *tabs->size_b);
	if (index_rule == 4)
		rule_push_a_bonus(tabs->tab_b, tabs->tab_a, tabs->size_b, tabs->size_a);
	if (index_rule == 5)
		rule_push_b_bonus(tabs->tab_a, tabs->tab_b, tabs->size_a, tabs->size_b);
	if (index_rule == 6)
		rule_rotate_a_bonus(tabs->tab_a, *tabs->size_a, 0);
	if (index_rule == 7)
		rule_rotate_b_bonus(tabs->tab_b, *tabs->size_b, 0);
	if (index_rule == 8)
		rule_rr_bonus(tabs->tab_a, tabs->tab_b, *tabs->size_a, *tabs->size_b);
	if (index_rule == 9)
		rule_reverse_rotate_a_bonus(tabs->tab_a, *tabs->size_a, 0);
	if (index_rule == 10)
		rule_reverse_rotate_b_bonus(tabs->tab_b, *tabs->size_b, 0);
	if (index_rule == 11)
		rule_rrr_bonus(tabs->tab_a, tabs->tab_b, *tabs->size_a, *tabs->size_b);
}

int	loop_rules(int *tab_a, int *tab_b, int *size_a, int *size_b)
{
	char		*line;
	t_arrays	arg;
	int			rule;

	arg = (t_arrays){tab_a, tab_b, size_a, size_b};
	line = get_next_line(0);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			return (0);
		}
		rule = check_line(line, ft_strlen(line) - 1);
		free(line);
		if (!rule)
			return (0);
		set_rules(rule, &arg);
		line = get_next_line(0);
	}
	return (1);
}

int	rule_uses(int *tab_a, int *size_a)
{
	int	*tab_b;
	int	size_b;

	tab_b = (int *)malloc(sizeof(int) * *size_a);
	if (!tab_b)
		return (0);
	size_b = 0;
	if (!loop_rules(tab_a, tab_b, size_a, &size_b))
	{
		ft_printf("Error\n");
		free(tab_b);
		return (0);
	}
	free(tab_b);
	return (1);
}

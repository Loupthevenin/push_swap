/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:48:59 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/02 10:39:24 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"

int		rule_swap(int *tab, int size_tab);
int		rule_ss(int *tab_a, int *tab_b, int size_tab_a, int size_tab_b);
int		rule_push(int *move, int *push, int *size_move, int *size_push);
int		rule_rotate(int *tab, int size_tab);
int		rule_rr(int *tab_a, int *tab_b, int size_tab_a, int size_tab_b);
int		rule_reverse_rotate(int *tab, int size_tab);
int		rule_rrr(int *tab_a, int *tab_b, int size_tab_a, int size_tab_b);

int		check_duplicate(int *tab, int size);
long	ft_atoi_long(char *s);
void	sort_tab(int *tab_a, int size);

#endif

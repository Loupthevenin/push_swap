/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:48:59 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/07 14:09:36 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"

int					rule_swap_a(int *tab_a, int size_tab_a, int is_print);
int					rule_swap_b(int *tab_b, int size_tab_b, int is_print);
int					rule_ss(int *tab_a, int *tab_b, int size_tab_a,
						int size_tab_b);
int					rule_push_a(int *move_b, int *push_a, int *size_move_b,
						int *size_push_a);
int					rule_push_b(int *move_a, int *push_b, int *size_move_a,
						int *size_push_b);
int					rule_rotate_a(int *tab_a, int size_tab_a, int is_print);
int					rule_rotate_b(int *tab_b, int size_tab_b, int is_print);
int					rule_rr(int *tab_a, int *tab_b, int size_tab_a,
						int size_tab_b);
int					rule_reverse_rotate_a(int *tab_a, int size_tab_a,
						int is_print);
int					rule_reverse_rotate_b(int *tab_b, int size_tab_b,
						int is_print);
int					rule_rrr(int *tab_a, int *tab_b, int size_tab_a,
						int size_tab_b);

typedef struct s_array
{
	int				*tab_a;
	int				*tab_b;
	int				*size_a;
	int				*size_b;
}					t_arrays;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_move_cost
{
	int				index_a;
	int				index_b;
	int				cost_a;
	int				cost_b;
	int				total_cost;
}					t_movecost;

typedef struct s_cost_info
{
	int				index_a;
	int				index_b;
	int				size_a;
	int				size_b;
	int				i;
}					t_cost_info;

int					check_duplicate(int *tab, int size);
long				ft_atoi_long(char *s);
int					is_sorted(int *tab, int size);
int					ft_max(int *tab, int size);
int					ft_min(int *tab, int size);
t_node				*tab_to_list(int *tab, int size);
void				free_list(t_node *head);
t_movecost			find_min_cost(t_movecost *costs, int size);
int					abs_diff(int a, int b);
int					find_target(t_arrays *tabs, int value,
						int is_closest_smaller);
void				move_on_top(t_arrays *tabs, int index_a, int index_b);
void				cost_analysis(t_arrays *tabs, int is_closest_smaller);
void				calculate_costs(t_node *current_list, t_arrays *tabs,
						t_movecost *costs, int is_closest_smaller);
void				sort_tab(int *tab_a, int size);

int					rule_swap_a_bonus(int *tab_a, int size_tab_a, int is_print);
int					rule_swap_b_bonus(int *tab_b, int size_tab_b, int is_print);
int					rule_ss_bonus(int *tab_a, int *tab_b, int size_tab_a,
						int size_tab_b);
int					rule_push_a_bonus(int *move_b, int *push_a,
						int *size_move_b, int *size_push_a);
int					rule_push_b_bonus(int *move_a, int *push_b,
						int *size_move_a, int *size_push_b);
int					rule_rotate_a_bonus(int *tab_a, int size_tab_a,
						int is_print);
int					rule_rotate_b_bonus(int *tab_b, int size_tab_b,
						int is_print);
int					rule_rr_bonus(int *tab_a, int *tab_b, int size_tab_a,
						int size_tab_b);
int					rule_reverse_rotate_a_bonus(int *tab_a, int size_tab_a,
						int is_print);
int					rule_reverse_rotate_b_bonus(int *tab_b, int size_tab_b,
						int is_print);
int					rule_rrr_bonus(int *tab_a, int *tab_b, int size_tab_a,
						int size_tab_b);

int					rule_uses(int *tab_a, int size_a);

#endif

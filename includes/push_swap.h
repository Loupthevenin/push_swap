/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:48:59 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/05 10:33:44 by ltheveni         ###   ########.fr       */
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
}					Arrays;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct
{
	int				index_a;
	int				index_b;
	int				cost_a;
	int				cost_b;
	int				total_cost;
}					MoveCost;

int					check_duplicate(int *tab, int size);
long				ft_atoi_long(char *s);
int					ft_max(int *tab, int size);
int					ft_min(int *tab, int size);
t_node				*tab_to_list(int *tab, int size);
void				free_list(t_node *head);
MoveCost			find_min_cost(MoveCost *costs, int size);
void				move_on_top_a(int *tab_a, int size_a, int index);
void				move_on_top_b(int *tab_b, int size_b, int index);
void				cost_analysis(Arrays *tabs, int is_closest_smaller);
void				sort_tab(int *tab_a, int size);

#endif

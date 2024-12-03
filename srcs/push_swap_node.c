/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:43:14 by ltheveni          #+#    #+#             */
/*   Updated: 2024/12/03 14:43:52 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_lstnew_node(int *tab, int i)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = tab[i];
	new_node->index = i;
	new_node->next = NULL;
	return (new_node);
}

t_node	*tab_to_list(int *tab, int size)
{
	t_node	*head;
	t_node	*current;
	t_node	*new_node;
	int		i;

	head = NULL;
	current = NULL;
	i = 0;
	while (i < size)
	{
		new_node = ft_lstnew_node(tab, i);
		if (!head)
		{
			head = new_node;
			current = head;
		}
		else
		{
			current->next = new_node;
			current = new_node;
		}
		i++;
	}
	return (head);
}

void	free_list(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

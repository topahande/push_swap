/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:18:57 by htopa             #+#    #+#             */
/*   Updated: 2024/11/26 21:41:50 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node *lst)
{
	int	temp;

	temp = lst->next->value;
	lst->next->value = lst->value;
	lst->value = temp;
}

void	ft_rotate(t_node **lst)
{
	t_node	*temp;
	t_node	*last_node;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	temp = *lst;
	last_node = lstlast(*lst);
	*lst = (*lst)->next;
	last_node->next = temp;
	temp->next = NULL;
}

void	ft_reverse_rotate(t_node **lst)
{
	t_node	*last_node;
	t_node	*second_last;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	last_node = *lst;
	while (last_node->next != NULL)
	{
		second_last = last_node;
		last_node = last_node->next;
	}
	last_node->next = *lst;
	*lst = last_node;
	second_last->next = NULL;
}

void	ft_push(t_node **a, t_node **b)
{
	t_node	*temp;

	if (a == NULL || *a == NULL)
		return ;
	temp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = temp;
}

t_node	*move_to_b_excluding_three(int total_nodes, t_node **a)
{
	t_node	*b;

	b = NULL;
	if (total_nodes <= 3 || a == NULL || *a == NULL)
		return (NULL);
	while (total_nodes > 3)
	{
		ft_push(a, &b);
		ft_printf("pb\n");
		total_nodes--;
	}
	return (b);
}

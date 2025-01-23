/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:08:32 by htopa             #+#    #+#             */
/*   Updated: 2024/11/27 13:11:28 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_node *lst)
{
	int	n_nodes;

	n_nodes = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		n_nodes++;
	}
	return (n_nodes);
}

void	lstadd_front(t_node **lst, t_node *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

t_node	*lstlast(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_node	*create_node(char *value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->error = 0;
	node->value = ft_atoi(value);
	if (node->value == 0 && is_zero(value) != 1)
		node->error = 1;
	node->cost = 0;
	node->total_cost = 0;
	node->move = -1;
	node->next = NULL;
	node->target = NULL;
	return (node);
}

void	append_node(t_node **head, char *value)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = create_node(value);
	if (new_node == NULL)
		exit_with_error("Malloc failed\n");
	if (*head == NULL)
		*head = new_node;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

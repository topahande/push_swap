/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:19:07 by htopa             #+#    #+#             */
/*   Updated: 2024/11/27 12:41:29 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*set_target_to_min_node(t_node **a)
{
	t_node	*temp_a;
	t_node	*min_node_in_a;

	temp_a = *a;
	min_node_in_a = temp_a;
	while (temp_a->next != NULL)
	{
		if (temp_a->next->value < min_node_in_a->value)
			min_node_in_a = temp_a->next;
		temp_a = temp_a->next;
	}
	return (min_node_in_a);
}

void	find_target_in_a(t_node *b, t_node **a)
{
	t_node	*temp_b;
	t_node	*temp_a;

	temp_b = b;
	while (temp_b != NULL)
	{
		temp_a = *a;
		temp_b->target = NULL;
		while (temp_a != NULL)
		{
			if (temp_a->value > temp_b->value)
				if ((temp_b->target == NULL)
					|| (temp_a->value < temp_b->target->value))
					temp_b->target = temp_a;
			temp_a = temp_a->next;
		}
		if (temp_b->target == NULL)
			temp_b->target = set_target_to_min_node(a);
		temp_b = temp_b->next;
	}
}

void	calculate_cost_to_move_to_top(t_node *lst)
{
	int		size;
	int		cost;
	t_node	*temp;

	cost = 0;
	temp = lst;
	size = lstsize(lst);
	while (temp != NULL)
	{
		if (cost <= (size / 2))
		{
			temp->cost = cost;
			temp->move = 0;
		}
		else
		{
			temp->cost = size - cost;
			temp->move = 1;
		}
		cost++;
		temp = temp->next;
	}
}

void	get_total_cost(t_node *b)
{
	t_node	*temp_b;

	temp_b = b;
	while (temp_b != NULL)
	{
		if (temp_b->cost < temp_b->target->cost)
			temp_b->total_cost = temp_b->target->cost;
		else
			temp_b->total_cost = temp_b->cost;
		temp_b = temp_b->next;
	}
}

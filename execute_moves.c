/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:24:12 by htopa             #+#    #+#             */
/*   Updated: 2024/11/27 12:41:21 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_back_from_b_to_a(t_node **a, t_node **b)
{
	t_node	*min_cost_node_b;
	t_node	*temp;

	while (*b != NULL)
	{
		find_target_in_a(*b, a);
		calculate_cost_to_move_to_top(*a);
		calculate_cost_to_move_to_top(*b);
		get_total_cost(*b);
		min_cost_node_b = *b;
		temp = (*b)->next;
		while (temp != NULL)
		{
			if ((temp->total_cost) < (min_cost_node_b->total_cost))
				min_cost_node_b = temp;
			temp = temp->next;
		}
		execute_moves(min_cost_node_b, a, b);
	}
}

static void	moves_in_both_a_and_b(int move, t_node **a, t_node **b)
{
	if (move == 0)
	{
		ft_rotate(b);
		ft_rotate(a);
		ft_printf("rr\n");
	}
	if (move == 1)
	{
		ft_reverse_rotate(b);
		ft_reverse_rotate(a);
		ft_printf("rrr\n");
	}
}

void	moves_in_single_stack(int move, t_node **t, char stack)
{
	if (move == 0)
	{
		ft_rotate(t);
		ft_printf("r%c\n", stack);
	}
	if (move == 1)
	{
		ft_reverse_rotate(t);
		ft_printf("rr%c\n", stack);
	}
}

static void	execute_same_moves_in_stacks(t_node *mcnode, t_node **a, t_node **b)
{
	int	i;
	int	min_num;
	int	max_num;

	if (mcnode->cost < mcnode->target->cost)
	{
		min_num = mcnode->cost;
		max_num = mcnode->target->cost;
	}
	else
	{
		max_num = mcnode->cost;
		min_num = mcnode->target->cost;
	}
	i = -1;
	while (++i < min_num)
		moves_in_both_a_and_b(mcnode->move, a, b);
	i--;
	while (++i < max_num)
	{
		if (mcnode->target->cost > mcnode->cost)
			moves_in_single_stack(mcnode->move, a, 'a');
		else
			moves_in_single_stack(mcnode->move, b, 'b');
	}
}

void	execute_moves(t_node *min_cost_node_b, t_node **a, t_node **b)
{
	int	i;

	if (min_cost_node_b->move == min_cost_node_b->target->move)
		execute_same_moves_in_stacks(min_cost_node_b, a, b);
	else
	{
		i = 0;
		while (i < min_cost_node_b->cost)
		{
			moves_in_single_stack(min_cost_node_b->move, b, 'b');
			i++;
		}
		i = 0;
		while (i < min_cost_node_b->target->cost)
		{
			moves_in_single_stack(min_cost_node_b->target->move, a, 'a');
			i++;
		}
	}
	ft_push(b, a);
	ft_printf("pa\n");
}

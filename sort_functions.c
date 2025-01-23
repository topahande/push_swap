/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:18:43 by htopa             #+#    #+#             */
/*   Updated: 2024/11/26 21:40:57 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_zero(char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0')
	{
		if (*str != '0')
			return (0);
		str++;
	}
	return (1);
}

int	is_sorted(t_node *lst)
{
	t_node	*temp;

	temp = lst;
	while (temp != NULL)
	{
		if (temp->next != NULL && temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	sort_two(t_node **lst)
{
	if ((*lst)->value > (*lst)->next->value)
	{
		ft_swap(*lst);
		ft_printf("sa\n");
	}
}

void	sort_three(t_node **lst)
{
	if ((*lst)->value > (*lst)->next->value)
	{
		ft_swap(*lst);
		ft_printf("sa\n");
	}
	if ((*lst)->value > (*lst)->next->next->value)
	{
		ft_reverse_rotate(lst);
		ft_printf("rra\n");
	}
	if ((*lst)->next->value > (*lst)->next->next->value)
	{
		ft_reverse_rotate(lst);
		ft_swap(*lst);
		ft_printf("rra\nsa\n");
	}
}

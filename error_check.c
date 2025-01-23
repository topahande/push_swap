/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:19:03 by htopa             #+#    #+#             */
/*   Updated: 2024/11/25 18:24:42 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_plus_minus(char *arg, int j)
{
	if (arg[j] == '-' || arg[j] == '+')
	{
		if ((arg[j + 1] == '\0') || (arg[j + 1] != '\0'
				&& ft_isdigit(arg[j + 1]) != 1))
			return (1);
		else
			return (0);
	}
	else
		return (1);
}

int	error_check(int argc, char **argv)
{
	int		i;
	int		j;
	char	*arg;

	if (argc == 2 && argv[1][0] == '\0')
		return (1);
	i = 1;
	while (i < argc)
	{
		arg = argv[i];
		j = 0;
		while (arg[j] != '\0')
		{
			if (ft_isdigit(arg[j]) == 0)
			{
				if (handle_plus_minus(arg, j) == 1)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_nonint_values(t_node *lst)
{
	t_node	*temp;

	temp = lst;
	while (temp != NULL)
	{
		if (temp->error == 1)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	check_duplicate(t_node *lst)
{
	t_node	*temp;
	t_node	*compared_node;

	temp = lst;
	while (temp != NULL)
	{
		compared_node = temp->next;
		while (compared_node != NULL)
		{
			if (temp->value == compared_node->value)
				return (1);
			compared_node = compared_node->next;
		}
		temp = temp->next;
	}
	return (0);
}

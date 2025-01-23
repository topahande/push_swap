/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:18:30 by htopa             #+#    #+#             */
/*   Updated: 2024/11/26 21:25:27 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node **head_of_list)
{
	t_node	*curr;
	t_node	*temp;

	curr = *head_of_list;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	*head_of_list = NULL;
}

void	free_argv(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	exit_with_error(const char *error_message)
{
	int	len;

	len = ft_strlen(error_message);
	write(2, error_message, len);
	exit(1);
}

int	free_and_exit(int free_flag, char **argv, const char *error_message)
{
	if (free_flag)
		free_argv(argv);
	if (error_message != NULL)
		exit_with_error(error_message);
	exit(0);
}

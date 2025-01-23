/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:53:13 by htopa             #+#    #+#             */
/*   Updated: 2024/11/26 21:22:56 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	simplify_argv(int *argc, char ***argv)
{
	char	**simplified_arg;
	int		k;
	char	**new_argv;

	simplified_arg = ft_split((*argv)[1], ' ');
	if (simplified_arg[0] == NULL)
	{
		free(simplified_arg);
		exit_with_error("Error\n");
	}
	k = 0;
	while (simplified_arg[k] != NULL)
		k++;
	*argc = k + 1;
	new_argv = malloc((*argc + 1) * sizeof(char *));
	if (!new_argv)
		return (-1);
	new_argv[0] = (*argv)[0];
	k = 0;
	while (++k < *argc)
		new_argv[k] = simplified_arg[k - 1];
	new_argv[k] = NULL;
	free(simplified_arg);
	*argv = new_argv;
	return (1);
}

static int	check_arguments(int *argc, char ***argv)
{
	int	free_flag;

	free_flag = 0;
	if (*argc == 1)
		exit(0);
	if (*argc == 2 && (*argv)[1][0] != '\0'
		&& ft_strchr((*argv)[1], ' ') == NULL)
	{
		if (ft_atoi((*argv)[1]) == 0 && is_zero((*argv)[1]) != 1)
			exit_with_error("Error\n");
	}
	if (*argc == 2 && (*argv)[1][0] != '\0'
		&& ft_strchr((*argv)[1], ' ') != NULL)
		free_flag = simplify_argv(argc, argv);
	if (free_flag == -1)
		exit_with_error("Malloc failed\n");
	if (error_check(*argc, *argv) == 1)
		free_and_exit(free_flag, *argv, "Error\n");
	if (*argc == 2 && (*argv)[1][0] != '\0'
		&& ft_strchr((*argv)[1], ' ') == NULL)
	{
		if (ft_atoi((*argv)[1]) == 0 && is_zero((*argv)[1]) != 1)
			free_and_exit(free_flag, *argv, "Error\n");
	}
	return (free_flag);
}

static t_node	*check_stack_a(int argc, char **argv, int free_flag)
{
	int		i;
	t_node	*a;

	a = NULL;
	i = 0;
	while (i < argc - 1)
	{
		append_node(&a, argv[i + 1]);
		i++;
	}
	if (check_nonint_values(a) == 1 || check_duplicate(a) == 1)
	{
		free_list(&a);
		free_and_exit(free_flag, argv, "Error\n");
	}
	if (is_sorted(a) == 1)
	{
		free_list(&a);
		free_and_exit(free_flag, argv, NULL);
	}
	return (a);
}

int	main(int argc, char **argv)
{
	int		i;
	t_node	*a;
	t_node	*b;
	t_node	*min_node_in_a;
	int		free_flag;

	free_flag = check_arguments(&argc, &argv);
	a = check_stack_a(argc, argv, free_flag);
	if (argc == 3)
	{
		sort_two(&a);
		free_list(&a);
		free_and_exit(free_flag, argv, NULL);
	}
	b = move_to_b_excluding_three(argc - 1, &a);
	sort_three(&a);
	move_back_from_b_to_a(&a, &b);
	calculate_cost_to_move_to_top(a);
	min_node_in_a = set_target_to_min_node(&a);
	i = -1;
	while (++i < min_node_in_a->cost)
		moves_in_single_stack(min_node_in_a->move, &a, 'a');
	free_list(&a);
	free_and_exit(free_flag, argv, NULL);
}

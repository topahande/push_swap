/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:53:04 by htopa             #+#    #+#             */
/*   Updated: 2024/11/27 12:42:31 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				error;
	int				cost;
	int				total_cost;
	int				move;
	struct s_node	*next;
	struct s_node	*target;
}	t_node;
int		lstsize(t_node *lst);
void	lstadd_front(t_node **lst, t_node *new);
t_node	*lstlast(t_node *lst);
t_node	*create_node(char *value);
void	append_node(t_node **head, char *value);
int		is_zero(char *str);
int		is_sorted(t_node *lst);
void	sort_two(t_node **lst);
void	sort_three(t_node **lst);
void	ft_swap(t_node *lst);
void	ft_rotate(t_node **lst);
void	ft_reverse_rotate(t_node **lst);
void	ft_push(t_node **a, t_node **b);
int		error_check(int argc, char **argv);
int		check_nonint_values(t_node *lst);
int		check_duplicate(t_node *lst);
void	calculate_cost_to_move_to_top(t_node *lst);
void	find_target_in_a(t_node *b, t_node **a);
void	get_total_cost(t_node *b);
void	execute_moves(t_node *min_cost_node_b, t_node **a, t_node **b);
int		simplify_argv(int *argc, char ***argv);
void	free_list(t_node **head_of_list);
void	moves_in_single_stack(int move, t_node **t, char stack);
t_node	*set_target_to_min_node(t_node **a);
void	free_argv(char **argv);
int		free_and_exit(int free_flag, char **argv, const char *error_message);
void	exit_with_error(const char *error_message);
t_node	*move_to_b_excluding_three(int total_nodes, t_node **a);
void	move_back_from_b_to_a(t_node **a, t_node **b);

#endif

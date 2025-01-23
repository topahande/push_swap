# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 17:04:53 by htopa             #+#    #+#              #
#    Updated: 2024/11/25 19:34:05 by htopa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c \
		utils.c \
		sort_functions.c \
		moves.c \
		error_check.c \
		target_utils.c \
		free_functions.c \
		execute_moves.c \

OBJS = $(SRCS:.c=.o)

CC = cc
CC_FLAGS = -Wall -Wextra -Werror

libft = libft/libft.a

%.o : %.c
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(libft)
	@$(CC) $(CC_FLAGS) $(OBJS) ${libft} -o ${NAME}
	echo "push_swap Done !"

$(libft):
	make -C libft

all: $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re

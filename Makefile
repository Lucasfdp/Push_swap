# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/13 01:25:43 by luferna3          #+#    #+#              #
#    Updated: 2026/05/13 01:31:41 by luferna3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

CFLAGS = -Wall -Wextra -Werror -I./include -I./libft

NAME = push_swap

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = ./src

SRCS = \
	$(SRC_DIR)/list_ops.c \
	$(SRC_DIR)/operations.c \
	$(SRC_DIR)/parsing.c \
	$(SRC_DIR)/parsing2.c \
	$(SRC_DIR)/freeing_ops.c \
	$(SRC_DIR)/less_simple_sorting.c \
	$(SRC_DIR)/simple_sorting.c \
	$(SRC_DIR)/double_ops.c \
	$(SRC_DIR)/k_sort.c \
	$(SRC_DIR)/main.c

OBJS = $(SRCS:.c=.o)

MAKEFLAGS 	+=	--no-print-directory

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

push:
	@if [ -z "$(M)" ]; then \
		printf "$(RED)  Usage: make push M=\"your commit message\"$(RESET)\n"; \
	else \
		printf "$(CYAN)$(BOLD)\n  Pushing to remote...$(RESET)\n\n"; \
		git add . && \
		git commit -m "$(M)" && \
		git push && \
		printf "$(GREEN)$(BOLD)  [Pushed successfully]$(RESET)\n\n"; \
	fi

re: fclean all

.PHONY: all clean fclean push re
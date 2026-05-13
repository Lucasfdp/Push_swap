# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13                                #+#    #+#              #
#    Updated: 2025/05/13                               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS_NAME	= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -I./include -I./libft

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

# ========================= #
#       COMMON FILES        #
# ========================= #

COMMON_SRC = \
	src/double_ops.c \
	src/freeing_ops.c \
	src/k_sort.c \
	src/less_simple_sorting.c \
	src/list_ops.c \
	src/operations.c \
	src/parsing.c \
	src/parsing2.c \
	src/simple_sorting.c

COMMON_OBJ = $(COMMON_SRC:.c=.o)

# ========================= #
#      PUSH_SWAP FILES      #
# ========================= #

PUSH_SWAP_SRC = \
	src/main.c

PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)

# ========================= #
#        BONUS FILES        #
# ========================= #

BONUS_SRC = \
	bonus/checker.c \
	bonus/checker_read.c \
	bonus/checker_exec.c \
	bonus/checker_utils.c \

BONUS_OBJ = $(BONUS_SRC:.c=.o)

# ========================= #
#          RULES            #
# ========================= #

all: $(LIBFT) $(NAME)

$(NAME): $(COMMON_OBJ) $(PUSH_SWAP_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) \
	$(COMMON_OBJ) $(PUSH_SWAP_OBJ) \
	-L$(LIBFT_DIR) -lft -lm \
	-o $(NAME)

checker: $(LIBFT) $(COMMON_OBJ) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) \
	$(COMMON_OBJ) $(BONUS_OBJ) \
	-L$(LIBFT_DIR) -lft -lm \
	-o $(BONUS_NAME)

# ========================= #
#         LIBFT             #
# ========================= #

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# ========================= #
#       COMPILATION         #
# ========================= #

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ========================= #
#          CLEAN            #
# ========================= #

clean:
	rm -f $(COMMON_OBJ)
	rm -f $(PUSH_SWAP_OBJ)
	rm -f $(BONUS_OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

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

# ========================= #
#          PHONY            #
# ========================= #

.PHONY: all clean fclean push re
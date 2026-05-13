/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 06:14:42 by luferna3          #+#    #+#             */
/*   Updated: 2026/05/13 03:54:47 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
}	t_data;

void		push(t_stack **src, t_stack **dest, char name, int print_op);
void		swap(t_stack **stack, char name, int print_op);
void		rotate(t_stack **stack, char name, int print_op);
void		reverse_rotate(t_stack **stack, char name, int print_op);
void		ss(t_stack **a, t_stack **b, int print_op);
void		rr(t_stack **a, t_stack **b, int print_op);
void		rrr(t_stack **a, t_stack **b, int print_op);

t_stack		*ft_lstnew_ps(int content);
void		ft_lstadd_front_ps(t_stack **lst, t_stack *new);
void		ft_lstadd_back_ps(t_stack **lst, t_stack *new);
int			ft_lstsize_ps(t_stack *lst);
t_stack		*ft_lstlast_ps(t_stack *lst);
int			ft_strlen_ps(char *str);

void		free_lst(t_stack *stack);
void		free_split(char **result, int count);
void		free_all(t_stack *stack_a, t_stack *stack_b, char **split,
				int count);

int			smallest_value(t_stack *stack_a);
void		three_nums(t_stack **stack_a);
void		four_nums(t_stack **stack_a, t_stack **stack_b);
void		five_nums(t_stack **stack_a, t_stack **stack_b);
void		six_nums(t_stack **stack_a, t_stack **stack_b);

int			*extracting_array(t_stack **stack_a);
void		sorting_array(int *array, int size);
void		assigning_index(t_stack **stack_a, int *array);

int			find_max_value(t_stack **stack_a);
void		k_sort(t_stack **stack_a, t_stack **stack_b, int size);

t_stack		*get_stack(int argc, char **argv);
t_stack		*parse_args(int argc, char **argv);
int			is_within_int_range(char *str, int overflow);
long long	ft_atoll(const char *str, long *j);
long long	ft_atoll2(const char *str, int *overflow);
int			valid_num_check(char *num);
int			check_order(t_stack **stack_a, int count);
void		print_stack(t_stack *stack, char name);

//BONUS

void	read_instructions(t_stack **a, t_stack **b);
void	execute_instruction(char *line, t_stack **a, t_stack **b);
int		is_sorted(t_stack *stack);
void	error_checker(t_stack **a, t_stack **b, char *line);

#endif

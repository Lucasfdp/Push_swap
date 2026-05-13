/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 04:39:31 by luferna3          #+#    #+#             */
/*   Updated: 2026/05/13 04:39:36 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_rotate(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(line, "ra\n", 3))
		rotate(a, 'a', 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate(b, 'b', 0);
	else if (!ft_strncmp(line, "rr\n", 3))
	{
		rotate(a, 'a', 0);
		rotate(b, 'b', 0);
	}
	else if (!ft_strncmp(line, "rra\n", 4))
		reverse_rotate(a, 'a', 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse_rotate(b, 'b', 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
	{
		reverse_rotate(a, 'a', 0);
		reverse_rotate(b, 'b', 0);
	}
	else
		error_checker(a, b, line);
}

void	execute_instruction(char *line,
			t_stack **a,
			t_stack **b)
{
	if (!ft_strncmp(line, "\n", 2))
		return ;
	else if (!ft_strncmp(line, "sa\n", 3))  // 4 -> 3
		swap(a, 'a', 0);
	else if (!ft_strncmp(line, "sb\n", 3))  // 4 -> 3
		swap(b, 'b', 0);
	else if (!ft_strncmp(line, "ss\n", 3))  // 4 -> 3
		ss(a, b, 0);
	else if (!ft_strncmp(line, "pa\n", 3))  // 4 -> 3
		push(b, a, 'a', 0);
	else if (!ft_strncmp(line, "pb\n", 3))  // 4 -> 3
		push(a, b, 'b', 0);
	else
		exec_rotate(line, a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/05/13 00:10:40 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_biggest_pos(t_stack *stack)
{
	int	pos;
	int	max;
	int	max_pos;

	pos = 0;
	max_pos = 0;
	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			max_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (max_pos);
}

static void	move_back_to_a(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;

	while (*b)
	{
		pos = find_biggest_pos(*b);
		size = ft_lstsize_ps(*b);
		if (pos <= size / 2)
		{
			while (pos--)
				rotate(b, 'b', 1);
		}
		else
		{
			pos = size - pos;
			while (pos--)
				reverse_rotate(b, 'b', 1);
		}
		push(b, a, 'a', 1);
	}
}

void	k_sort(t_stack **a, t_stack **b, int size)
{
	int	range;

	range = 1.3 * sqrt(size);
	while (*a)
	{
		if ((*a)->index <= ft_lstsize_ps(*b))
		{
			push(a, b, 'b', 1);
			rotate(b, 'b', 1);
		}
		else if ((*a)->index <= ft_lstsize_ps(*b) + range)
			push(a, b, 'b', 1);
		else
			rotate(a, 'a', 1);
	}
	move_back_to_a(a, b);
}

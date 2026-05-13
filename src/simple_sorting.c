/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 06:14:46 by luferna3          #+#    #+#             */
/*   Updated: 2026/05/13 04:46:59 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Returns the position (0-indexed from top) of the smallest value
int	smallest_pos(t_stack *stack_a)
{
	int	smallest;
	int	index;
	int	pos;

	index = 0;
	pos = 0;
	smallest = stack_a->value;
	while (stack_a)
	{
		if (stack_a->value < smallest)
		{
			smallest = stack_a->value;
			pos = index;
		}
		stack_a = stack_a->next;
		index++;
	}
	return (pos);
}

// Bring element at position pos to the top of stack_a optimally
static void	bring_to_top(t_stack **stack_a, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos--)
			rotate(stack_a, 'a', 1);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			reverse_rotate(stack_a, 'a', 1);
	}
}

void	three_nums(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)
		swap(stack_a, 'a', 1);
	else if (a > b && b > c)
	{
		swap(stack_a, 'a', 1);
		reverse_rotate(stack_a, 'a', 1);
	}
	else if (a > b && b < c && a > c)
		rotate(stack_a, 'a', 1);
	else if (a < b && b > c && a < c)
	{
		swap(stack_a, 'a', 1);
		rotate(stack_a, 'a', 1);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate(stack_a, 'a', 1);
}

void	four_nums(t_stack **stack_a, t_stack **stack_b)
{
	bring_to_top(stack_a, smallest_pos(*stack_a), 4);
	push(stack_a, stack_b, 'b', 1);
	three_nums(stack_a);
	push(stack_b, stack_a, 'a', 1);
}

void	five_nums(t_stack **stack_a, t_stack **stack_b)
{
	bring_to_top(stack_a, smallest_pos(*stack_a), 5);
	push(stack_a, stack_b, 'b', 1);
	bring_to_top(stack_a, smallest_pos(*stack_a), 4);
	push(stack_a, stack_b, 'b', 1);
	three_nums(stack_a);
	push(stack_b, stack_a, 'a', 1);
	push(stack_b, stack_a, 'a', 1);
}

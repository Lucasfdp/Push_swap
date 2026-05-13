/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 04:39:21 by luferna3          #+#    #+#             */
/*   Updated: 2026/05/13 04:39:22 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_result(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	b = NULL;
	a = get_stack(argc, argv);
	if (!a)
		return (write(2, "Error\n", 6), 1);
	read_instructions(&a, &b);
	check_result(a, b);
	free_lst(a);
	free_lst(b);
	return (0);
}

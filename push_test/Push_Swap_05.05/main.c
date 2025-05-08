/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 06:14:17 by luferna3          #+#    #+#             */
/*   Updated: 2025/05/08 06:15:30 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, char name)
{
	printf("Stack %c: ", name);
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

char	**handle_nums(int ac, char *av[], char **args, int count)
{
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args || !args[0])
			return (free_split(args, count), NULL);
		while (args[count])
			count++;
	}
	else
	{
		args = av + 1;
		count = ac - 1;
	}
	return (args);
}

void	handle_sort(t_stack **stack_a, t_stack **stack_b)
{
	int size = ft_lstsize_ps(*stack_a);
	int *array = (int *)malloc(size * sizeof(int));
	array = extracting_array(stack_a);
	sorting_array(array, size);
	assigning_index(stack_a, array);
	if (size == 2)
		swap(stack_a, 'a', 1);
	else if (size == 3)
		three_nums(stack_a);
	else if (size == 4)
		four_nums(stack_a, stack_b);
	else if (size == 5)
		five_nums(stack_a, stack_b);
	else if (size == 6)
		six_nums(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b, size);
}

int	main(int ac, char **av)
{
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	char	**args;
	int		count;

	a = NULL;
	b = NULL;
	args = NULL;
	count = 0;
	if (ac < 2)
		return (0);
	if (!(args = handle_nums(ac, av, args, count)))
		return (free_all(a, b, args, count), write(2, "Error\n", 6));
	if (!(a = get_stack(ac, av)))
		return (free_all(a, b, args, count), write(2, "Error\n", 6));
	handle_sort(&a, &b);
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 06:14:17 by luferna3          #+#    #+#             */
/*   Updated: 2025/05/24 23:31:10 by lucas            ###   ########.fr       */
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

char	**handle_nums(int ac, char *av[], char **args, int *count)
{
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args || !args[0])
			return (free_split(args, *count), NULL);
		while (args[*count])
			(*count)++;
	}
	else
	{
		args = av + 1;
		*count = ac - 1;
	}
	return (args);
}

int	check_order(t_stack **stack_a, int count)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack_a;
	while (i < count && tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		else
		{
			tmp = tmp->next;
			i++;
		}
	}
	return (1);
}

void	handle_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	*array;

	size = ft_lstsize_ps(*stack_a);
	if (size == 1)
		return ;
	array = extracting_array(stack_a);
	sorting_array(array, size);
	assigning_index(stack_a, array);
	if (check_order(stack_a, size))
		return ;
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
	free(array);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		count;
	int		overflow;

	a = NULL;
	b = NULL;
	args = NULL;
	count = 0;
	overflow = 0;
	if (ac < 2)
		return (0);
	args = handle_nums(ac, av, args, &count);
	if (!args)
		return (free_all(a, b, args, count), write(2, "Error\n", 6));
	if (count == 1 && is_within_int_range(args[0], overflow))
		return (free_all(a, b, args, count), 0);
	a = get_stack(ac, av);
	if (!a)
		return (write(2, "Error\n", 6));
	handle_sort(&a, &b);
	print_stack(a, 0);
	free_lst(a);
	free_lst(b);
	return (0);
}

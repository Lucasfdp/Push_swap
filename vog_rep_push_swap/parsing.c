/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 06:14:37 by luferna3          #+#    #+#             */
/*   Updated: 2025/05/20 04:59:32 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicate_num_check(t_stack *stack, int value)
{
	while (stack)
	{
		if (value == stack->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	valid_num_check(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	if (!num[i])
		return (0);
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

t_stack	*parse_args(int ac, char **av)
{
	t_stack	*stack;
	int		i;
	long	num;
	long	j;

	stack = NULL;
	i = 1;
	num = 0;
	while (i < ac)
	{
		if (!valid_num_check(av[i]))
			return (free_lst(stack), NULL);
		j = 0;
		num = ft_atoll(av[i], &j);
		if (num < INT_MIN || num > INT_MAX || duplicate_num_check(stack,
				(int)num) || j > 10)
			return (free_lst(stack), NULL);
		ft_lstadd_back_ps(&stack, ft_lstnew_ps((int)num));
		i++;
	}
	return (stack);
}

t_stack	*get_stack(int ac, char **av)
{
	char	**args;
	t_stack	*stack;
	int		i;

	i = 0;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args)
			return (NULL);
		i = 0;
		while (args[i])
			i++;
		stack = parse_args(i, args);
		free_split(args, i);
		return (stack);
	}
	else
		return (parse_args(ac, av));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmachlou <mmachlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:14:49 by mmachlou          #+#    #+#             */
/*   Updated: 2024/09/06 14:34:27 by mmachlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		ft_sa(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

void	error_first_number(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	exit(1);
}

static char	**get_arguments(int ac, char **av)
{
	char	**arg;

	if (ac == 2)
	{
		arg = ft_split(av[1], ' ');
		if (arg[1] == NULL)
		{
			error_first_number(NULL, NULL);
		}
	}
	else
		arg = av;
	return (arg);
}

static void	cleanup(int ac, char **arg, t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	if (ac == 2)
	{
		i = 0;
		while (arg[i])
			free(arg[i++]);
		free(arg);
	}
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**arg;
	int		stack_size;
	int		i;

	if (ac < 2)
		return (0);
	arg = get_arguments(ac, av);
	if (!is_input_correct(arg))
	{
		if (arg && ac == 2)
		{
			i = 0;
			while (arg[i])
				free(arg[i++]);
			free(arg);
		}
		error_exit(NULL, NULL);
	}
	stack_a = fill_stack_data(ac, arg);
	stack_b = NULL;
	stack_size = ft_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	cleanup(ac, arg, &stack_a, &stack_b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmachlou <mmachlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:54:47 by mmachlou          #+#    #+#             */
/*   Updated: 2024/09/06 14:31:59 by mmachlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	handle_error(t_stack **stack_a)
{
	free_stack(stack_a);
	error_exit(NULL, NULL);
}

static void	add_number_to_stack(t_stack **stack_a, long nb)
{
	t_stack	*new_node;

	new_node = new_stack((int)nb);
	if (!new_node)
		handle_error(stack_a);
	if (*stack_a == NULL)
		*stack_a = new_node;
	else
		add_stack_bottom(stack_a, new_node);
}

t_stack	*fill_stack_data(int ac, char **av)
{
	long	nb;
	int		i;
	t_stack	*stack_a;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	stack_a = NULL;
	while (av[i] != NULL)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			handle_error(&stack_a);
		add_number_to_stack(&stack_a, nb);
		i++;
	}
	return (stack_a);
}

void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*tmp;
	t_stack	*biggest;
	int		data;

	while (--stack_size > 0)
	{
		tmp = stack_a;
		data = INT_MIN;
		biggest = NULL;
		while (tmp)
		{
			if (tmp->data == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			if (tmp->data > data && tmp->index == 0)
			{
				data = tmp->data;
				biggest = tmp;
				tmp = stack_a;
			}
			else
				tmp = tmp->next;
		}
		if (biggest != NULL)
			biggest->index = stack_size;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmachlou <mmachlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:11:51 by mmachlou          #+#    #+#             */
/*   Updated: 2024/09/06 14:31:59 by mmachlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	tmp = stack;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_stack	*new_stack(int data)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->data = data;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	add_stack_bottom(t_stack **stack, t_stack *neww)
{
	t_stack	*last;

	last = *stack;
	if (!neww)
		return ;
	if (!(*stack))
	{
		*stack = neww;
		neww->next = NULL;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = neww;
	neww->next = NULL;
}

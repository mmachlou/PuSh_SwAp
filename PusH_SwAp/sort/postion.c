/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafa-machlouch <mustafa-machlouch@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:30:32 by mmachlou          #+#    #+#             */
/*   Updated: 2024/08/07 12:45:41 by mmachlou	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	pos_of_lowest_index(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

static int	get_target(t_stack **a, int b_x, int target_x, int target_p)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->index > b_x && tmp->index < target_x)
		{
			target_x = tmp->index;
			target_p = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_x != INT_MAX)
		return (target_p);
	tmp = *a;
	while (tmp)
	{
		if (tmp->index < target_x)
		{
			target_x = tmp->index;
			target_p = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (target_p);
}

void	pos_of_target(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_p;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	target_p = 0;
	while (tmp_b)
	{
		target_p = get_target(a, tmp_b->index, INT_MAX, target_p);
		tmp_b->target_pos = target_p;
		tmp_b = tmp_b->next;
	}
}

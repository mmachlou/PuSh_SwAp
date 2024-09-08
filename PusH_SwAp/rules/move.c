/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmachlou <mmachlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:26:35 by mmachlou          #+#    #+#             */
/*   Updated: 2024/09/06 14:31:59 by mmachlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rev_rot_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while ((*cost_a) < 0 && (*cost_b) < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_rrr(a, b);
	}
}

static void	rot_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while ((*cost_a) > 0 && (*cost_b) > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rr(a, b);
	}
}

static void	rot_a(t_stack **a, int *cost_a)
{
	while (*cost_a)
	{
		if ((*cost_a) > 0)
		{
			ft_ra(a);
			(*cost_a)--;
		}
		else if ((*cost_a) < 0)
		{
			ft_rra(a);
			(*cost_a)++;
		}
	}
}

static void	rot_b(t_stack **b, int *cost_b)
{
	while (*cost_b)
	{
		if ((*cost_b) > 0)
		{
			ft_rb(b);
			(*cost_b)--;
		}
		else if ((*cost_b) < 0)
		{
			ft_rrb(b);
			(*cost_b)++;
		}
	}
}

void	ft_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rot_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rot_both(a, b, &cost_a, &cost_b);
	rot_a(a, &cost_a);
	rot_b(b, &cost_b);
	ft_pa(a, b);
}

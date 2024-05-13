/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:04:11 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/04/24 01:11:20 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **stack_a, t_stack **stack_b
	, int *cost_a, int *cost_b)
{
	while (*cost_a && *cost_b)
	{
		rr(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b
	, int *cost_a, int *cost_b)
{
	while (*cost_a && *cost_b)
	{
		rrr(stack_a, stack_b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	rotate_a(t_stack **stack_a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			ra(stack_a);
			(*cost_a)--;
		}
		else
		{
			rra(stack_a);
			(*cost_a)++;
		}
	}
}

void	rotate_b(t_stack **stack_b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			rb(stack_b);
			(*cost_b)--;
		}
		else
		{
			rrb(stack_b);
			(*cost_b)++;
		}
	}
}

void	get_node_in_top(t_stack **stack_a, t_stack **stack_b
	, t_stack *cheap_node)
{
	int	cost_a;
	int	cost_b;	

	cost_a = cheap_node->cost_a;
	cost_b = cheap_node->cost_b;
	if (cost_a > 0 && cost_b > 0)
		rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a < 0 && cost_b < 0)
		reverse_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	rotate_a(stack_a, &cost_a);
	rotate_b(stack_b, &cost_b);
	pa(stack_a, stack_b);
}

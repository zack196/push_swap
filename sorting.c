/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:24:43 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/04/24 01:24:44 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ranking(t_stack **stack, int size_stack)
{
	t_stack	*ptr;
	t_stack	*node;
	int		i;
	int		min;

	i = -1;
	while (++i < size_stack)
	{
		ptr = *stack;
		node = NULL;
		min = 2147483647;
		while (ptr)
		{
			if (ptr->value == 2147483647 && ptr->rank == -1)
				ptr->rank = size_stack;
			if (min > ptr->value && ptr->rank == -1)
			{
				min = ptr->value;
				node = ptr;
			}
			ptr = ptr->next;
		}
		if (node)
			node->rank = i + 1;
	}
}

void	push_all_save_3(t_stack **stack_a, t_stack **stack_b)
{
	int	median;

	while (stack_size(*stack_a) > 3)
	{
		median = stack_median(*stack_a);
		if ((*stack_a)->rank >= median)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
	}
}

void	sort_3(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->value > (*stack)->next->next->value)
		ra(stack);
	if ((*stack)->next->value > (*stack)->next->next->value)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

t_stack	*node_to_push(t_stack *stack_b)
{
	t_stack	*ptr_b;
	t_stack	*push_node;
	int		cost;

	ptr_b = stack_b;
	push_node = stack_b;
	cost = val_abs(ptr_b->cost_a) + val_abs(ptr_b->cost_b);
	while (ptr_b)
	{
		if (cost > val_abs(ptr_b->cost_a) + val_abs(ptr_b->cost_b))
		{
			push_node = ptr_b;
			cost = val_abs(ptr_b->cost_a) + val_abs(ptr_b->cost_b);
		}
		ptr_b = ptr_b->next;
	}
	return (push_node);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*push_node;
	int		size;

	ranking(stack_a, stack_size(*stack_a));
	if (is_sorted(*stack_a) == 1 || stack_size(*stack_a) == 2)
		return ;
	push_all_save_3(stack_a, stack_b);
	sort_3(stack_a);
	size = stack_size(*stack_b);
	while (size--)
	{
		get_push_costs(stack_a, stack_b);
		push_node = node_to_push(*stack_b);
		get_node_in_top(stack_a, stack_b, push_node);
	}
	resort(stack_a);
}

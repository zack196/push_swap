/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:25:20 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/04/24 01:28:59 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*small_node(t_stack *stack)
{
	t_stack	*small;

	small = stack;
	while (stack)
	{
		if (stack->value < small->value)
			small = stack;
		stack = stack->next;
	}
	return (small);
}

int	stack_median(t_stack *stack)
{
	int		median;
	t_stack	*ptr;

	median = 0;
	ptr = stack;
	while (ptr)
	{
		median = median + ptr->rank;
		ptr = ptr->next;
	}
	median = median / stack_size(stack);
	return (median);
}

t_stack	*target_node(t_stack *stack_a, t_stack *node)
{
	t_stack	*target;

	target = NULL;
	while (stack_a)
	{
		if (node->value < stack_a->value && !target)
			target = stack_a;
		else if (node->value < stack_a->value && stack_a->value < target->value)
			target = stack_a;
		stack_a = stack_a->next;
	}
	if (!target)
		target = small_node(stack_a);
	return (target);
}

void	set_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*ptr_b;
	t_stack	*target;

	ptr_b = *stack_b;
	while (ptr_b)
	{
		target = target_node(*stack_a, ptr_b);
		ptr_b->target = target;
		ptr_b = ptr_b->next;
	}
}

void	get_push_costs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*ptr_b;
	t_stack	*target;
	int		size_a;
	int		size_b;

	ptr_b = *stack_b;
	size_a = stack_size(*stack_a) / 2;
	size_b = stack_size(*stack_b) / 2;
	set_target(stack_a, stack_b);
	while (ptr_b)
	{
		target = ptr_b->target;
		ptr_b->cost_b = ptr_b->index;
		if (ptr_b->index > size_b)
			ptr_b->cost_b = ptr_b->index - stack_size(*stack_b);
		ptr_b->cost_a = target->index;
		if (target->index > size_a)
			ptr_b->cost_a = target->index - stack_size(*stack_a);
		ptr_b = ptr_b->next;
	}
}

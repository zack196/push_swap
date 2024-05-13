/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:00:48 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/04/24 01:00:48 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*last;
	t_stack	*seconde_node;

	if (stack_size(*stack) < 2)
		return ;
	last = last_node(*stack);
	first_node = *stack;
	seconde_node = (*stack)->next;
	first_node->next = NULL;
	last->next = first_node;
	*stack = seconde_node;
}

void	ra(t_stack **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
	indexing(stack);
}

void	rb(t_stack **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
	indexing(stack);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	indexing(stack_a);
	indexing(stack_b);
	write(1, "rr\n", 3);
}

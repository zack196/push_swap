/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:58:32 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/04/24 00:58:32 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*seconde_last;

	last = last_node(*stack);
	seconde_last = *stack;
	while (seconde_last->next->next)
		seconde_last = seconde_last->next;
	last->next = *stack;
	seconde_last->next = NULL;
	*stack = last;
}

void	rra(t_stack **stack)
{
	reverse_rotate(stack);
	indexing(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack)
{
	reverse_rotate(stack);
	indexing(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	indexing(stack_a);
	indexing(stack_b);
	write(1, "rrr\n", 4);
}

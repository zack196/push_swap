/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:13:59 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/04/24 01:14:21 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resort(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*small;

	ptr = *stack;
	small = small_node(*stack);
	if (small->index > stack_size(*stack) / 2)
	{
		while (small->index != 0)
			rra(stack);
	}
	else
	{
		while (small->index != 0)
			ra(stack);
	}
}

int	val_abs(int val)
{
	if (val < 0)
		return (-1 * val);
	return (val);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

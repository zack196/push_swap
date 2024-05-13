/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 06:25:46 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/04/25 13:13:47 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*ptr;

	ptr = stack;
	while (ptr->next)
	{
		if (ptr->value > ptr->next->value)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = fill_in_stack(ac, av);
	if (!stack_a || stack_size(stack_a) == 1)
		free_stack(&stack_a);
	else if (stack_size(stack_a) == 3)
		sort_3(&stack_a);
	else if (stack_size(stack_a) == 2 && !is_sorted(stack_a))
		sa(&stack_a);
	else
		sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

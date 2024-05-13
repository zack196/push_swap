/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_fct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:47:53 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/04/25 10:25:36 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*creat_node(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof (t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->rank = -1;
	new->target = NULL;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	add_node(t_stack **list, t_stack *new)
{
	t_stack	*ptr;

	if (new == NULL)
	{
		free_stack(list);
		return ;
	}
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	ptr = *list;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	indexing(list);
}

void	indexing(t_stack **stack)
{
	t_stack	*ptr;
	int		index;

	if (!*stack)
		return ;
	ptr = *stack;
	index = 0;
	while (ptr)
	{
		ptr->index = index;
		index++;
		ptr = ptr->next;
	}
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack	*last_node(t_stack *stack)
{
	t_stack	*ptr;

	ptr = stack;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

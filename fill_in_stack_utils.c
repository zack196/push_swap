/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_in_stack_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:37:37 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/04/25 07:47:27 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_str(char **s)
{
	int	i;

	if (!s || !*s)
		return ;
	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	s = NULL;
}

int	is_digit(char d)
{
	if ('0' <= d && d <= '9')
		return (1);
	return (0);
}

long	ft_atol(char *str)
{
	long	nbr;
	long	sign;

	sign = 1;
	nbr = 0;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (is_digit(*str))
	{
		nbr = (*str - '0') + 10 * nbr;
		if (sign * nbr > 2147483647 || sign * nbr < -2147483648)
			return (2147483648);
		str++;
	}
	return (sign * nbr);
}

void	error_message(char **s, t_stack *stack)
{
	free_str(s);
	free_stack(&stack);
	write(2, "Error\n", 6);
	exit(1);
}

int	node_existe(t_stack *stack, int nb)
{
	while (stack)
	{
		if (stack->value == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}

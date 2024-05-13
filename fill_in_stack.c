/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_in_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:41:46 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/04/25 12:36:35 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**append(char **str_nbr, char *nbr)
{
	char	**res;
	int		size;

	size = 0;
	if (!nbr)
		return (str_nbr);
	if (str_nbr)
		while (str_nbr[size])
			size++;
	res = malloc((size + 2) * sizeof (char *));
	if (!res)
		return (NULL);
	res[size + 1] = NULL;
	res[size] = ft_strdup(nbr);
	while (size--)
		res[size] = ft_strdup(str_nbr[size]);
	free_str(str_nbr);
	return (res);
}

char	**fill_char_stack(int ac, char **av)
{
	char	**res;
	char	**split;
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
		{
			free_str(res);
			return (NULL);
		}
		if (av[i] && !*split)
		{
			free_str(split);
			error_message(res, NULL);
		}
		j = -1;
		while (split[++j])
			res = append(res, split[j]);
		free_str(split);
	}
	return (res);
}

int	check2(char *nb)
{
	if ((*nb == '-' || *nb == '+') && *(nb + 1))
		nb++;
	while (*nb)
	{
		if (!is_digit(*nb))
			return (0);
		nb++;
	}
	return (1);
}

int	check(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!check2(s[i]))
			return (0);
		i++;
	}
	return (1);
}

t_stack	*fill_in_stack(int ac, char *av[])
{
	char	**s;
	int		i;
	long	nb;
	t_stack	*stack;

	s = fill_char_stack(ac, av);
	if (!s)
		return (NULL);
	stack = NULL;
	if (check(s) == 0)
		error_message(s, stack);
	i = -1;
	while (s[++i])
	{
		nb = ft_atol(s[i]);
		if (nb == 2147483648 || node_existe(stack, nb))
			error_message(s, stack);
		add_node(&stack, creat_node((int)nb));
	}
	free_str(s);
	return (stack);
}

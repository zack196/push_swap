/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 06:25:06 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/04/25 11:23:29 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	num_word(char const *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static int	word(char const *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

static void	free_mal(char **res, int i)
{
	while (i >= 0)
	{
		free(res[i]);
		res[i--] = NULL;
	}
	free(res);
	res = NULL;
}

static char	*extract(char const *s, char c)
{
	int		c_word;
	char	*res;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	c_word = word(s, c);
	res = ft_substr(s, 0, c_word);
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		nbr_word;
	int		i;

	nbr_word = num_word(s, c);
	i = 0;
	res = (char **)malloc((nbr_word + 1) * sizeof(char *));
	if (!res || !s)
		return (free(res), NULL);
	while (i < nbr_word)
	{
		while (*s == c)
			s++;
		res[i] = extract(s, c);
		if (res[i] == NULL)
		{
			free_mal(res, i);
			return (0);
		}
		i++;
		while (*s && *s != c)
			s++;
	}
	res[i] = NULL;
	return (res);
}

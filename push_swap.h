/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:59:43 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/04/25 13:14:04 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				rank;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
	struct s_stack	*target;
}	t_stack;

void	add_node(t_stack **list, t_stack *new);
t_stack	*creat_node(int value);
void	indexing(t_stack **stack);
int		stack_size(t_stack *stack);
t_stack	*last_node(t_stack *stack);

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

void	ranking(t_stack **stack, int size_stack);
void	push_all_save_3(t_stack **stack_a, t_stack **stack_b);
void	sort_3(t_stack **stack);

int		stack_median(t_stack *stack);
void	sort(t_stack **stack_a, t_stack **stack_b);

t_stack	*target_node(t_stack *stack_a, t_stack *stack_b);
t_stack	*node_to_push(t_stack *stack_b);
void	resort(t_stack **stack);
t_stack	*small_node(t_stack *stack);
int		val_abs(int val);
int		is_sorted(t_stack *stack);
void	free_str(char **s);
int		node_existe(t_stack *stack, int nb);
void	error_message(char **s, t_stack *stack);
int		is_digit(char d);
t_stack	*fill_in_stack(int ac, char *av[]);

void	rotate_both(t_stack **stack_a, t_stack **stack_b,
			int *cost_a, int *cost_b);
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b,
			int *cost_a, int *cost_b);
void	rotate_a(t_stack **stack_a, int *cost_a);
void	rotate_b(t_stack **stack_b, int *cost_b);
void	get_node_in_top(t_stack **stack_a, t_stack **stack_b,
			t_stack *cheap_node);
void	set_target(t_stack **stack_a, t_stack **stack_b);
void	get_push_costs(t_stack **stack_a, t_stack **stack_b);
t_stack	*set_target_pos(t_stack **stack_a, t_stack **stack_b);

void	free_stack(t_stack **stack);
char	*ft_strdup(const char *s1);
long	ft_atol(char *str);

#endif
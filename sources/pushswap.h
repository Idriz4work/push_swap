/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:43 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/12 19:23:01 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/Libft/get_next_line/get_next_line.h"
# include "../includes/Libft/libft.h"
# include "../includes/ft_printf/ft_printf_bonus.h"
# include "big_o.h"
# include <limits.h>

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}			t_stack_top;

typedef struct s_order{
	int order_of_a;
	int order_of_b;
} rot_number;

typedef struct t_casehandler
{
	long	first;
	long	second;
	long	last;
	long	average;
}			t_case;

// algorithm
void		osman_sort_algorithm(t_list **stack_a, t_list **stack_b, int *op);
void		osman_sort_algorithm_two(t_list **stack_a, t_list **stack_b,
				int *op);
// void		calculator_op(t_list *stack_a, t_list **stack_b, int *op_count);
void		handle_edge_three_two(t_list **stack_a, t_list **stack_b, t_case *n,
				int *count);
void		handle_edge_three(t_list **stack_a, t_list **stack_b, t_case *n,
				int *count);
void		handle_edge_four_two(t_list **stack_a, t_list **stack_b, t_case *n,
				int *count);
void		handle_edge_four(t_list **stack_a, t_list **stack_b, t_case *n,
				int *count);

// void		merge(t_stack_top *stak, int left[], int right[]);
// void		merge_sort(t_stack_top **stacks);
// void	merge_sort_recursion(t_stack_top **stak, int left, int right);
// void		merge_sort_array(t_stack_top **stak, int left, int mid, int right);

// Operation function declarations with operation counter
void		print_stack(t_list **stak);
void		push_a(long value, t_list **stack_a,t_list **stack_b, int *op_count);
void		push_b(long value, t_list **stack_b,t_list **stack_a, int *op_count);
void		pop(t_list **stack);

t_list*		rotate(t_list *stack);
void		rotate_a(t_list **stack_a, int *op_count);
void		rotate_b(t_list **stack_b, int *op_count);
void		rotate_anb(t_list **stack_a, t_list **stack_b, int *op_count);
void		reverse_rotate_a(t_list **stack_a, int *op_count);
void		reverse_rotate_b(t_list **stack_b, int *op_count);
void		swap_a(t_list **stak, int *op_count);
void		swap_b(t_list **stak, int *op_count);
void		sa_ab_same(t_list **stak_a, t_list **stak_b, int *op_count);
void		reverse_rotate_rrr(t_list **stak_a, t_list **stak_b, int *op_count);

// Edge case handlers with operation counter
void		handle_edge_three_two(t_list **stack_a, t_list **stack_b, t_case *n,
				int *op_count);
void		handle_edge_three(t_list **stack_a, t_list **stack_b, t_case *n,
				int *op_count);
void		handle_edge_four_two(t_list **stack_a, t_list **stack_b, t_case *n,
				int *op_count);
void		handle_edge_four(t_list **stack_a, t_list **stack_b, t_case *n,
				int *op_count);

// utils
int			check_sorted(t_list *stack_a);
int			initialize_stack(t_list **stack_a, t_list **stack_b);
static int	is_valid_number(char *str);
int			handle_ops(char **argv);
long		ft_atol(char *s);
int			calculate_biggest(t_list **stack_a);

#endif
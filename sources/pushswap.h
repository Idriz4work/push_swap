/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:43 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/02 05:24:01 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/Libft/get_next_line/get_next_line.h"
# include "../includes/Libft/libft.h"
# include "../includes/ft_printf/ft_printf_bonus.h"
# include <limits.h>

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}			t_stack_top;

typedef struct t_casehandler
{
	long	first;
	long	second;
	long	last;
} t_case;


// algorithm
void		osman_sort_algorithm(t_list **stack_a, t_list **stack_b);
//void	handle_edge_three_two(t_list **stack_a, t_list **stack_b, t_case *n);
//void	handle_edge_three(t_list **stack_a, t_list **stack_b);
//void	handle_edge_four(t_list **stack_a, t_list **stack_b, t_case *n);
//void	process_values(t_list **stack_a, t_list **stack_b);


// void		merge(t_stack_top *stak, int left[], int right[]);
// void		merge_sort(t_stack_top **stacks);
// // void	merge_sort_recursion(t_stack_top **stak, int left, int right);
// void		merge_sort_array(t_stack_top **stak, int left, int mid, int right);

// Function to handle operations for the push_swap project
void		print_stack(t_list **stak);
// void		handle_ops(void);
void		rotate_a(t_list **stack_a);
void		rotate_b(t_list **stack_b);
void		rotate_anb(t_list **stack_a, t_list **stack_b);
void		reverse_rotate_a(t_list **stack_a);
void		reverse_rotate_b(t_list **stack_b);
void		reverse_rotate_rrr(t_list **stack_a, t_list **stack_b);
void		swap_a(t_list **stack_a);
void		swap_b(t_list **stack_b);
void		sa_ab_same(t_list **stack_a, t_list **stack_b);
void		push_a(long value, t_list **stack_a);
void		push_b(long value, t_list **stack_b);
void		pop_a(t_list **stack_a);
void		pop_b(t_list **stack_b);

// utils
int			check_sorted(t_list *stack_a);
int			initialize_stack(t_list **stack_a, t_list **stack_b);
static int	is_valid_number(char *str);
int			handle_ops(char **argv);

#endif
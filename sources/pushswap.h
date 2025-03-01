/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:43 by iatilla-          #+#    #+#             */
/*   Updated: 2025/03/01 22:17:46 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../includes/Libft/get_next_line/get_next_line.h"
# include "../includes/Libft/libft.h"
# include "../includes/ft_printf/ft_printf_bonus.h"
# include <limits.h>

// #ifndef RO
# define ROTATE 1
# define REV_ROTATE -1

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}			t_stack_top;

typedef struct s_order
{
	int		order_of_a;
	int		order_of_b;
	int		order_rev_a;
	int		order_rev_b;
	int		best_ind;
	int		rev_up_or_down;
}			t_rot;

typedef struct t_casehandler
{
	long	first;
	long	second;
	long	third;
	long	last;
}			t_case;

typedef struct t_up_or_down
{
	int		uu;
	int		ud;
	int		du;
	int		dd;
}			t_updown;

// ----------------------------
// Algorithm Functions
// ----------------------------
void		osman_sort_algorithm(t_list **stack_a, t_list **stack_b);
void		osman_sort_algorithm_two(t_list **stack_a, t_list **stack_b);
void		handle_rotation_a(t_rot *rots, t_list **stack_a);
void		handle_rotation_b(t_rot *rots, t_list **stack_b);
void		check_for_top_min(t_list **stack_a, t_list **stack_b);
void		handle_rotation_a(t_rot *rots, t_list **stack_a);
void		handle_rotation_b(t_rot *rots, t_list **stack_b);
void		position_decider_a(int position, int stack_size, t_rot *rots);
void		position_decider_b(int position, int stack_size, t_rot *rots);
void		initialize_rotation(t_rot *rots);
int			calculator_op(t_list *stack_a, t_list *stack_b, t_rot *rots);
void		update_up_down(t_updown *up_down, t_rot *rots);

// ----------------------------
// Functions for Calculator
// ----------------------------
int			get_right_index(int index, t_list *stack_a);
int			smallest(int a, int b, int c, int d);
int			short_index_finder(int *number_ops, int length);
int			find_next_largest(int top, t_list **stack_b);
int			find_largest_position(t_list **stack_b);
void		cost_of_gettop_a(int current, t_list **stack_a, t_rot *rots);
void		cost_moving_position_b(int num, t_list **stack_b, t_rot *rots);

// ----------------------------
// Hardcoded Functions for 3 and 4 Stack Size
// ----------------------------
// Main function declarations for handling different stack sizes
void		handle_edge_three(t_list **stack_a, t_case *n);
void		handle_edge_four(t_list **stack_a, t_list **stack_b, t_case *n);
void		handle_edge_five(t_list **stack_a, t_list **stack_b, t_case *n);

// Helper function declarations
void		handle_edge_three_two(t_list **stack_a, t_case *n);
void		handle_edge_four_two(t_list **stack_a, t_case *n);
int			find_min_position(t_list **stack);

// ----------------------------
// Operations Functions
// ----------------------------
void		push_a(long value, t_list **stack_a, t_list **stack_b);
void		push_b(long value, t_list **stack_b, t_list **stack_a);
void		pop(t_list **stack);
void		rotate_a(t_list **stack_a);
void		rotate_b(t_list **stack_b);
void		rotate_anb(t_list **stack_a, t_list **stack_b);
void		reverse_rotate_a(t_list **stack_a);
void		reverse_rotate_b(t_list **stack_b);
void		swap_a(t_list **stak);
void		swap_b(t_list **stak);
void		sa_ab_same(t_list **stak_a, t_list **stak_b);
void		reverse_rotate_rrr(t_list **stak_a, t_list **stak_b);

// ----------------------------
// Utility Functions
// ----------------------------
int			check_sorted(t_list *stack_a);
int			initialize_stack(t_list **stack_a, t_list **stack_b);
int			is_valid_number(char *str);
int			handle_ops(char **argv);
long		ft_atol(char *s);
void		print_stack(t_list **stak);
int			is_valid_number(char *str);
int			is_valid_integer_range(long num);
int			check_for_duplicates(char **argv, int current_index);

// ----------------------------
// Helper Functions
// ----------------------------
void		forwords_sorter(t_list **stack_b, int num_rotates);
void		backwards_sorter(t_list **stack_b, int num_reverse_op);
int			find_largest_position(t_list **stack_b);
void		cleanup_and_exit(t_list **stack_a, t_list **stack_b, int status);
void		process_values(t_list **stack_a, t_list **stack_b);
int			process_values_two(char **values);

void		filler(char **values, t_list **stack_a, int i);
t_list		*fill_stack(char **values, t_list **stack_a, t_list **stack_b);

#endif

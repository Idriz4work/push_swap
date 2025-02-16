/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   egde_case_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 06:42:54 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/16 16:58:58 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// helper function for handle_egde_three
void	handle_edge_three_two(t_list **stack_a, t_list **stack_b, t_case *n)
{
	n->first = (long)((*stack_a)->content);
	n->second = (long)((*stack_a)->next->content);
	n->last = (long)((*stack_a)->next->next->content);
	if (n->first > n->second && n->first > n->last && n->second < n->last)
	{
		rotate_a(stack_a);
		return ;
	}
	if (n->second > n->first && n->second > n->last && n->first < n->last)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
		return ;
	}
	if (n->first > n->second && n->first < n->last)
	{
		swap_a(stack_a);
		return ;
	}
	if (n->first < n->second && n->first > n->last)
		reverse_rotate_a(stack_a);
}

// hardcoded function makes sure that minimal number
// of opeartions occur for 3 numbers in stack a
void	handle_edge_three(t_list **stack_a, t_list **stack_b, t_case *n)
{
	n->first = (long)((*stack_a)->content);
	n->second = (long)((*stack_a)->next->content);
	n->last = (long)((*stack_a)->next->next->content);
	if (n->first < n->second && n->second < n->last)
		return ;
	if (n->first > n->second && n->second > n->last)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
		return ;
	}
	else
		handle_edge_three_two(stack_a, stack_b, n);
}

// helper function for handle_egde_four
void	handle_edge_four_two(t_list **stack_a, t_list **stack_b, t_case *n)
{
	long	third;

	n->first = (long)((*stack_a)->content);
	n->second = (long)((*stack_a)->next->content);
	third = (long)((*stack_a)->next->next->content);
	n->last = (long)((*stack_a)->next->next->next->content);
	if (n->first > n->second && n->second < third && third < n->last
		&& n->first < third)
		swap_a(stack_a);
	else if (n->first > n->second && n->first > third && n->first > n->last
		&& n->first > third)
		rotate_a(stack_a);
	else if (n->first > n->second && n->second < third && third < n->last
		&& n->first > third)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
}

// hardcoded function makes sure that minimal number
// of opeartions occur for 4 numbers in stack a
void	handle_edge_four(t_list **stack_a, t_list **stack_b, t_case *n)
{
	long	third;

	n->first = (long)((*stack_a)->content);
	n->second = (long)((*stack_a)->next->content);
	third = (long)((*stack_a)->next->next->content);
	n->last = (long)((*stack_a)->next->next->next->content);
	// print_stack(stack_a);
	if (n->first < n->second && n->second < third && third < n->last)
		return ;
	push_b((long)(void *)(*stack_a)->content, stack_b, stack_a);
	handle_edge_three(stack_a, stack_b, n);
	push_a((long)(*stack_b)->content, stack_a, stack_b);
	handle_edge_four_two(stack_a, stack_b, n);
}



// helper function for handle_egde_four
void	handle_edge_five_two(t_list **stack_a, t_list **stack_b, t_case *n)
{
	long	third;
	long	forth;

	n->first = (long)((*stack_a)->content);
	n->second = (long)((*stack_a)->next->content);
	third = (long)((*stack_a)->next->next->content);
	forth = (long)(*stack_a)->next->next->next->content;
	n->last = (long)((*stack_a)->next->next->next->next->content);
	if (n->first > n->second && n->second < third && third < n->last
		&& n->first < third)
		swap_a(stack_a);
	else if (n->first > n->second && n->first > third && n->first > n->last
		&& n->first > third)
		rotate_a(stack_a);
	else if (n->first > n->second && n->second < third && third < n->last
		&& n->first > third)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
}

// hardcoded function makes sure that minimal number
// of opeartions occur for 4 numbers in stack a
void	handle_edge_five(t_list **stack_a, t_list **stack_b, t_case *n)
{
	long	third;
	long	forth;

	n->first = (long)((*stack_a)->content);
	n->second = (long)((*stack_a)->next->content);
	third = (long)((*stack_a)->next->next->content);
	forth = (long)(*stack_a)->next->next->next->content;
	n->last = (long)((*stack_a)->next->next->next->next->content);
	// print_stack(stack_a);
	if (n->first < n->second && n->second < third && third < forth
		&& forth < n->last)
		return ;
	push_b((long)(void *)(*stack_a)->content, stack_b, stack_a);
	handle_edge_four(stack_a, stack_b, n);
	push_a((long)(*stack_b)->content, stack_a, stack_b);
	print_stack(stack_a);
	handle_edge_five_two(stack_a, stack_b, n);
}

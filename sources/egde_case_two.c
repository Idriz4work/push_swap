/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   egde_case_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:03:07 by iatilla-          #+#    #+#             */
/*   Updated: 2025/03/01 22:03:46 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	egde_four_two_helper(t_list **stack_a, t_case *n)
{
	if (n->second > n->first && n->second > n->third && n->second > n->last)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (n->third > n->first && n->third > n->second && n->third > n->last)
		reverse_rotate_a(stack_a);
	else if (n->first > n->last && n->last < n->second)
		reverse_rotate_a(stack_a);
}

void	handle_edge_four_two(t_list **stack_a, t_case *n)
{
	n->first = (long)((*stack_a)->content);
	n->second = (long)((*stack_a)->next->content);
	n->third = (long)((*stack_a)->next->next->content);
	n->last = (long)((*stack_a)->next->next->next->content);
	if (n->first > n->second && n->second < n->third && n->third < n->last
		&& n->first < n->third)
		swap_a(stack_a);
	else if (n->first > n->second && n->first > n->third && n->first > n->last)
		rotate_a(stack_a);
	else if (n->first > n->second && n->second < n->third && n->third < n->last
		&& n->first > n->third)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else
		egde_four_two_helper(stack_a, n);
}

void	egde_four_helper(t_list **stack_a, t_list **stack_b, t_case *n)
{
	if (n->second <= n->first && n->second <= n->third && n->second <= n->last)
	{
		swap_a(stack_a);
		push_b((long)(*stack_a)->content, stack_b, stack_a);
	}
	else if (n->third <= n->first && n->third <= n->second
		&& n->third <= n->last)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
		push_b((long)(*stack_a)->content, stack_b, stack_a);
	}
	else
	{
		reverse_rotate_a(stack_a);
		push_b((long)(*stack_a)->content, stack_b, stack_a);
	}
}

void	handle_edge_four(t_list **stack_a, t_list **stack_b, t_case *n)
{
	n->first = (long)((*stack_a)->content);
	n->second = (long)((*stack_a)->next->content);
	n->third = (long)((*stack_a)->next->next->content);
	n->last = (long)((*stack_a)->next->next->next->content);
	if (n->first < n->second && n->second < n->third && n->third < n->last)
		return ;
	if (n->first <= n->second && n->first <= n->third && n->first <= n->last)
		push_b((long)(*stack_a)->content, stack_b, stack_a);
	else
		egde_four_helper(stack_a, stack_b, n);
	handle_edge_three(stack_a, n);
	push_a((long)(*stack_b)->content, stack_a, stack_b);
	handle_edge_four_two(stack_a, n);
}

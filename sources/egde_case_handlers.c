/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   egde_case_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 06:42:54 by iatilla-          #+#    #+#             */
/*   Updated: 2025/03/01 22:03:43 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// Helper function for handle_edge_three
void	handle_edge_three_two(t_list **stack_a, t_case *n)
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

void	handle_edge_three(t_list **stack_a, t_case *n)
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
		handle_edge_three_two(stack_a, n);
}

// Helper function to find position of minimum number
int	find_min_position(t_list **stack)
{
	t_list	*current;
	long	min;
	int		min_pos;
	int		current_pos;

	current = *stack;
	min = (long)(current->content);
	min_pos = 0;
	current_pos = 0;
	while (current)
	{
		if ((long)(current->content) < min)
		{
			min = (long)(current->content);
			min_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (min_pos);
}

void	handle_edge_five(t_list **stack_a, t_list **stack_b, t_case *n)
{
	int	min_pos;

	min_pos = find_min_position(stack_a);
	while (min_pos > 0)
	{
		if (min_pos <= 2)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
		min_pos = find_min_position(stack_a);
	}
	push_b((long)(*stack_a)->content, stack_b, stack_a);
	handle_edge_four(stack_a, stack_b, n);
	push_a((long)(*stack_b)->content, stack_a, stack_b);
}

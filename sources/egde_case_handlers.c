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

// Helper function for handle_edge_three
void    handle_edge_three_two(t_list **stack_a, t_case *n)
{
    n->first = (long)((*stack_a)->content);
    n->second = (long)((*stack_a)->next->content);
    n->last = (long)((*stack_a)->next->next->content);
    if (n->first > n->second && n->first > n->last && n->second < n->last)
    {
        rotate_a(stack_a);
        return;
    }
    if (n->second > n->first && n->second > n->last && n->first < n->last)
    {
        swap_a(stack_a);
        rotate_a(stack_a);
        return;
    }
    if (n->first > n->second && n->first < n->last)
    {
        swap_a(stack_a);
        return;
    }
    if (n->first < n->second && n->first > n->last)
        reverse_rotate_a(stack_a);
}

void    handle_edge_three(t_list **stack_a, t_case *n)
{
    n->first = (long)((*stack_a)->content);
    n->second = (long)((*stack_a)->next->content);
    n->last = (long)((*stack_a)->next->next->content);
    if (n->first < n->second && n->second < n->last)
        return;
    if (n->first > n->second && n->second > n->last)
    {
        swap_a(stack_a);
        reverse_rotate_a(stack_a);
        return;
    }
    else
        handle_edge_three_two(stack_a, n);
}

void    handle_edge_four_two(t_list **stack_a, t_case *n)
{
    long    third;

    n->first = (long)((*stack_a)->content);
    n->second = (long)((*stack_a)->next->content);
    third = (long)((*stack_a)->next->next->content);
    n->last = (long)((*stack_a)->next->next->next->content);
    if (n->first > n->second && n->second < third && third < n->last
        && n->first < third)
        swap_a(stack_a);
    else if (n->first > n->second && n->first > third && n->first > n->last)
        rotate_a(stack_a);
    else if (n->first > n->second && n->second < third && third < n->last
        && n->first > third)
    {
        reverse_rotate_a(stack_a);
        swap_a(stack_a);
        rotate_a(stack_a);
        rotate_a(stack_a);
    }
    else if (n->second > n->first && n->second > third && n->second > n->last)
    {
        swap_a(stack_a);
        rotate_a(stack_a);
    }
    else if (third > n->first && third > n->second && third > n->last)
        reverse_rotate_a(stack_a);
    else if (n->first > n->last && n->last < n->second)
        reverse_rotate_a(stack_a);
}

void    handle_edge_four(t_list **stack_a, t_list **stack_b, t_case *n)
{
    long third;
    n->first = (long)((*stack_a)->content);
    n->second = (long)((*stack_a)->next->content);
    third = (long)((*stack_a)->next->next->content);
    n->last = (long)((*stack_a)->next->next->next->content);
    
    if (n->first < n->second && n->second < third && third < n->last)
        return;
    
    if (n->first <= n->second && n->first <= third && n->first <= n->last)
        push_b((long)(void *)(*stack_a)->content, stack_b, stack_a);
    else if (n->second <= n->first && n->second <= third && n->second <= n->last)
    {
        swap_a(stack_a);
        push_b((long)(void *)(*stack_a)->content, stack_b, stack_a);
    }
    else if (third <= n->first && third <= n->second && third <= n->last)
    {
        rotate_a(stack_a);
        rotate_a(stack_a);
        push_b((long)(void *)(*stack_a)->content, stack_b, stack_a);
    }
    else
    {
        reverse_rotate_a(stack_a);
        push_b((long)(void *)(*stack_a)->content, stack_b, stack_a);
    }
    
    handle_edge_three(stack_a, n);  // Fixed: Removed stack_b argument
    push_a((long)(*stack_b)->content, stack_a, stack_b);
    handle_edge_four_two(stack_a, n);
}

// Helper function to find position of minimum number
int find_min_position(t_list **stack)
{
	t_list *current = *stack;
	long min = (long)(current->content);
	int min_pos = 0;
	int current_pos = 0;
	
	while (current) {
		if ((long)(current->content) < min) {
			min = (long)(current->content);
			min_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	
	return min_pos;
}

void handle_edge_five(t_list **stack_a, t_list **stack_b, t_case *n)
{
    // Find the smallest number and push it to stack_b
    int min_pos = find_min_position(stack_a);
    
    // Rotate until minimum is at top
    while (min_pos > 0) {
        if (min_pos <= 2) {
            rotate_a(stack_a);
        } else {
            reverse_rotate_a(stack_a);
        }
        min_pos = find_min_position(stack_a);
    }
    
    // Push minimum to stack_b
    push_b((long)(void *)(*stack_a)->content, stack_b, stack_a);
    
    // Handle remaining 4 numbers
    handle_edge_four(stack_a, stack_b, n);
    
    // Push back the minimum number which will automatically be in correct position
    push_a((long)(*stack_b)->content, stack_a, stack_b);
}


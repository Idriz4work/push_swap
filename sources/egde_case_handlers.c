/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   egde_case_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 06:42:54 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/07 11:24:23 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    handle_edge_three_two(t_list **stack_a, t_list **stack_b, t_case *n, int *op_count)
{
    n->first = (long)((*stack_a)->content);
    n->second = (long)((*stack_a)->next->content);
    n->last = (long)((*stack_a)->next->next->content);

    if (n->first > n->second && n->first > n->last && n->second < n->last)
    {
        rotate_a(stack_a,op_count);
        return;
    }
    if (n->second > n->first && n->second > n->last && n->first < n->last)
    {
        swap_a(stack_a,op_count);
        rotate_a(stack_a,op_count);
        return;
    }
    if (n->first > n->second && n->first < n->last)
    {
        swap_a(stack_a,op_count);
        return;
    }
    if (n->first < n->second && n->first > n->last)
        reverse_rotate_a(stack_a,op_count);
}

void    handle_edge_three(t_list **stack_a, t_list **stack_b, t_case *n, int *op_count)
{
    n->first = (long)((*stack_a)->content);
    n->second = (long)((*stack_a)->next->content);
    n->last = (long)((*stack_a)->next->next->content);

    if (n->first < n->second && n->second < n->last)
        return;
    if (n->first > n->second && n->second > n->last)
    {
        swap_a(stack_a,op_count);
        reverse_rotate_a(stack_a,op_count);
        return;
    }
    else
        handle_edge_three_two(stack_a, stack_b, n, op_count);
}

void    handle_edge_four_two(t_list **stack_a, t_list **stack_b, t_case *n, int *op_count)
{
    long    third;

    n->first = (long)((*stack_a)->content);
    n->second = (long)((*stack_a)->next->content);
    third = (long)((*stack_a)->next->next->content);
    n->last = (long)((*stack_a)->next->next->next->content);

    if (n->first > n->second && n->second < third && third < n->last && n->first < third)
        swap_a(stack_a,op_count);
    else if (n->first > n->second && n->first > third && n->first > n->last && n->first > third)
        rotate_a(stack_a,op_count);
    else if (n->first > n->second && n->second < third && third < n->last && n->first > third)
    {
        reverse_rotate_a(stack_a,op_count);
        swap_a(stack_a,op_count);
        rotate_a(stack_a,op_count);
        rotate_a(stack_a,op_count);
    }
}

void    handle_edge_four(t_list **stack_a, t_list **stack_b, t_case *n, int *op_count)
{
    long    third;

    n->first = (long)((*stack_a)->content);
    n->second = (long)((*stack_a)->next->content);
    third = (long)((*stack_a)->next->next->content);
    n->last = (long)((*stack_a)->next->next->next->content);

    if (n->first < n->second && n->second < third && third < n->last)
        return;
    
    push_b((long)(void *)(*stack_a)->content, stack_b,op_count);
    pop(stack_a);

    handle_edge_three(stack_a, stack_b, n, op_count);
    
    push_a((long)(*stack_b)->content, stack_a,op_count);
    pop(stack_b);

    handle_edge_four_two(stack_a, stack_b, n, op_count);
}
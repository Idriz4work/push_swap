/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:46 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/02 03:55:11 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


void rotate_a(t_list **stack_a)
{
    t_list *first;
    t_list *last;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    first = *stack_a;
    *stack_a = first->next;
    last = *stack_a;
    while (last->next != NULL)
        last = last->next;
    last->next = first;
    first->next = NULL;
    ft_printf("ra\n");
}

void rotate_b(t_list **stack_b)
{
    t_list *first;
    t_list *last;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    first = *stack_b;
    *stack_b = first->next;
    last = *stack_b;
    while (last->next != NULL)
        last = last->next;
    last->next = first;
    first->next = NULL;
    ft_printf("rb\n");
}

void rotate_anb(t_list **stack_a, t_list **stack_b)
{
    rotate_a(stack_a);
    rotate_b(stack_b);
    ft_printf("rr\n");
}

void reverse_rotate_a(t_list **stack_a)
{
    t_list *head;
    t_list *last;

    last = ft_lstlast(*stack_a);
    if (*stack_a == NULL || (*stack_a)->next == NULL || !last)
        return;
    head = *stack_a;
    while (head->next->next != NULL)
        head = head->next;
    head->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
    ft_printf("rra\n");
}

void reverse_rotate_b(t_list **stack_b)
{    
	t_list *head;
    t_list *last;

    last = ft_lstlast(*stack_b);
    if (*stack_b == NULL || (*stack_b)->next == NULL || !last)
        return;
    head = *stack_b;
    while (head->next->next != NULL)
        head = head->next;
    head->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
    ft_printf("rrb\n");
}
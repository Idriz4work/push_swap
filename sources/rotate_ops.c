/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:46 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/14 22:19:53 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// Rotates stack_a: Moves the first element to the last position.
void	rotate_a(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	ft_printf("ra\n");
}

// Rotates stack_b: Moves the first element to the last position.
void	rotate_b(t_list **stack_b)
{
	t_list	*first;
	t_list	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	ft_printf("rb\n");
}

// Rotates both stack_a and stack_b: Moves the first element of each stack to the last position.
void	rotate_anb(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_printf("rr\n");
}
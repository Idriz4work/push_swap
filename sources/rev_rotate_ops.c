/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:16:30 by iatilla-          #+#    #+#             */
/*   Updated: 2025/03/01 21:53:39 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// Reverse rotates stack_a: Moves the last element to the first position.
void	reverse_rotate_a(t_list **stack_a)
{
	t_list	*head;
	t_list	*last;

	last = ft_lstlast(*stack_a);
	if (*stack_a == NULL || (*stack_a)->next == NULL || !last)
		return ;
	head = *stack_a;
	while (head->next->next != NULL)
		head = head->next;
	head->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	ft_printf("rra\n");
}

// Reverse rotates stack_b: Moves the last element to the first position.
void	reverse_rotate_b(t_list **stack_b)
{
	t_list	*head;
	t_list	*last;

	last = ft_lstlast(*stack_b);
	if (*stack_b == NULL || (*stack_b)->next == NULL || !last)
		return ;
	head = *stack_b;
	while (head->next->next != NULL)
		head = head->next;
	head->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	ft_printf("rrb\n");
}

// Reverse rotates both stack_a and stack_b: Moves the
// last element of each stack to the first position.
void	reverse_rotate_rrr(t_list **stak_a, t_list **stak_b)
{
	reverse_rotate_a(stak_a);
	reverse_rotate_b(stak_b);
	ft_printf("rrr\n");
}

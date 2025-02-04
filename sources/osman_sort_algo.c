/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osman_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:46:08 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/04 13:47:40 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	osman_sort_algorithm_two(t_list **stack_a, t_list **stack_b)
{
}


t_list	*copy_stack_a(t_list **stack_a, t_list **stack_b, t_list *tmp)
{
	t_case	n;

	n.value = 0;
	n.first = (long)(*stack_a)->content;
	tmp = *stack_a;
	while (tmp != NULL)
	{
		n.value = (long)tmp->content;
		if (n.first > n.value)
			n.first = n.value;
		tmp = tmp->next;
	}
	tmp = *stack_a;
	while (tmp != NULL)
	{
		if ((long)tmp->content != n.first)
			push_b((long)tmp->content, stack_b);
		tmp = tmp->next;
	}
	while (*stack_a != NULL)
		pop_a(stack_a);
	push_a(n.first, stack_a);
	tmp = *stack_b;
	return tmp;
}

void	osman_sort_algorithm(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_case	n;
	t_list	*prev;

	prev = NULL;
	tmp = NULL;
	n.value = 0;
	n.size = 0;
	tmp = copy_stack_a(stack_a, stack_b, tmp);
	while (tmp != NULL)
	{
		if ((long)tmp->content == n.first)
		{
			if (prev)
				prev->next = tmp->next;
			else
				*stack_b = tmp->next;
			free(tmp);
			break ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	n.size = ft_lstsize(*stack_b);
	// ft_printf("size: %i\n\n", n.size);
	if (n.size == 4)
	{
		handle_edge_four_two(stack_b, stack_a, &n);
		while ((*stack_b) != NULL)
		{
			push_a((long)(void *)(*stack_b)->content,stack_a);
			pop_b(stack_b);
		}
	}
	else
		osman_sort_algorithm_two(stack_a, stack_b);
	// push_a((long) (void*)stack_b,stack_a);
}

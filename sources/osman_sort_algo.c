/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osman_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:46:08 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/05 17:36:35 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	osman_sort_algorithm_third(t_list **stack_a, t_list **stack_b,
		int *op_count)
{
}


void	osman_sort_algorithm_two(t_list **stack_a, t_list **stack_b,
		int *op_count)
{
	t_case	n;
	t_list	*tmp;
	t_list	*last_node;
	int		list_size;
	int		i;

	i = 0;
	list_size = ft_lstsize(*stack_b);
	tmp = (*stack_b);
	last_node = ft_lstlast(*stack_b);
	while (i < list_size - 1 && tmp != NULL)
	{
		if ((long)(void *)tmp->content < (long)last_node->content)
			rotate_b(stack_b, op_count);
		tmp = tmp->next;
		i++;
	}
	if (ft_lstsize(*stack_a) == 4)
		handle_edge_four(stack_a, stack_b, &n, op_count);
	osman_sort_algorithm_third(stack_a,stack_b,op_count);
	while ((*stack_b))
	{
		push_a((long)(void *)(*stack_b)->content, stack_a, op_count);
		pop_b(stack_b);
	}
}

void	osman_sort_algorithm(t_list **stack_a, t_list **stack_b, int *op_count)
{
	t_case	n;
	long	size;
	long	list_size;
	t_list	*tmp;

	// Step 1: Calculate the average of stack_a
	n.average = calculate_average(stack_a);
	list_size = ft_lstsize(*stack_a);
	// Step 2: Iterate through stack_a and move elements greater than average to stack_b
	size = 0;
	while (size < list_size)
	{
		tmp = *stack_a; // Always work with the current head of stack_a
		if ((long)tmp->content < n.average)
		{
			push_b((long)tmp->content, stack_b, op_count);
			pop_a(stack_a); // Remove from stack_a after pushing
		}
		else
			rotate_a(stack_a, op_count);
		// Move current node to the bottom to keep stack order
		size++;
	}
	// Step 3: Print stacks for debugging
	print_stack(stack_a);
	print_stack(stack_b);
	// Step 4: Continue sorting the remaining elements
	osman_sort_algorithm_two(stack_a, stack_b, op_count);
	// Step 3: Print stacks for debugging
	print_stack(stack_a);
	print_stack(stack_b);
}

// t_list	*copy_stack_a(t_list **stack_a, t_list **stack_b, t_list *tmp,
// 		t_case *n)
// {
// 	n->value = 0;
// 	n->last = (long)(*stack_a)->content;
// 	tmp = *stack_a;
// 	while (tmp != NULL)
// 	{
// 		n->value = (long)tmp->content;
// 		if (n->last < n->value)
// 			n->last = n->value;
// 		tmp = tmp->next;
// 	}
// 	tmp = *stack_a;
// 	while (tmp != NULL)
// 	{
// 		if ((long)tmp->content != n->last)
// 			push_b((long)tmp->content, stack_b);
// 		tmp = tmp->next;
// 	}
// 	while (*stack_a != NULL)
// 		pop_a(stack_a);
// 	push_a(n->last, stack_a);
// 	tmp = *stack_b;
// 	// ft_printf("b: ");
// 	// print_stack(stack_b);
// 	// ft_printf("\na: ");
// 	// print_stack(stack_a);
// 	return (tmp);
// }

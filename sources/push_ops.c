/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:15:34 by iatilla-          #+#    #+#             */
/*   Updated: 2025/03/01 21:52:06 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// Removes the top element from the stack.
void	pop(t_list **stack)
{
	t_list	*temp;

	if (*stack == NULL)
		return ;
	temp = *stack;
	*stack = temp->next;
	free(temp);
	temp = NULL;
}

// Pushes a value onto stack_a, and pops the top element from stack_b.
void	push_a(long value, t_list **stack_a, t_list **stack_b)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		exit(EXIT_FAILURE);
	newnode->content = (void *)(long)value;
	newnode->next = *stack_a;
	*stack_a = newnode;
	pop(stack_b);
	ft_printf("pa\n");
}

// Pushes a value onto stack_b, and pops the top element from stack_a.
void	push_b(long value, t_list **stack_b, t_list **stack_a)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		exit(EXIT_FAILURE);
	newnode->content = (void *)(long)value;
	newnode->next = *stack_b;
	*stack_b = newnode;
	pop(stack_a);
	ft_printf("pb\n");
}

// Prints all elements in the stack, followed by a newline.
void	print_stack(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current != NULL)
	{
		ft_printf("%d ", (long)current->content);
		current = current->next;
	}
	ft_printf("\n");
}

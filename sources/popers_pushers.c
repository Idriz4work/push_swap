/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popers_pushers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:32:38 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/07 11:21:04 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_a(long value, t_list **stack_a, int *op_count)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		exit(EXIT_FAILURE);
	newnode->content = (void *)(long)value;
	newnode->next = *stack_a;
	*stack_a = newnode;
	(*op_count)++;
	ft_printf("pa\n");
}

void	push_b(long value, t_list **stack_b, int *op_count)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		exit(EXIT_FAILURE);
	newnode->content = (void *)(long)value;
	newnode->next = *stack_b;
	*stack_b = newnode;
	(*op_count)++;
	ft_printf("pb\n");
}

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

void	print_stack(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current != NULL)
	{
		ft_printf("%d ", current->content);
		current = current->next;
	}
	ft_printf("\n");
}

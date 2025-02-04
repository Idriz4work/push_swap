/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popers_pushers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:32:38 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/04 10:36:42 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_a(long value, t_list **stack_a)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		exit(EXIT_FAILURE);
	newnode->content = (void *)(long)value;
	newnode->next = *stack_a;
	*stack_a = newnode;
	ft_printf("pa\n");
}

void	push_b(long value, t_list **stack_b)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		exit(EXIT_FAILURE);
	newnode->content = (void *)(long)value;
	newnode->next = *stack_b;
	*stack_b = newnode;
	ft_printf("pb\n");
}

void	pop_a(t_list **stack_a)
{
	t_list	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = temp->next;
	free(temp);
	temp = NULL;
}

void	pop_b(t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = temp->next;
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

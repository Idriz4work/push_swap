/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:40 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/02 05:26:20 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	handle_edge_three_two(t_list **stack_a, t_list **stack_b, t_case *n)
{
	n->first = (long)((*stack_a)->content);
	n->second = (long)((*stack_a)->next->content);
	n->last = (long)((*stack_a)->next->next->content);
	if (n->first > n->second && n->first > n->last && n->second < n->last)
	{
		rotate_a(stack_a);
		return ;
	}
	if (n->second > n->first && n->second > n->last && n->first < n->last)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
		return ;
	}
	if (n->first > n->second && n->first < n->last)
	{
		swap_a(stack_a);
		return ;
	}
	if (n->first < n->second && n->first > n->last)
		reverse_rotate_a(stack_a);
}

void	handle_edge_three(t_list **stack_a, t_list **stack_b, t_case *n)
{
	n->first = (long)((*stack_a)->content);
	n->second = (long)((*stack_a)->next->content);
	n->last = (long)((*stack_a)->next->next->content);
	if (n->first < n->second && n->second < n->last)
		return ;
	if (n->first > n->second && n->second > n->last)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
		return ;
	}
	else
		handle_edge_three_two(stack_a, stack_b, n);
}

void	handle_edge_four(t_list **stack_a, t_list **stack_b, t_case *n)
{
	long	third;

	n->first = (long)((*stack_a)->content);
	n->second = (long)((*stack_a)->next->content);
	third = (long)((*stack_a)->next->next->content);
	n->last = (long)((*stack_a)->next->next->next->content);
	// if a < b < c < d
	if (n->first < n->second && n->second < third && third < n->last)
		return ;
	push_b((long)(void *)(*stack_a)->content,stack_b);
	pop_a(stack_a);
	handle_edge_three(stack_a,stack_b,n);
	push_a((long)(*stack_b)->content,stack_a);
	pop_b(stack_b);
}

void	process_values(t_list **stack_a, t_list **stack_b)
{
	int		value;
	t_case	n;

	n.first = 0;
	n.last = 0;
	n.second = 0;
	value = ft_lstsize(*stack_a);
	if (value == 2)
	{
		n.first = (long)((*stack_a)->content);
		n.second = (long)((*stack_a)->next->content);
		if (n.first > n.second)
			swap_a(stack_a);
	}
	else if (value == 3)
		handle_edge_three(stack_a, stack_b, &n);
	else if (value == 4)
		handle_edge_four(stack_a, stack_b, &n);
	else
		osman_sort_algorithm(stack_a, stack_b);
}

t_list	*fill_stack(char **values)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 1;
	if (initialize_stack(&stack_a, &stack_b) == -1)
	{
		ft_printf("Error\n");
		return (NULL);
	}
	while (values[i] != NULL)
		i++;
	i--;
	while (i >= 1)
		push_a(ft_atoi(values[i--]), &stack_a);
	// print_stack(&stack_a);
	process_values(&stack_a, &stack_b);
	// print_stack(&stack_a);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stak;

	if (argc < 2)
		return (-1);
	if (handle_ops(argv) == -1)
		return (-2);
	stak = fill_stack(argv);
	if (stak == NULL)
		return (-3);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:40 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/04 16:49:55 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	{
		if (ft_atol(values[i]) > 2147483647 || ft_atol(values[i]) < -2147483648)
		{
			ft_printf("Error\n");
			return (NULL);
		}
		i++;
	}
	i--;
	while (i >= 1)
		push_a(ft_atoi(values[i--]), &stack_a);
	// print_stack(&stack_a);
	process_values(&stack_a, &stack_b);
	ft_printf("b: ");
	print_stack(&stack_b);
	ft_printf("\na: ");
	print_stack(&stack_a);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	if (argc <= 2)
		return (-1);
	if (handle_ops(argv) == -1)
		return (-2);
	if (fill_stack(argv) == NULL)
		return (-3);
	return (0);
}

// #include <stdio.h>
// #include <limits.h>

// int main() {
//     printf("Max long: %ld\n", LONG_MAX);
//     printf("Max unsigned long: %lu\n", ULONG_MAX);
//     return (0);
// }

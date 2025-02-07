/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:40 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/07 14:47:03 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	process_values(t_list **stack_a, t_list **stack_b)
{
	int		value;
	t_case	n;
	int		op_count;

	n.first = 0;
	n.last = 0;
	n.second = 0;
	value = ft_lstsize(*stack_a);
	op_count = 0;
	if (value == 2)
	{
		n.first = (long)((*stack_a)->content);
		n.second = (long)((*stack_a)->next->content);
		if (n.first > n.second)
			swap_a(stack_a, &op_count);
	}
	else if (value == 3)
		handle_edge_three(stack_a, stack_b, &n, &op_count);
	else if (value == 4)
		handle_edge_four(stack_a, stack_b, &n, &op_count);
	else
		osman_sort_algorithm(stack_a, stack_b, &op_count);
	print_stack(stack_a);
	print_stack(stack_b);
	// osmani_iki(stack_a,stack_b,&op_count);
	ft_printf("-----------------\nOP COUNT: %i\n----------------", op_count);
}

int	process_values_two(char **values)
{
	int	i;

	i = 1;
	while (values[i] != NULL)
	{
		if (ft_atol(values[i]) > 2147483647 || ft_atol(values[i]) < -2147483648)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
			return (-1);
		}
		i++;
	}
	i--;
	return (i);
}

void	filler(char **values, t_list **stack_a, int i)
{
	t_list	*newnode;

	while (i >= 1)
	{
		newnode = (t_list *)malloc(sizeof(t_list));
		if (!newnode)
			exit(EXIT_FAILURE);
		newnode->content = (void *)(long)ft_atoi(values[i--]);
		newnode->next = (*stack_a);
		(*stack_a) = newnode;
	}
}

t_list	*fill_stack(char **values)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 0;
	if (initialize_stack(&stack_a, &stack_b) == -1)
	{
		ft_printf("Error\n");
		return (NULL);
	}
	i = process_values_two(values);
	filler(values, &stack_a, i);
	process_values(&stack_a, &stack_b);
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
//     t_list      *stack_a;
// t_list      *stack_b;
// t_analyzer  analyzer;

// if (argc < 2)
//     return (0);

// stack_a = NULL;
// stack_b = NULL;

// Initialize stack_a with your numbers
// ... your existing initialization code ...

// // Initialize analyzer with stack size
// init_analyzer(&analyzer, argc - 1);  //  argc - 1 is your stack size

// // Your sorting algorithm
// sort_stacks(&stack_a, &stack_b, &analyzer);

// // Print analysis at the end
// analyze_push_swap(&analyzer);

// Free your stacks
// ... your existing cleanup code ...

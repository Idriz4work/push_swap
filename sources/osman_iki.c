/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osman_iki.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:45:50 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/12 18:06:39 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// calculates the number of ops that it takes to rotate the num value which is the current number in the given stack (a or b)
// int	cost_of_gettop_a(int current, t_list **stack_a)
// {
// 	int		num_ops;
// 	t_list	*tmp;
// 	int		i;

// 	i = 0;
// 	tmp = (*stack_a);
// 	num_ops = 0;
// 	while ((long)tmp->content != current)
// 	{
// 		num_ops++;
// 		tmp = tmp->next;
// 	}
// 	// ft_printf("[%i] this is number of rotates to top A:%i\n ",current,num_ops);
// 	return (num_ops);
// }

// // finds the number that needs to be 1 before the top value which means that the number needs to be
// // rotated to the top and then the top value gets pushed to the top
// int	find_next_smallest(int top, t_list **stack_b)
// {
// 	int		current;
// 	t_list	*tmp;

// 	tmp = (*stack_b);
// 	current = INT_MAX; // Start with maximum possible value
// 	while (tmp)
// 	{
// 		// Find the closest smaller number
// 		if ((long)tmp->content < top && (long)tmp->content > current)
// 			current = (long)tmp->content;
// 		tmp = tmp->next;
// 	}
// 	// If no valid smaller number is found, return a special value
// 	return ((current == INT_MAX) ? -1 : current);
// }

// // calculates the number of rotate ops to put the num above the number
// // which would result in the number that is nearest to it (the number that is excep)
// int	cost_moving_position_b(int num, t_list **stack_b)
// {
// 	int		num_ops;
// 	t_list	*tmp;

// 	num_ops = 0;
// 	tmp = *stack_b;
// 	num = find_next_smallest(num, stack_b);
// 	while (tmp)
// 	{
// 		if ((long)tmp->content > num)
// 		{
// 			num_ops++;
// 			if (tmp == (*stack_b))
// 				break ;
// 		}
// 		tmp = tmp->next;
// 	}
// 	// ft_printf("this is rotataion ops for B: %i\n",num_ops);
// 	return (num_ops);
// }

// // goes throu all elemnts in stack a and calculates the moves to put current value
// // into right position in stack b,
// // the index of shortest number of ops gets returned
// int	calculator_op(t_list *stack_a, t_list *stack_b, int *op_count,
// 		rot_number *rotations)
// {
// 	int		i;
// 	int		index;
// 	int		shortest;
// 	int		*number_ops;
// 	t_list	*tmp;

// 	index = 0;
// 	i = 0;
// 	shortest = INT_MAX;
// 	number_ops = malloc(sizeof(int) * ft_lstsize(stack_a) + 1);
// 	if (!number_ops)
// 		exit(EXIT_FAILURE);
// 	tmp = stack_a;
// 	print_stack(&stack_a);
// 	while (tmp)
// 	{
// 		//
// 		rotations->order_of_a = cost_of_gettop_a((long)tmp->content, &stack_a);
// 		rotations->order_of_b = cost_moving_position_b((long)tmp->content,
// 				&stack_b);
// 		// ft_printf("ops: %i\n", rotations->order_of_b);
// 		number_ops[i] = rotations->order_of_a + rotations->order_of_b;
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	i--;
// 	while (i >= 0)
// 	{
// 		// ft_printf("i: %i, value-1: %i\n", i, number_ops[i]);
// 		if (number_ops[i] < shortest)
// 		{
// 			shortest = number_ops[i];
// 			index = i;
// 		}
// 		i--;
// 	}
// 	return (index);
// }


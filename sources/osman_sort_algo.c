/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osman_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:46:08 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/12 19:27:28 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// this is the last function that makes sure that everything is sorted in the ascending order in stack a
// this gets called last

void	forwords_sorter(t_list **stack_b, int num_rotates, int *op_count)
{
	while (num_rotates > 0)
	{
		rotate_b(stack_b, op_count);
		num_rotates--;
	}
}

void	backwards_sorter(t_list **stack_b, int num_reverse_op, int *op_count)
{
	while (num_reverse_op > 0)
	{
		reverse_rotate_b(stack_b, op_count);
		num_reverse_op--;
	}
}

void	check_for_top_max(t_list **stack_a, t_list **stack_b, int *op_count,
		rot_number *rots)
{
	int		largest;
	t_list	*tmp;
	int		position;
	int		current_pos;
	int		stack_size;

	ft_printf("CHECK FOR RIGHT ORDER OF STACK B\n");
	// Reset variables for each iteration
	largest = INT_MIN;
	position = 0;
	current_pos = 0;
	tmp = *stack_b;
	stack_size = ft_lstsize(*stack_b);
	// Find largest number and its position
	while (tmp)
	{
		if ((long)tmp->content > largest)
		{
			largest = (long)tmp->content;
			position = current_pos;
		}
		tmp = tmp->next;
		current_pos++;
	}
	// Choose rotation direction and perform rotations
	// If position is less than half of stack_size, rotate forward
	// Otherwise, rotate backward to bring the largest element to the top
	if (position <= stack_size / 2)
		forwords_sorter(stack_b, position, op_count); // Rotate forward for ascending order
	else
		backwards_sorter(stack_b, stack_size - position, op_count); // Reverse rotate for descending order

	ft_printf("PUSHING STACK B 2 STACK A\n");
	rotate_b(stack_b,op_count);
	printf("STACK B: \n");
	print_stack(stack_b); // Print stack B for debugging
	// Now push elements from Stack B to Stack A
	while (*stack_b)
		push_a((long)(*stack_b)->content, stack_a, stack_b, op_count);
}

// calculates the number of ops that it takes to rotate the num value which is the current number in the given stack (a or b)
int	cost_of_gettop_a(int current, t_list **stack_a)
{
	int		num_ops;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = (*stack_a);
	num_ops = 0;
	while ((long)tmp->content != current)
	{
		num_ops++;
		tmp = tmp->next;
	}
	// ft_printf("[%i] this is number of rotates to top A:%i\n ",current,num_ops);
	return (num_ops);
}

// finds the number that needs to be 1 before the top value which means that the number needs to be
// rotated to the top and then the top value gets pushed to the top
// finds the number that should be right before the given top value in descending order
int	find_next_smallest(int top, t_list **stack_b)
{
	int		current;
	t_list	*tmp;

	tmp = (*stack_b);
	current = INT_MIN; // Start with minimum possible value
	while (tmp)
	{
		// Find the largest number that's still smaller than top
		// printf("Cur: %i contender: %i\n", current, (int)tmp->content);
		if ((long)tmp->content < top && (long)tmp->content > current)
			current = (long)tmp->content;
		tmp = tmp->next;
	}
	// If no valid smaller number is found, return the largest number in stack_b
	if (current == INT_MIN)
	{
		tmp = (*stack_b);
		current = (long)tmp->content;
		while (tmp)
		{
			if ((long)tmp->content > current)
				current = (long)tmp->content;
			tmp = tmp->next;
		}
	}
	// printf("Next smallest for %i is %i\n", top, current);
	return (current);
}

// calculates the number of rotate ops to put the num above the number
// which would result in the number that is nearest to it (the number that is excep)
// calculates the number of rotate operations needed to put the number in correct position
int	cost_moving_position_b(int num, t_list **stack_b)
{
	int		num_ops;
	t_list	*tmp;
	int		target;

	num_ops = 0;
	tmp = *stack_b;
	target = find_next_smallest(num, stack_b);
	// First, find the position of the target number
	while (tmp && (long)tmp->content != target)
	{
		num_ops++;
		tmp = tmp->next;
	}
	// If we found the target, we need one more rotation to position above it
	if (tmp)
		num_ops = (num_ops + 1) % ft_lstsize(*stack_b);
	return (num_ops);
}

// goes throu all elemnts in stack a and calculates the moves to put current value
// into right position in stack b,
// the index of shortest number of ops gets returned
int	calculator_op(t_list *stack_a, t_list *stack_b, int *op_count,
		rot_number *rotations)
{
	int		i;
	int		index;
	int		shortest;
	int		*number_ops;
	t_list	*tmp;

	index = 0;
	i = 0;
	shortest = INT_MAX;
	number_ops = malloc(sizeof(int) * ft_lstsize(stack_a) + 1);
	if (!number_ops)
		exit(EXIT_FAILURE);
	tmp = stack_a;
	// print_stack(&stack_b);
	while (tmp)
	{
		//
		rotations->order_of_a = cost_of_gettop_a((long)tmp->content, &stack_a);
		rotations->order_of_b = cost_moving_position_b((long)tmp->content,
				&stack_b);
		// ft_printf("ops: %i\n", rotations->order_of_b);
		number_ops[i] = rotations->order_of_a + rotations->order_of_b;
		tmp = tmp->next;
		i++;
	}
	i--;
	while (i >= 0)
	{
		// ft_printf("i: %i, value-1: %i\n", i, number_ops[i]);
		if (number_ops[i] < shortest)
		{
			shortest = number_ops[i];
			index = i;
		}
		i--;
	}
	return (index);
}

// rotate the stack until the value of the top value in stack a gets pushed into the right position
//
void	osman_sort_algorithm_two(t_list **stack_a, t_list **stack_b,
		int *op_count)
{
	t_list		*tmp;
	rot_number	rotations;
	int			list_size;
	int			i;
	int			shortest_op;

	tmp = (*stack_a);
	i = 0;
	list_size = ft_lstsize(*stack_a);
	while (i < list_size)
	{
		shortest_op = calculator_op(tmp, *stack_b, op_count, &rotations);
		// ft_printf("num of ops (osman sort): %i\n", shortest_op);
		// ft_printf("number of rotations for a: [%i]\nnumber of rotations for b: [%i]\n",
		// rotations.order_of_a, rotations.order_of_b);
		while (rotations.order_of_a > 0)
		{
			rotate_a(stack_a, op_count);
			rotations.order_of_a--;
		}
		while (rotations.order_of_b > 0)
		{
			rotate_b(stack_b, op_count);
			rotations.order_of_b--;
		}
		// ft_printf("pushed value to b: [%i]\n", (long)(*stack_a)->content);
		push_b((long)(*stack_a)->content, stack_b, stack_a, op_count);
		// print_stack(stack_b);
		// ft_printf("----------[%i ROUND]----------------\n", i);
		i++;
	}
}

// n.average = calculate_average(stack_a);
void	osman_sort_algorithm(t_list **stack_a, t_list **stack_b, int *op_count)
{
	t_case		n;
	rot_number	rots;

	// push 2 values to stack b
	push_b((long)(*stack_a)->content, stack_b, stack_a, op_count);
	push_b((long)(*stack_a)->content, stack_b, stack_a, op_count);
	osman_sort_algorithm_two(stack_a, stack_b, op_count);
	print_stack(stack_b);
	// final check
	check_for_top_max(stack_a, stack_b, op_count, &rots);
}

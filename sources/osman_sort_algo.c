/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osman_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:46:08 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/12 14:44:32 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// do something more hardcoded
// this is the last function that makes sure that everything is sorted in the ascending order in stack a
// this gets called last
void	check_for_top_min(t_list **stack_a,t_list **stack_b, int *op_count)
{
	int		i;
	t_case	n;
	t_list	*tmp;

	i = 0;
	ft_printf("CHECK FOR RIGHT ORDER OF STACK B\n");
	tmp = (*stack_b);
	n.first = (long)(*stack_b)->content;
	n.second = (long)(*stack_b)->next->content;
	while (n.first < n.second && (*stack_b)->next != NULL)
	{
		rotate_b(stack_b, op_count);
		n.first = (long)(*stack_b)->content;
		n.second = (long)(*stack_b)->next->content;
	}
	print_stack(stack_b);
	ft_printf("PUSHING STACK B 2 STACK A\n");
	while (*stack_b)
		push_a((long)(*stack_b)->content,stack_a,stack_b,op_count);
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
	// ft_printf("[%i] this is number of rotates to top A: %i\n",current,num_ops);
	return (num_ops);
}

int	find_next_smallest(int top, t_list **stack_b)
{
	int		current;
	t_list	*tmp;

	tmp = (*stack_b);
	current = INT_MAX; // Start with maximum possible value
	while (tmp)
	{
		// Find the closest smaller number
		if ((long)tmp->content < top && (long)tmp->content > current)
			current = (long)tmp->content;
		tmp = tmp->next;
	}
	// If no valid smaller number is found, return a special value
	return ((current == INT_MAX) ? -1 : current);
}

// calculates the number of rotate ops to put the num above the number
// which would result in the number that is nearest to it (the number that is excep)
int	cost_moving_position_b(int num, t_list **stack_b)
{
	int		num_ops;
	t_list	*tmp;

	num_ops = 0;
	tmp = *stack_b;
	num = find_next_smallest(num, stack_b);
	while (tmp)
	{
		if ((long)tmp->content > num)
		{
			num_ops++;
			if (tmp == (*stack_b))
				break ;
		}
		tmp = tmp->next;
	}
	// ft_printf("this is rotataion ops for B: %i\n",num_ops);
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
	print_stack(&stack_a);
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
		ft_printf("num of ops (osman sort): %i\n", shortest_op);
		
		ft_printf("number of rotations for a: [%i]\nnumber of rotations for b: [%i]\n",rotations.order_of_a, rotations.order_of_b);
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
		ft_printf("pushed value to b: [%i]\n",(long)(*stack_a)->content);
		push_b((long)(*stack_a)->content, stack_b, stack_a, op_count);
		print_stack(stack_b);
		ft_printf("----------[%i ROUND]----------------\n",i);
		i++;
	}
}

// n.average = calculate_average(stack_a);
void	osman_sort_algorithm(t_list **stack_a, t_list **stack_b, int *op_count)
{
	t_case	n;

	// push 2 values to stack b
	push_b((long)(*stack_a)->content, stack_b, stack_a, op_count);
	push_b((long)(*stack_a)->content, stack_b, stack_a, op_count);
	osman_sort_algorithm_two(stack_a, stack_b, op_count);
	print_stack(stack_a);
	print_stack(stack_b);
	// final check
	check_for_top_min(stack_a,stack_b, op_count);
}

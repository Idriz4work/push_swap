/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osman_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:46:08 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/07 16:00:29 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_for_top_min(t_list **stack_a, int *op_count)
{
	int		i;
	t_case	n;
	t_list	*tmp;

	i = 0;
	tmp = (*stack_a);
	n.first = (long)(*stack_a)->content;
	n.second = (long)(*stack_a)->next->content;
	while (n.first < n.second && (*stack_a)->next != NULL)
	{
		rotate_a(stack_a, op_count);
		n.first = (long)(*stack_a)->content;
		n.second = (long)(*stack_a)->next->content;
	}
}

// fixed
int	cost_of_gettop_a(int num, t_list *stack)
{
	int		res;
	t_list	*tmp;

	tmp = stack;
	res = 0;
	while (num != (long)tmp->content && tmp)
	{
		res++;
		rotate(&tmp);
		if (stack == tmp)
			break;
	}
	return (res);
}

// calculates the number of rotate ops to put the num above the number
// which would result in the number that is nearest to it (the number that is excep)
int	cost_moving_position_b(int num, t_list *stack)
{
	int		res;
	t_list	*tmp;

	res = 0;
	tmp = stack;
	while (tmp)
	{
		if ((long)tmp->content > num)
		{
			rotate(&tmp);
			if (tmp == stack)
				break;
		}
		if (res > ft_lstsize(stack))
			break;
		res++;
	}
	if (num < (long)tmp->content)
		res++; // this would be now the push cmd
	return (res);
}



void	put_on_top_a(int num_of_ops, t_list **stack, int *op_count)
{
	while (num_of_ops > 0)
	{
		rotate_a(stack, op_count);
		num_of_ops--;
	}
}

// pushes the top value of 
void push_to_right_position(int top_stack_value, t_list **stack_a, t_list **stack_b, int *op_count)
{
	int		res;
	t_list	*tmp;

	res = 0;
	tmp = (*stack_b);
	while (tmp)
	{
		if ((long)tmp->content > top_stack_value)
		{
			rotate_a(stack_a,op_count);
			rotate(&tmp);
			if (tmp == (*stack_b))
				break;
		}
		if (res > ft_lstsize(*stack_b))
			break;
		res++;
	}
	if (top_stack_value < (long)tmp->content)
		push_b(top_stack_value,stack_b,op_count);
}

// goes throu all elemnts in stack a and calculates the moves to put current value
// into right position in stack b, the shortest number of ops gets returned
int	calculator_op(t_list *stack, t_list **stack_b, int *op_count)
{
	int		i;
	int		index;
	int		ops;
	int		shortest;
	int		*number_ops;
	t_list	*tmp;

	index = 0;
	i = 0;
	ops = 0;
	shortest = 0;
	number_ops = malloc(sizeof(int) * ft_lstsize(stack) + 1);
	if (!number_ops)
		exit(EXIT_FAILURE);
	tmp = stack;
	while (tmp)
	{
		ops = cost_of_gettop_a((long)tmp->content, stack);
		ops += cost_moving_position_b((long)tmp->content, *stack_b);
		number_ops[i++] = ops;
		tmp = tmp->next;
	}
	while (i > 0)
	{
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
void	osman_sort_algorithm_third(t_list **stack_a, t_list **stack_b,
		int *op_count, int index_shortest)
{
	// t_list	*tmp;

	put_on_top_a(index_shortest, stack_a, op_count);
	push_to_right_position((long)(*stack_a)->content,stack_a,stack_b,op_count);
	// tmp = (*stack_b);
	// while ((long)(*stack_a)->content > (long)(*stack_b)->content && tmp)
	// {
	// 	rotate_b(stack_b, op_count);
	// 	if ((*stack_b) == NULL)
	// 		break ;
	// 	tmp = tmp->next;
	// }
}

void	osman_sort_algorithm_two(t_list **stack_a, t_list **stack_b,
		int *op_count)
{
	t_list	*tmp;
	int		list_size;
	int		i;
	int		shortest_op;

	i = 0;
	tmp = (*stack_a);
	list_size = ft_lstsize(*stack_a);
	while (i < list_size - 3)
	{
		shortest_op = calculator_op(tmp, stack_b, op_count);
		osman_sort_algorithm_third(stack_a, stack_b, op_count, shortest_op);
		i++;
	}
}

// n.average = calculate_average(stack_a);
void	osman_sort_algorithm(t_list **stack_a, t_list **stack_b, int *op_count)
{
	t_case	n;

	// push 2 values to stack b
	push_b((long)(*stack_a)->content, stack_b, op_count);
	pop(stack_a);
	push_b((long)(*stack_a)->content, stack_b, op_count);
	pop(stack_a);
	// proceed
	print_stack(stack_a);
	print_stack(stack_b);
	
	osman_sort_algorithm_two(stack_a, stack_b, op_count);

	print_stack(stack_a);
	print_stack(stack_b);
	
	// handle_edge_three(stack_a, stack_b, &n, op_count);
	print_stack(stack_a);
	print_stack(stack_b);
	// final push
	while ((*stack_b))
	{
		if ((long)(*stack_b)->content < (long)(*stack_a)->content)
		{
			push_a((long)(void *)(*stack_b)->content, stack_a, op_count);
			pop(stack_b);
		}
		else
			rotate_b(stack_b, op_count);
	}
	// final check
	print_stack(stack_a);
	print_stack(stack_b);
	// check_for_top_min(stack_a, op_count);
}

// print_stack(stack_a);
// print_stack(stack_b);
// Step 4: Continue sorting the remaining elements
// osman_sort_algorithm_two(stack_a, stack_b, op_count);
// print_stack(stack_a);
// print_stack(stack_b);
// osman_sort_algorithm_third(stack_a,stack_b,op_count);
// Step 3: Print stacks for debugging
// print_stack(stack_a);
// print_stack(stack_b);

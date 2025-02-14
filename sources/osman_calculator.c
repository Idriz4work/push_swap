/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osman_calculator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:31:54 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/14 19:08:32 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// this function returns the actual index of the number
// which has the shortest operations to do
int	short_index_finder(int *rotate_ops, int length)
{
	int	index;
	int	shortest;

	index = 0;
	shortest = INT_MAX;
	while (length >= 0)
	{
		if (rotate_ops[length] < shortest)
		{
			shortest = rotate_ops[length];
			index = length;
		}
		length--;
	}
	return (index);
}

// finds the number that needs to be 1 before the top
// value which means that the number needs to be
// rotated to the top and then the top value gets
// pushed to the top
// finds the number that should be right before
// the given top value in descending order
// Find the number that should be right before the given top value in ascending order
// If no valid larger number is found, return the smallest number in stack_b
// Find the smallest number that's still larger than top
int	find_next_largest(int top, t_list **stack_b)
{
	long	current;
	t_list	*tmp;

	tmp = (*stack_b);
	current = INT_MIN;
	while (tmp)
	{
		if ((long)tmp->content < top && (long)tmp->content > current)
			current = (long)tmp->content;
		tmp = tmp->next;
	}
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
	return (current);
}

// this calculates how many rotations or reverse rotataions
// the current number(num) needs in order to be placed
// in the right position in stack b First find the position of the target
void	cost_moving_position_b(int num, t_list **stack_b, int index,
		rot_number *rots)
{
	t_list	*tmp;
	int		target;
	int		size;
	int		position;

	tmp = *stack_b;
	target = find_next_largest(num, stack_b);
	size = ft_lstsize(*stack_b);
	position = 0;
	rots->order_of_b = 0;
	rots->order_rev_b = 0;
	while (tmp && (long)tmp->content != target)
	{
		position++;
		tmp = tmp->next;
	}
	position_decider_b(position, size, rots);
}

// finds postion for the current number and then calls decider which will tell if
// rotate or reverse rotate needs to be done
void	cost_of_gettop_a(int current, t_list **stack_a, int index,
		rot_number *rots)
{
	t_list	*tmp;
	int		position;
	int		size;

	position = 0;
	tmp = *stack_a;
	size = ft_lstsize(*stack_a);
	rots->order_of_a = 0;
	rots->order_rev_a = 0;
	while (tmp && (long)tmp->content != current)
	{
		position++;
		tmp = tmp->next;
	}
	position_decider_a(position, size, rots);
}

// goes through all elements in stack a and calculates the moves to put the current value
// into the right position in stack b,
// the index of shortest number of ops gets returned
int	calculator_op(t_list *stack_a, t_list *stack_b, rot_number *rots)
{
	int		i;
	int		j;
	int		*rotate_ops;
	int		*rev_ops;
	t_list	*tmp;

	j = 0;
	i = 0;
	rotate_ops = malloc(sizeof(int) * ft_lstsize(stack_a) + 1);
	if (!rotate_ops)
		exit(EXIT_FAILURE);
	rev_ops = malloc(sizeof(int) * ft_lstsize(stack_a) + 1);
	if (!rev_ops)
		exit(EXIT_FAILURE);
	tmp = stack_a;
	while (tmp)
	{
		initialize_rotation(rots);
		cost_of_gettop_a((long)tmp->content, &stack_a, i, rots);
		cost_moving_position_b((long)tmp->content, &stack_b, i, rots);
		rotate_ops[i] = rots->order_of_a + rots->order_of_b;
		rev_ops[i] = rots->order_rev_a + rots->order_rev_b;
		tmp = tmp->next;
		i++;
	}
	i = short_index_finder(rotate_ops, i - 1);
	j = short_index_finder(rev_ops, i - 1);
	free(rotate_ops);
	rotate_ops = NULL;
	free(rev_ops);
	rotate_ops = NULL;
	if (i < j)
		rots->best_ind = rotate_ops[i];
	else
		rots->best_ind = rev_ops[j];
	if (i < j)
		rots->rev_up_or_down = ROTATE;
	else
		rots->rev_up_or_down = REV_ROTATE;	
}

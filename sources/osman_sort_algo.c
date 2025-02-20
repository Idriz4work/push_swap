/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osman_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:46:08 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/15 23:13:07 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// This function checks if the smallest
// number in stack_b is located at the top of the stack.
// If it's not,
// it performs the necessary rotations
// (either forwards or backwards) to bring it
// to the top, and then pushes all
// elements from stack_b back onto stack_a.
void	check_for_top_min(t_list **stack_a, t_list **stack_b)
{
	int	position;
	int	stack_size;

	position = find_largest_position(stack_b);
	stack_size = ft_lstsize(*stack_b);
	if (position <= stack_size / 2)
		forwords_sorter(stack_b, position);
	else
		backwards_sorter(stack_b, stack_size - position);
	while (*stack_b)
		push_a((long)(*stack_b)->content, stack_a, stack_b);
}

// This function retrieves the content of
//  the element at the specified index in stack_a.
// It iterates through the list until it
// reaches the correct position and then returns the value.
int	get_right_index(int index, t_list *stack_a)
{
	int		j;
	t_list	*tmp;

	tmp = stack_a;
	j = 0;
	while (j < index)
	{
		tmp = tmp->next;
		j++;
	}
	return ((long)tmp->content);
}

// This function implements the core sorting algorithm
// for the "Osman Sort" strategy.
// It calculates the number of rotations
// required for each element in stack_a to place it in the
// correct position in stack_b,
// and then applies the necessary rotations to both stacks.
// After placing each element in stack_b,
// it moves to the next one until stack_a is empty.
void	osman_sort_algorithm_two(t_list **stack_a, t_list **stack_b)
{
	t_rot	rots;
	int		list_size;
	int		i;
	long	target_content;

	i = 0;
	list_size = ft_lstsize(*stack_a);
	while (i < list_size)
	{
		initialize_rotation(&rots);
		rots.best_ind = calculator_op(*stack_a, *stack_b, &rots);
		target_content = get_right_index(rots.best_ind, *stack_a);
		cost_of_gettop_a(target_content, stack_a, &rots);
		cost_moving_position_b(target_content, stack_b, &rots);
		handle_rotation_a(&rots, stack_a);
		handle_rotation_b(&rots, stack_b);
		push_b((long)(*stack_a)->content, stack_b, stack_a);
		i++;
	}
}

// This function performs the Osman sorting algorithm.
// It first moves two elements from stack_a to stack_b,
// then calls the second phase of the algorithm
// to sort the remaining elements.
// After sorting, it ensures the smallest element is at
// the top of stack_b before pushing all elements back to stack_a.
void	osman_sort_algorithm(t_list **stack_a, t_list **stack_b)
{
	push_b((long)(*stack_a)->content, stack_b, stack_a);
	push_b((long)(*stack_a)->content, stack_b, stack_a);
	osman_sort_algorithm_two(stack_a, stack_b);
	check_for_top_min(stack_a, stack_b);
}

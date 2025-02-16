/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osman_calculator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:31:54 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/15 23:13:22 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// returns the smallest value
// a = up_down.uu (up up (rotate a rotate b))
// b = up_down.ud ((up down (rotate a rotate b)))
// c = up_down.du
// d = up_down.dd
static int	smallest(int a, int b, int c, int d)
{
	int	cur;

	cur = a;
	if (b < cur)
		cur = b;
	if (c < cur)
		cur = c;
	if (d < cur)
		cur = d;
	return (cur);
}

// This function returns the index of the
// number with the shortest number of rotation operations
// required to reach its correct position
// in the stack.
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

// This function calculates how many rotations or
//  reverse rotations are needed to position
// a number (num) at the correct spot in stack_b.
//  It first determines the target position
// in stack_b, then calculates the necessary moves.
void	cost_moving_position_b(int num, t_list **stack_b, int index,
		t_rot *rots)
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

// This function calculates the position of a given
//  number (current) in stack_a and calls
// position_decider_a to determine whether a rotation
// or reverse rotation is needed to bring
// the number to the top of stack_a.
void	cost_of_gettop_a(int current, t_list **stack_a, int index, t_rot *rots)
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

// This function calculates the necessary moves to
//  position each element in stack_a at
// the correct position in stack_b. It tracks the
// number of operations required for each
// number and returns the index of the number with
//  the shortest number of operations.
int	calculator_op(t_list *stack_a, t_list *stack_b, t_rot *rots)
{
	int			i;
	int			*rotate_ops;
	t_list		*tmp;
	t_updown	up_down;

	i = 0;
	rotate_ops = malloc(sizeof(int) * ft_lstsize(stack_a) + 1);
	if (!rotate_ops)
		exit(EXIT_FAILURE);
	tmp = stack_a;
	while (tmp)
	{
		initialize_rotation(rots);
		cost_of_gettop_a((long)tmp->content, &stack_a, i, rots);
		cost_moving_position_b((long)tmp->content, &stack_b, i, rots);
		update_up_down(&up_down, rots);
		rotate_ops[i] = smallest(up_down.uu, up_down.ud, up_down.du,
				up_down.dd);
		tmp = tmp->next;
		i++;
	}
	i = short_index_finder(rotate_ops, i - 1);
	free(rotate_ops);
	rotate_ops = NULL;
	return (i);
}

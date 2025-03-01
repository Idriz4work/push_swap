/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_osman_ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:45:38 by iatilla-          #+#    #+#             */
/*   Updated: 2025/03/01 21:53:35 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// this is the function which decides if
// we rotate forword or backwards for stack a
void	position_decider_a(int position, int stack_size, t_rot *rots)
{
	rots->order_of_a = position;
	rots->order_rev_a = stack_size - position;
}

// this is the function which decides if we
// rotate forword or backwards for stack b
void	position_decider_b(int position, int stack_size, t_rot *rots)
{
	rots->order_of_b = position;
	rots->order_rev_b = stack_size - position;
}

// Initialize rots structure for each new number
void	initialize_rotation(t_rot *rots)
{
	rots->order_of_a = 0;
	rots->order_of_b = 0;
	rots->order_rev_a = 0;
	rots->order_rev_b = 0;
	rots->rev_up_or_down = 0;
}

void	handle_rotation_a(t_rot *rots, t_list **stack_a)
{
	if (rots->order_of_a < rots->order_rev_a)
	{
		while (rots->order_of_a > 0)
		{
			rotate_a(stack_a);
			rots->order_of_a--;
		}
	}
	else
	{
		while (rots->order_rev_a > 0)
		{
			reverse_rotate_a(stack_a);
			rots->order_rev_a--;
		}
	}
}

// Handle rotations for stack B either rotate forward
//  or reverse rotate backward
void	handle_rotation_b(t_rot *rots, t_list **stack_b)
{
	if (rots->order_of_b < rots->order_rev_b)
	{
		while (rots->order_of_b > 0)
		{
			rotate_b(stack_b);
			rots->order_of_b--;
		}
	}
	else
	{
		while (rots->order_rev_b > 0)
		{
			reverse_rotate_b(stack_b);
			rots->order_rev_b--;
		}
	}
}

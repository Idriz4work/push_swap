/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_osman_ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:45:38 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/14 20:18:12 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// this is the function which decides if we rotate forword or backwards for stack a
void	position_decider_a(int position, int stack_size, rot_number *rots)
{
	// Calculate ops based on position relative to half size
	rots->order_of_a = position;
	// rots->rot_or_rev = ROTATE;
	rots->order_rev_a = stack_size - position;

}

// this is the function which decides if we rotate forword or backwards for stack b
void	position_decider_b(int position, int stack_size, rot_number *rots)
{
	// Calculate ops based on position relative to half size
	rots->order_of_b = position;
	rots->order_rev_b = stack_size - position;

}

// Initialize rots structure for each new number
void	initialize_rotation(rot_number *rots)
{
	rots->order_of_a = 0;
	rots->order_of_b = 0;
	rots->order_rev_a = 0;
	rots->order_rev_b = 0;
	rots->rev_up_or_down = 0;
}

void    handle_rotation_a(rot_number *rots, t_list **stack_a)
{
    int i;
    i = 0;
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
// Handle rotations for stack B either rotate forward or reverse rotate backward
void    handle_rotation_b(rot_number *rots, t_list **stack_b)
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

// // Handle rotations for stack A either rotate forward or reverse rotate backward
// void	handle_rotation_a(rot_number *rots, t_list **stack_a)
// {
// 	if (rots->rev_up_or_down == ROTATE)
// 	{
// 		while (rots->best_ind > 0)
// 		{
// 			rotate_a(stack_a);
// 			rots->best_ind--;
// 		}
// 	}
// 	else
// 	{
// 		while (rots->best_ind > 0)
// 		{
// 			reverse_rotate_a(stack_a);
// 			rots->best_ind--;
// 		}
// 	}
// }

// // Handle rotations for stack B either rotate forward or reverse rotate backward
// void	handle_rotation_b(rot_number *rots, t_list **stack_b)
// {
// 	if (rots->order_of_b < rots->order_rev_b)
// 	{
// 		while (rots->order_of_b > 0)
// 		{
// 			rotate_b(stack_b);
// 			rots->order_of_b--;
// 		}
// 	}
// 	else
// 	{
// 		while (rots->order_rev_b > 0)
// 		{
// 			reverse_rotate_b(stack_b);
// 			rots->order_rev_b--;
// 		}
// 	}
// }

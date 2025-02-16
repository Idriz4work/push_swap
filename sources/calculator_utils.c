/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:42:16 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/15 23:11:51 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// updates the values in up_down struct
void	update_up_down(t_updown *up_down, t_rot *rots)
{
	up_down->uu = rots->order_of_a + rots->order_of_b;
	up_down->ud = rots->order_of_a + rots->order_rev_b;
	up_down->du = rots->order_rev_a + rots->order_of_b;
	up_down->dd = rots->order_rev_a + rots->order_rev_b;
}

// This function finds the number in stack_b that
//  is just larger than the given 'top' value
// when traversing the stack in descending order.
// If no such number is found,it returns the smallest
// number in stack_b. If no valid larger number is found
// it returns the smallest value in stack_b.
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

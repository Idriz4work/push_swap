/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osman_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:46:08 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/02 04:50:17 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	osman_sort_algorithm(t_list **stack_a, t_list **stack_b)
{
	long	value;
	int	starting_point;

	value = 0;
	starting_point = check_sorted(*stack_a);
	while ((*stack_a) != NULL)
	{
		value = (long)(*stack_a)->content;
		push_b(value, stack_b);
		pop_a(stack_a);
	}
}

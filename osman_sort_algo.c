/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osman_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:46:08 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/14 20:28:35 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void check_for_top_min(t_list **stack_a, t_list **stack_b, rot_number *rots)
{
    int position;
    int stack_size;

    position = find_largest_position(stack_b);
    stack_size = ft_lstsize(*stack_b);
    if (position <= stack_size / 2)
        forwords_sorter(stack_b, position);
    else
        backwards_sorter(stack_b, stack_size - position);
    while (*stack_b)
        push_a((long)(*stack_b)->content, stack_a, stack_b);
}

// Main algorithm functions
void osman_sort_algorithm_two(t_list **stack_a, t_list **stack_b)
{
    rot_number  rots;
    int         list_size;
    int         i;
    
    i = 0;
    list_size = ft_lstsize(*stack_a);
    while (i < list_size)
    {
        initialize_rotation(&rots);
        rots.best_ind = calculator_op(*stack_a, *stack_b, &rots);  // Changed tmp to *stack_a
        cost_of_gettop_a((long)(*stack_a)->content, stack_a, rots.best_ind, &rots);
        cost_moving_position_b((long)(*stack_a)->content, stack_b, rots.best_ind, &rots);
        handle_rotation_a(&rots, stack_a);
        handle_rotation_b(&rots, stack_b);
        push_b((long)(*stack_a)->content, stack_b, stack_a);
        i++;
    }
}


void osman_sort_algorithm(t_list **stack_a, t_list **stack_b)
{
    rot_number rots;

    push_b((long)(*stack_a)->content, stack_b, stack_a);
    push_b((long)(*stack_a)->content, stack_b, stack_a);
    osman_sort_algorithm_two(stack_a, stack_b);
    check_for_top_min(stack_a, stack_b, &rots);
}

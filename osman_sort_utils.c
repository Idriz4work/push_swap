/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osman_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:06:42 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/13 17:09:48 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void forwords_sorter(t_list **stack_b, int num_rotates)
{
    while (num_rotates > 0)
    {
        rotate_b(stack_b);
        num_rotates--;
    }
}

void backwards_sorter(t_list **stack_b, int num_reverse_op)
{
    while (num_reverse_op > 0)
    {
        reverse_rotate_b(stack_b);
        num_reverse_op--;
    }
}

// finds largest postion of stack_b 
int find_largest_position(t_list **stack_b)
{
    t_list  *tmp;
    int     position;
    int     current_pos;
    int     largest;

    largest = INT_MIN;
    position = 0;
    current_pos = 0;
    tmp = *stack_b;
    while (tmp)
    {
        if ((long)tmp->content > largest)
        {
            largest = (long)tmp->content;
            position = current_pos;
        }
        tmp = tmp->next;
        current_pos++;
    }
    return (position);
}


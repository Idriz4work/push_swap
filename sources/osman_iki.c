/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osman_iki.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:18:31 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/07 11:24:54 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
void osmani_iki(t_list **stack_a,t_list **stack_b, int *op_count)
{
    int size;
    int *array;
    int i, j, tmp;

    // Get the size of the stack
    size = ft_lstsize(*stack_a);
    
    // Allocate memory for the array
    array = malloc(sizeof(int) * size);
    if (!array)
        return;

    // Copy elements from stack to array
    t_list *current = *stack_a;
    for (i = 0; i < size; i++)
    {
        array[i] = (long)current->content;
        current = current->next;
    }

    // Perform bubble sort
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                // Swap elements
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }

    // Clear the original stack
    while (*stack_a)
        pop(stack_a);

    // Push sorted elements back to stack
    for (i = 0; i < size; i++)
    {
        push_b(array[i], stack_b, op_count);
    }
	while ((*stack_b) != NULL)
    {
        push_a((long)(*stack_b)->content, stack_a, op_count);
		pop(stack_b);
    }

    // Free the temporary array
    free(array);
	// print_stack(stack_a);
	// return (array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:55:49 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/16 15:48:45iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// Checks if the stack is sorted in ascending order.
// Returns the index where the sorted order breaks,
// or exits with error if not sorted.
int check_sorted(t_list *stack)
{
    t_list *current;

    if (stack == NULL || stack->next == NULL)
        return (1);
    current = stack;
    while (current->next != NULL)
    {
        if ((long)current->content > (long)current->next->content)
            return (-1);
        current = current->next;
    }
    return (1);
}

long ft_atol(char *s)
{
    long i = 0;
    unsigned long endresult = 0;
    long is_op = 1;

    while ((s[i] == ' ') || (s[i] >= 9 && s[i] <= '\r'))
        i++;
    if (s[i] == '+' || s[i] == '-')
    {
        if (s[i] == '-')
            is_op = -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9')
    {
        endresult = endresult * 10 + (s[i] - '0');
        if ((is_op == 1 && endresult > 2147483647) ||
            (is_op == -1 && endresult > 2147483648))
        {
            ft_putstr_fd("Error\n", 2);
            exit(EXIT_FAILURE);
        }
        i++;
    }
    return (is_op * endresult);
}


int initialize_stack(t_list **stack_a, t_list **stack_b)
{
    *stack_a = NULL;
    *stack_b = NULL;
    return (0);
}

int is_valid_number(char *str)
{
    int i = 0;

    if (!str || *str == '\0')
        return (0);
    if (str[i] == '+' || str[i] == '-')
    {
        if (!ft_isdigit(str[i + 1]))
            return (0);
        i++;
    }
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int handle_ops(char **argv)
{
    int i, j;
    long num;

    i = 1;
    while (argv[i] != NULL)
    {
        if (!is_valid_number(argv[i]))
        {
            ft_putstr_fd("Error\n", 2);
            return (-1);
        }
        num = ft_atol(argv[i]);
        if (num > 2147483647 || num < -2147483648)
        {
            ft_putstr_fd("Error\n", 2);
            return (-1);
        }
        j = i + 1;
        while (argv[j] != NULL)
        {
            if (ft_atol(argv[i]) == ft_atol(argv[j]))
            {
                ft_putstr_fd("Error\n", 2);
                return (-1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:40 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/16 16:53:16 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void cleanup_and_exit(t_list **stack_a, t_list **stack_b, int status)
{
    if (stack_a && *stack_a)
        ft_lstclear(stack_a, free);
    if (stack_b && *stack_b)
        ft_lstclear(stack_b, free);
    if (status != EXIT_SUCCESS)
        ft_putstr_fd("Error\n", 2); // Ensure error printed to stderr if exiting with failure
    exit(status);
}

void process_values(t_list **stack_a, t_list **stack_b)
{
    int value;
    t_case n;

    n.first = 0;
    n.last = 0;
    n.second = 0;
    value = ft_lstsize(*stack_a);
    if (check_sorted(*stack_a) == 1)
        cleanup_and_exit(stack_a, stack_b, EXIT_SUCCESS);
    if (value == 2)
    {
        n.first = (long)((*stack_a)->content);
        n.second = (long)((*stack_a)->next->content);
        if (n.first > n.second)
            swap_a(stack_a);
    }
    else if (value == 3)
        handle_edge_three(stack_a, &n);
    else if (value == 4)
        handle_edge_four(stack_a, stack_b, &n);
    else if (value == 5)
        handle_edge_five(stack_a, stack_b, &n);
    else
        osman_sort_algorithm(stack_a, stack_b);
}

int process_values_two(char **values)
{
    int i;

    i = 1;
    while (values[i] != NULL)
    {
        if (ft_atol(values[i]) > 2147483647 || ft_atol(values[i]) < -2147483648)
        {
            ft_putstr_fd("Error\n", 2);
            return (-1);
        }
        i++;
    }
    return (i - 1);
}

void filler(char **values, t_list **stack_a, int i)
{
    t_list *newnode;

    while (i >= 1)
    {
        newnode = (t_list *)malloc(sizeof(t_list));
        if (!newnode)
        {
            ft_putstr_fd("Error\n", 2); // Error to stderr
            ft_lstclear(stack_a, free);
            exit(EXIT_FAILURE);
        }
        newnode->content = (void *)(long)ft_atoi(values[i--]);
        newnode->next = (*stack_a);
        (*stack_a) = newnode;
    }
}

t_list *fill_stack(char **values, t_list **stack_a, t_list **stack_b)
{
    int i;

    i = 0;
    if (initialize_stack(stack_a, stack_b) == -1)
    {
        ft_putstr_fd("Error\n", 2);
        return (NULL);
    }
    i = process_values_two(values);
    if (i == -1)
        cleanup_and_exit(stack_a, stack_b, EXIT_FAILURE);
    filler(values, stack_a, i);
    process_values(stack_a, stack_b);
    return (*stack_a);
}

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (argc < 2)
        return (-1);
    if (handle_ops(argv) == -1)
        return (-2);
    stack_a = fill_stack(argv, &stack_a, &stack_b);
    if (stack_a == NULL)
        return (-3);
    ft_lstclear(&stack_a, free);
    ft_lstclear(&stack_b, free);
    return (0);
}

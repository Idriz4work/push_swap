/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:55:49 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/14 22:14:00 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// Checks if the stack is sorted in ascending order.
// Returns the index where the sorted order breaks,
// or exits with error if not sorted.
int	check_sorted(t_list *stack)
{
	int		index;
	t_list	*current;

	index = 0;
	current = stack;
	while (current != NULL && current->next != NULL)
	{
		if (current->content < current->next->content)
		{
			index++;
			current = current->next;
			continue ;
		}
		return (index);
	}
	exit(1);
}

// Converts a string to a long integer while handling signs (+ or -).
long	ft_atol(char *s)
{
	long	i;
	long	endresult;
	long	is_op;

	i = 0;
	endresult = 0;
	is_op = 1;
	while ((s[i] == ' ') || (s[i] >= 9 && s[i] <= '\r'))
		i++;
	if (s[i] == '+' || s[i] == '-' || s[i] == ' ')
	{
		if (s[i] == '-')
			is_op = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		endresult = endresult * 10 + s[i] - '0';
		i++;
	}
	return (is_op * endresult);
}

// Initializes both stacks to NULL.
int	initialize_stack(t_list **stack_a, t_list **stack_b)
{
	*stack_a = NULL;
	*stack_b = NULL;
	return (0);
}

// Helper function that checks if a given string is a valid number.
static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

// Handles the operations: checks for duplicates and validates the numbers in the argument array.
int	handle_ops(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_strncmp(argv[i], argv[j], 20) == 0)
			{
				ft_printf("Error op\n");
				return (-1);
			}
			j++;
		}
		if (!is_valid_number(argv[i]))
		{
			ft_printf("Error op\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

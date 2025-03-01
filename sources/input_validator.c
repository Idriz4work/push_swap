/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:07:16 by iatilla-          #+#    #+#             */
/*   Updated: 2025/03/01 22:18:32 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// Checks if the stack is sorted in ascending order.
// Returns the index where the sorted order breaks,
// or exits with error if not sorted.
int	check_sorted(t_list *stack)
{
	t_list	*current;

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

// Handles the initial whitespace and signs in string
long	handle_whitespace_and_sign(char *s, long *i, long *is_op)
{
	while ((s[*i] == ' ') || (s[*i] >= 9 && s[*i] <= '\r'))
		(*i)++;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			*is_op = -1;
		(*i)++;
	}
	return (0);
}

// Validates if the converted number is within integer range
void	check_integer_overflow(unsigned long endresult, long is_op)
{
	if ((is_op == 1 && endresult > 2147483647) || (is_op == -1
			&& endresult > 2147483648))
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

// Main function to convert string to long
long	ft_atol(char *s)
{
	long			i;
	unsigned long	endresult;
	long			is_op;

	i = 0;
	endresult = 0;
	is_op = 1;
	handle_whitespace_and_sign(s, &i, &is_op);
	while (s[i] >= '0' && s[i] <= '9')
	{
		endresult = endresult * 10 + (s[i] - '0');
		check_integer_overflow(endresult, is_op);
		i++;
	}
	return (is_op * endresult);
}

// Main handler function that validates each argument
int	handle_ops(char **argv)
{
	int		i;
	long	num;

	i = 1;
	while (argv[i] != NULL)
	{
		if (!is_valid_number(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		num = ft_atol(argv[i]);
		if (!is_valid_integer_range(num))
			return (-1);
		if (!check_for_duplicates(argv, i))
			return (-1);
		i++;
	}
	return (0);
}

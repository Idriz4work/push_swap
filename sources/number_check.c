/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:15:53 by iatilla-          #+#    #+#             */
/*   Updated: 2025/03/01 22:18:46 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
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

// Validates if a number is within the integer range
int	is_valid_integer_range(long num)
{
	if (num > 2147483647 || num < -2147483648)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

// Checks for duplicate numbers in the array
int	check_for_duplicates(char **argv, int current_index)
{
	int		j;
	long	current_num;

	current_num = ft_atol(argv[current_index]);
	j = current_index + 1;
	while (argv[j] != NULL)
	{
		if (current_num == ft_atol(argv[j]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		j++;
	}
	return (1);
}

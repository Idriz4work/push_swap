/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:05:10 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/12 19:22:58 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	calculate_biggest(t_list **stack_a)
{
	int		n;
	int		sum;
	t_list	*tmp;

	sum = 0;
	n = 0;
	tmp = (*stack_a);
	sum = (long)tmp->content;
	while (n < ft_lstsize(*(stack_a)))
	{
		if (sum < (long)tmp->content)
			sum = (long)tmp->content;
		n++;
	}
	return (sum);
}

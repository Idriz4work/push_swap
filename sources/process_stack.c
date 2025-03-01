/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:52:02 by iatilla-          #+#    #+#             */
/*   Updated: 2025/03/01 22:10:12 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	cleanup_and_exit(t_list **stack_a, t_list **stack_b, int status)
{
	if (stack_a && *stack_a)
		ft_lstclear(stack_a, free);
	if (stack_b && *stack_b)
		ft_lstclear(stack_b, free);
	if (status != EXIT_SUCCESS)
		ft_putstr_fd("Error\n", 2);
	exit(status);
}

int	initialize_stack(t_list **stack_a, t_list **stack_b)
{
	*stack_a = NULL;
	*stack_b = NULL;
	return (0);
}

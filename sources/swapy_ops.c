/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapy_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:15:58 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/15 19:26:06 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// Swaps the top two elements of stack_a.
void	swap_a(t_list **stak)
{
	t_list	*first;
	t_list	*second;

	if ((*stak) == NULL || (*stak)->next == NULL)
		return ;
	first = (*stak);
	second = (*stak)->next;
	first->next = second->next;
	second->next = first;
	(*stak) = second;
	ft_printf("sa\n");
}

// Swaps the top two elements of stack_b.
void	swap_b(t_list **stak)
{
	t_list	*first;
	t_list	*second;

	if ((*stak) == NULL || (*stak)->next == NULL)
		return ;
	first = (*stak);
	second = (*stak)->next;
	first->next = second->next;
	second->next = first;
	(*stak) = second;
	ft_printf("sb\n");
}

// Swaps the top two elements of both stack_a and stack_b.
void	sa_ab_same(t_list **stak_a, t_list **stak_b)
{
	swap_a(stak_a);
	swap_b(stak_b);
	ft_printf("ss\n");
}

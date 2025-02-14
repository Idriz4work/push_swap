/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:28:02 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/13 14:52:48 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void	sa_ab_same(t_list **stak_a, t_list **stak_b)
{
	swap_a(stak_a);
	swap_b(stak_b);
	ft_printf("ss\n");
}

void	reverse_rotate_rrr(t_list **stak_a, t_list **stak_b)
{
	reverse_rotate_a(stak_a);
	reverse_rotate_b(stak_b);
	ft_printf("rrr\n");
}

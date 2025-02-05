/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:28:02 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/05 13:28:37 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void swap_a(t_list **stak, int *op_count)
{
    t_list *first;
    t_list *second;

    if ((*stak) == NULL || (*stak)->next == NULL)
        return;
    first = (*stak);
    second = (*stak)->next;
    first->next = second->next;
    second->next = first;
    (*stak) = second;
    ft_printf("sa\n");
    (*op_count)++;
}

void swap_b(t_list **stak, int *op_count)
{
    t_list *first;
    t_list *second;

    if ((*stak) == NULL || (*stak)->next == NULL)
        return;
    first = (*stak);
    second = (*stak)->next;
    first->next = second->next;
    second->next = first;
    (*stak) = second;
    ft_printf("sb\n");
    (*op_count)++;
}

void sa_ab_same(t_list **stak_a, t_list **stak_b, int *op_count)
{
    swap_a(stak_a, op_count);
    swap_b(stak_b, op_count);
    ft_printf("ss\n");
    (*op_count)++;
}

void reverse_rotate_rrr(t_list **stak_a, t_list **stak_b, int *op_count)
{
    reverse_rotate_a(stak_a, op_count);
    reverse_rotate_b(stak_b, op_count);
    ft_printf("rrr\n");
    (*op_count)++;
}

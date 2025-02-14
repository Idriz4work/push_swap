/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:42:16 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/14 22:50:58 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// updates the values in up_down struct
void update_up_down(t_updown *up_down,rot_number *rots)
{
	up_down->uu = rots->order_of_a + rots->order_of_b;
	up_down->ud = rots->order_of_a + rots->order_rev_b;
	up_down->du = rots->order_rev_a + rots->order_of_b;
	up_down->dd = rots->order_rev_a + rots->order_rev_b;
}
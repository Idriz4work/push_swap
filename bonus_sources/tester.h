/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 04:34:04 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/23 05:23:52 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include "../sources/pushswap.h"

typedef struct s_tester
{
	int			flag;
	char		*str;
	t_stk_top	*stack;
}	t_test;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:18:19 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/12 14:49:42 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int ce)
{
	if ((ce >= 32) && (ce <= 126))
		return (1);
	return (0);
}

// #include "libft.h"
// int main()
// {
// 	printf("%i\n%i\n",ft_isprint(125),isprint(125));
// }

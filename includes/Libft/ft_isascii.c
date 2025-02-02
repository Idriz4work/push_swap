/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:18:40 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/12 14:20:39 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int ce)
{
	if ((ce >= 0) && (ce <= 127))
		return (1);
	return (0);
}
// #include "libft.h"
// int main()
// {
// 	printf("%i\n%i\n",isascii(3),ft_isascii(3));
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:24:30 by htsang            #+#    #+#             */
/*   Updated: 2022/11/07 22:30:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** @param n: a pointer
** @return the length of the given pointer address if printed out.
*/
size_t	ft_ptrlen(size_t n)
{
	size_t	len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

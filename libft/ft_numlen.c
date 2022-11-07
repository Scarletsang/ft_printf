/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:24:30 by htsang            #+#    #+#             */
/*   Updated: 2022/11/07 22:29:50 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** @param n: a long number
** @param base: the base to interpret the number in
** @return the length of the given number when printed out
*/
size_t	ft_numlen(long n, int base)
{
	size_t	len;

	len = 0;
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

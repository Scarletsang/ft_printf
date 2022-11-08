/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:24:36 by htsang            #+#    #+#             */
/*   Updated: 2022/11/07 23:24:29 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

static void	print_long_recurse(long n, int sign)
{
	if (n * sign > 0)
	{
		print_long_recurse(n / 10, sign);
		print_c(n % 10 * sign + '0');
	}
}

/*
** @brief Print a number.
**
** @param n:  the number
*/
static void	print_long(long n)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
	}
	print_long_recurse(n / 10, sign);
	print_c(n % 10 * sign + '0');
}

void	print_di(int n)
{
	print_long(n);
}

void	print_u(unsigned int n)
{
	print_long(n);
}

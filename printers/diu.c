/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:24:36 by htsang            #+#    #+#             */
/*   Updated: 2022/11/05 20:21:35 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

static void	print_long_recurse(size_t n, int sign)
{
	if (n > 0)
	{
		print_long_recurse(n / 10, sign);
		printer(n % 10 * sign + '0', 1);
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
	printer(n % 10 * sign + '0', 1);
}

void	print_di(int n)
{
	print_long(n);
}

void	print_u(unsigned int n)
{
	print_long(n);
}
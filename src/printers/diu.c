/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:24:36 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 01:12:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

static int	printf_long_recurse(long n, int sign)
{
	struct s_printf_sequencer	seq;

	if (n * sign > 0)
	{
		printf_sequencer_init(&seq);
		if (printf_sequence(&seq, printf_long_recurse(n / 10, sign)) || \
			printf_sequence(&seq, printf_c(n % 10 * sign + '0')))
			return (-1);
		return (seq.sum);
	}
	return (0);
}

/*
** @brief Print a number.
**
** @param n:  the number
*/
static int	printf_long(long n)
{
	struct s_printf_sequencer	seq;
	int							sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
	}
	printf_sequencer_init(&seq);
	if (printf_sequence(&seq, printf_long_recurse(n / 10, sign)) || \
		printf_sequence(&seq, printf_c(n % 10 * sign + '0')))
		return (-1);
	return (seq.sum);
}

int	printf_di(int n)
{
	return (printf_long(n));
}

int	printf_u(unsigned int n)
{
	return (printf_long(n));
}

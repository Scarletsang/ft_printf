/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xXp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:02:49 by htsang            #+#    #+#             */
/*   Updated: 2022/11/07 22:11:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

static void	print_hex_recurse(unsigned long n, char alphabet_case)
{
	if (n)
	{
		print_hex_recurse(n >> 4, alphabet_case);
		if ((n & 15) > 9)
		{
			print_c((n & 15) - 10 + alphabet_case);
		}
		else
		{
			print_c((n & 15) + '0');
		}
	}
}

static void	print_hex(unsigned long n, char alphabet_case)
{
	print_hex_recurse(n >> 4, alphabet_case);
	if ((n & 15) > 9)
	{
		print_c((n & 15) - 10 + alphabet_case);
	}
	else
	{
		print_c((n & 15) + '0');
	}
}

void	print_p(unsigned long p)
{
	print_hex(p, 'a');
}

void	print_x(unsigned int n)
{
	print_hex(n, 'a');
}

void	print_x_upper(unsigned int n)
{
	print_hex(n, 'A');
}

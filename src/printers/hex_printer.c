/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 00:31:56 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 02:59:34 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

static int	printf_hex_digit(size_t n, char alphabet_case)
{
	struct s_printf_sequencer	seq;

	printf_sequencer_init(&seq);
	if ((n & 15) > 9)
	{
		if (printf_sequence(&seq, \
			printf_c((n & 15) - 10 + alphabet_case)))
			return (-1);
	}
	else
	{
		if (printf_sequence(&seq, \
			printf_c((n & 15) + '0')))
			return (-1);
	}
	return (seq.sum);
}

static int	printf_hex_recurse(size_t n, char alphabet_case)
{
	struct s_printf_sequencer	seq;

	if (n)
	{
		printf_sequencer_init(&seq);
		if (printf_sequence(&seq, \
			printf_hex_recurse(n >> 4, alphabet_case)))
			return (-1);
		if (printf_sequence(&seq, \
			printf_hex_digit(n, alphabet_case)))
			return (-1);
		return (seq.sum);
	}
	return (0);
}

int	printf_hex(size_t n, char alphabet_case)
{
	struct s_printf_sequencer	seq;

	printf_sequencer_init(&seq);
	if (printf_sequence(&seq, \
		printf_hex_recurse(n >> 4, alphabet_case)))
		return (-1);
	if (printf_sequence(&seq, \
		printf_hex_digit(n, alphabet_case)))
		return (-1);
	return (seq.sum);
}

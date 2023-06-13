/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:22:54 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:19:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

int	printf_zeros(unsigned int len)
{
	struct s_printf_sequencer	seq;

	printf_sequencer_init(&seq);
	while (len)
	{
		if (printf_sequence(&seq, write(STDOUT_FILENO, "0", 1)))
			return (-1);
		len--;
	}
	return (seq.sum);
}

int	printf_spaces(unsigned int len)
{
	struct s_printf_sequencer	seq;

	printf_sequencer_init(&seq);
	while (len)
	{
		if (printf_sequence(&seq, write(STDOUT_FILENO, " ", 1)))
			return (-1);
		len--;
	}
	return (seq.sum);
}

int	printf_plus(void)
{
	return (write(STDOUT_FILENO, "+", 1));
}

int	printf_minus(void)
{
	return (write(STDOUT_FILENO, "-", 1));
}

int	printf_0x(char is_upper)
{
	if (is_upper)
	{
		return (write(STDOUT_FILENO, "0X", 2));
	}
	else
	{
		return (write(STDOUT_FILENO, "0x", 2));
	}
}

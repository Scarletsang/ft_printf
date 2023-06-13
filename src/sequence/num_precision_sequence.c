/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_precision_sequence.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:30:14 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 03:00:26 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sequence.h"

static int	printf_sequence_with_precision_minus(char format, \
struct s_printf_parser *states, va_list *subs)
{
	struct s_printf_sequencer	seq;

	printf_sequencer_init(&seq);
	if (printf_sequence(&seq, printf_prefix(format, states, subs)) || \
		printf_sequence(&seq, printf_zeros(states->precision)) || \
		printf_sequence(&seq, printf_num_sub(format, states->strlen, subs)) || \
		printf_sequence(&seq, printf_spaces(states->width)))
		return (-1);
	return (seq.sum);
}

static int	printf_sequence_with_precision_default(char format, \
struct s_printf_parser *states, va_list *subs)
{
	struct s_printf_sequencer	seq;

	printf_sequencer_init(&seq);
	if (printf_sequence(&seq, printf_spaces(states->width)) || \
		printf_sequence(&seq, printf_prefix(format, states, subs)) || \
		printf_sequence(&seq, printf_zeros(states->precision)) || \
		printf_sequence(&seq, printf_num_sub(format, states->strlen, subs)))
		return (-1);
	return (seq.sum);
}

int	printf_sequence_num_with_precision(char format, \
struct s_printf_parser *states, va_list *subs)
{
	struct s_printf_sequencer	seq;

	printf_sequencer_init(&seq);
	if (printf_has_flag(states, '-'))
	{
		return (printf_sequence_with_precision_minus(format, states, subs));
	}
	else
	{
		return (printf_sequence_with_precision_default(format, states, subs));
	}
}

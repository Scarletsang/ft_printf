/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_sequence.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:30:14 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 03:00:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sequence.h"

static int	printf_sequence_str_minus(char format, \
struct s_printf_parser *states, va_list *subs)
{
	struct s_printf_sequencer	seq;

	printf_sequencer_init(&seq);
	if (printf_sequence(&seq, printf_str_sub(format, states, subs)) || \
		printf_sequence(&seq, printf_spaces(states->width)))
		return (-1);
	return (seq.sum);
}

static int	printf_sequence_str_zero(char format, \
struct s_printf_parser *states, va_list *subs)
{
	struct s_printf_sequencer	seq;

	printf_sequencer_init(&seq);
	if (printf_sequence(&seq, printf_zeros(states->width)) || \
		printf_sequence(&seq, printf_str_sub(format, states, subs)))
		return (-1);
	return (seq.sum);
}

static int	printf_sequence_str_default(char format, \
struct s_printf_parser *states, va_list *subs)
{
	struct s_printf_sequencer	seq;

	printf_sequencer_init(&seq);
	if (printf_sequence(&seq, printf_spaces(states->width)) || \
		printf_sequence(&seq, printf_str_sub(format, states, subs)))
		return (-1);
	return (seq.sum);
}

int	printf_sequence_str(char format, struct s_printf_parser *states, \
va_list *subs)
{
	if (printf_has_flag(states, '-'))
	{
		return (printf_sequence_str_minus(format, states, subs));
	}
	else if (printf_has_flag(states, '0'))
	{
		return (printf_sequence_str_zero(format, states, subs));
	}
	else
	{
		return (printf_sequence_str_default(format, states, subs));
	}
}

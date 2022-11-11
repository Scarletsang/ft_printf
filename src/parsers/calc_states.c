/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:13:10 by htsang            #+#    #+#             */
/*   Updated: 2022/11/11 14:10:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsers.h"

static int	minus_without_neg(int a, int b)
{
	if (a > b)
	{
		return (a - b);
	}
	return (0);
}

static int	prefixlen(char format, t_parser *states, va_list *subs \
, int is_zero)
{
	char	has_plus_or_space;

	has_plus_or_space = has_flags(states, "+ ");
	if (format == 'u' && has_plus_or_space)
	{
		return (1);
	}
	if (ft_strchr("di", format) && \
	(peek(subs, &va_is_minus) || has_plus_or_space))
	{
		return (1);
	}
	if (format == 'p' || \
	(ft_strchr("xX", format) && has_flag(states, '#') && !is_zero))
	{
		return (2);
	}
	return (0);
}

static void	calc_states_num_with_precision(int prefixlen, t_parser *states)
{
	int	space_len;
	int	zero_len;

	space_len = 0;
	zero_len = 0;
	if (states->precision >= states->width)
		zero_len = minus_without_neg(states->precision, states->strlen);
	else
	{
		if (states->strlen < states->precision)
		{
			zero_len = states->precision - states->strlen;
			space_len = minus_without_neg(states->width, \
			states->precision + prefixlen);
		}
		else if (states->strlen + prefixlen < states->width)
		{
			space_len = states->width - states->strlen - prefixlen;
		}
	}
	states->width = space_len;
	states->precision = zero_len;
}

void	calc_states_num(char format, t_parser *states, va_list *subs)
{
	int	is_zero;
	int	prefix_len;

	is_zero = sub_is_zero(format, subs);
	prefix_len = prefixlen(format, states, subs, is_zero);
	if (is_zero)
	{
		states->strlen = !(states->precision == 0);
	}
	else
	{
		states->strlen = calc_numlen(subs, format);
	}
	if (has_precision(states))
	{
		calc_states_num_with_precision(prefix_len, states);
	}
	else
	{
		states->width = minus_without_neg(states->width, \
		states->strlen + prefix_len);
	}
}

void	calc_states_str(char format, t_parser *states, va_list *subs)
{
	states->strlen = 1;
	if (format == 's')
	{
		states->strlen = calc_strlen(subs);
		if (has_precision(states) && states->precision < states->strlen)
		{
			states->strlen = states->precision;
		}
	}
	states->width = minus_without_neg(states->width, states->strlen);
}

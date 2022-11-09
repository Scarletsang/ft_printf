/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:13:10 by htsang            #+#    #+#             */
/*   Updated: 2022/11/09 15:40:56 by htsang           ###   ########.fr       */
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

static int	prefixlen(char format, t_parser *states, va_list *subs)
{
	char	has_plus_or_space;

	has_plus_or_space = has_flags(states, "+ ");
	if (format == 'u' && has_plus_or_space)
	{
		return (1);
	}
	if (ft_strchr("di", format) && (sub_is_minus(subs) || has_plus_or_space))
	{
		return (1);
	}
	if (format == 'p' || (ft_strchr("xX", format) && has_flag(states, '#')))
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
			space_len = states->width - states->precision - prefixlen;
		}
		else if (states->strlen < states->width)
		{
			space_len = states->width - states->strlen - prefixlen;
		}
	}
	states->width = space_len;
	states->precision = zero_len;
}

void	calc_states_num(char format, t_parser *states, va_list *subs)
{
	if (sub_is_zero(subs))
	{
		states->strlen = !(states->precision == 0);
	}
	else
	{
		states->strlen = peek_va_arg_numlen(subs, format);
	}
	if (has_precision(states))
	{
		calc_states_num_with_precision(prefixlen(format, states, subs), states);
	}
	else
	{
		states->width = minus_without_neg(states->width, \
		states->strlen + prefixlen(format, states, subs));
	}
}

void	calc_states_str(char format, t_parser *states, va_list *subs)
{
	states->strlen = 1;
	if (!ft_strchr("c%", format))
	{
		states->strlen = peek_va_arg_strlen(subs);
	}
	if (has_precision(states) && states->precision < states->strlen)
	{
		states->strlen = states->precision;
	}
	states->width = minus_without_neg(states->width, states->strlen);
}

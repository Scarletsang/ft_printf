/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:13:10 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:22:04 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsers.h"

static int	printf_minus_without_neg(int a, int b)
{
	if (a > b)
	{
		return (a - b);
	}
	return (0);
}

static int	printf_prefixlen(char format, struct s_printf_parser *states, \
va_list *subs, int is_zero)
{
	char	has_plus_or_space;

	has_plus_or_space = printf_has_flags(states, "+ ");
	if (format == 'u' && has_plus_or_space)
	{
		return (1);
	}
	if (ft_strchr("di", format) && \
	(printf_va_peek(subs, &printf_va_is_minus) || has_plus_or_space))
	{
		return (1);
	}
	if (format == 'p' || \
	(ft_strchr("xX", format) && printf_has_flag(states, '#') && !is_zero))
	{
		return (2);
	}
	return (0);
}

static void	printf_calc_states_num_with_precision(int prefixlen, \
struct s_printf_parser *states)
{
	int	space_len;
	int	zero_len;

	space_len = 0;
	zero_len = 0;
	if (states->precision >= states->width)
		zero_len = printf_minus_without_neg(states->precision, states->strlen);
	else
	{
		if (states->strlen < states->precision)
		{
			zero_len = states->precision - states->strlen;
			space_len = printf_minus_without_neg(states->width, \
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

void	printf_calc_states_num(char format, struct s_printf_parser *states, \
va_list *subs)
{
	int	is_zero;
	int	prefix_len;

	is_zero = printf_sub_is_zero(format, subs);
	prefix_len = printf_prefixlen(format, states, subs, is_zero);
	if (is_zero)
	{
		states->strlen = !(states->precision == 0);
	}
	else
	{
		states->strlen = printf_calc_numlen(subs, format);
	}
	if (printf_has_precision(states))
	{
		printf_calc_states_num_with_precision(prefix_len, states);
	}
	else
	{
		states->width = printf_minus_without_neg(states->width, \
		states->strlen + prefix_len);
	}
}

void	printf_calc_states_str(char format, struct s_printf_parser *states, \
va_list *subs)
{
	states->strlen = 1;
	if (format == 's')
	{
		states->strlen = printf_calc_strlen(subs);
		if (printf_has_precision(states) && states->precision < states->strlen)
		{
			states->strlen = states->precision;
		}
	}
	states->width = printf_minus_without_neg(states->width, states->strlen);
}

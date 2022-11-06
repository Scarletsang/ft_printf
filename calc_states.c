/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:13:10 by htsang            #+#    #+#             */
/*   Updated: 2022/11/06 21:38:09 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	minus_without_neg(int a, int b)
{
	if (a > b)
	{
		return (a - b);
	}
	return (0);
}

static int	return_bigger(int a, int b)
{
	if (a > b)
	{
		return (a);
	}
	return (b);
}

static int	prefixlen(char format, t_parser *states)
{
	if (ft_strchr("diu", format) && has_flags(states, "+ "))
	{
		return (1);
	}
	if (ft_strchr("xX", format) && has_flag(states, '#') || format == 'p')
	{
		return (2);
	}
	return (0);
}

void	calc_states_str(char format, t_parser *states, va_list *subs)
{
	states->sub_strlen = 1;
	if (format != '%')
	{
		states->sub_strlen = va_arg_strlen(subs);
	}
	if (states->precision != -1 && states->precision < states->sub_strlen)
	{
		states->sub_strlen = states->precision;
	}
	states->width = minus_without_neg(states->width, states->sub_strlen);
}

void	calc_states_num(char format, t_parser *states, va_list *subs)
{
	int	space_len;
	int	zero_len;

	states->sub_strlen = va_arg_numlen(subs, format);
	if (states->precision == -1)
	{
		space_len = 0;
		zero_len = minus_without_neg(states->precision, states->sub_strlen);
		if (states->precision < states->width)
		{
			space_len = minus_without_neg(states->width, \
			return_bigger(zero_len, states->sub_strlen));
		}
		states->width = space_len;
		states->precision = zero_len;
	}
	else
	{
		states->sub_strlen += prefixlen(format, states);
		states->width = minus_without_neg(states->width, states->sub_strlen);
	}
}

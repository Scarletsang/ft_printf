/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:13:10 by htsang            #+#    #+#             */
/*   Updated: 2022/11/08 18:35:49 by htsang           ###   ########.fr       */
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

static void	calc_states_num_with_precision(int space_min, int zero_min, \
int strlen, t_parser *states)
{
	int	space_len;
	int	zero_len;

	space_len = 0;
	zero_len = 0;
	if (zero_min >= space_min)
		zero_len = minus_without_neg(zero_min, strlen);
	else
	{
		if (strlen < zero_min)
		{
			zero_len = zero_min - strlen;
			space_len = space_min - zero_min;
		}
		else if (strlen < space_min)
		{
			space_len = space_min - strlen;
		}
	}
	states->width = space_len;
	states->precision = zero_len;
}

void	calc_states_num(char format, t_parser *states, va_list *subs)
{
	if (sub_is_zero(subs))
	{
		states->sub_strlen = !(states->precision == 0);
	}
	else
	{
		states->sub_strlen = peek_va_arg_numlen(subs, format);
	}
	if (has_precision(states))
	{
		calc_states_num_with_precision(states->width, states->precision, \
		states->sub_strlen + prefixlen(format, states, subs), states);
	}
	else
	{
		states->width = minus_without_neg(states->width, \
		states->sub_strlen + prefixlen(format, states, subs));
	}
}

void	calc_states_str(char format, t_parser *states, va_list *subs)
{
	states->sub_strlen = 1;
	if (!ft_strchr("c%", format))
	{
		states->sub_strlen = peek_va_arg_strlen(subs);
	}
	if (has_precision(states) && states->precision < states->sub_strlen)
	{
		states->sub_strlen = states->precision;
	}
	states->width = minus_without_neg(states->width, states->sub_strlen);
}

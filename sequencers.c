/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequencers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:50:25 by htsang            #+#    #+#             */
/*   Updated: 2022/11/07 20:23:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_sequence_num_with_precision(char format, \
t_parser *states, va_list *subs)
{
	if (has_flag(states, '-'))
	{
		print_prefix(format, states);
		print_zeros(states->precision);
		print_num_sub(format, subs);
		print_spaces(states->width);
	}
	else
	{
		print_spaces(states->width);
		print_prefix(format, states);
		print_zeros(states->precision);
		print_num_sub(format, subs);
	}
}

void	print_sequence_num(char format, t_parser *states, va_list *subs)
{
	if (has_precision(states))
	{
		print_sequence_num_with_precision(format, states, subs);
		return ;
	}
	if (has_flag(states, '-'))
	{
		print_prefix(format, states);
		print_num_sub(format, subs);
		print_spaces(states->width);
	}
	else if (has_flag(states, '0'))
	{
		print_prefix(format, states);
		print_zeros(states->width);
		print_num_sub(format, subs);
	}
	else
	{
		print_spaces(states->width);
		print_prefix(format, states);
		print_num_sub(format, subs);
	}
}

void	print_sequence_str(char format, t_parser *states, va_list *subs)
{
	if (has_flag(states, '-'))
	{
		print_str_sub(format, states, subs);
		print_spaces(states->width);
	}
	else if (has_flag(states, '0'))
	{
		print_zeros(states->width);
		print_str_sub(format, states, subs);
	}
	else
	{
		print_spaces(states->width);
		print_str_sub(format, states, subs);
	}
}

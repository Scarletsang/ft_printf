/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:51:51 by htsang            #+#    #+#             */
/*   Updated: 2022/11/07 21:39:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_maybe_s(t_parser *states, va_list *subs)
{
	char	*str;

	str = va_arg(*subs, char *);
	if (str)
	{
		print_s(str, states->sub_strlen);
	}
	else
	{
		print_null(states->sub_strlen);
	}
}

void	print_str_sub(char format, t_parser *states, va_list *subs)
{
	if (format == 'c')
	{
		print_c(va_arg(*subs, int));
	}
	else if (format == '%')
	{
		print_c('%');
	}
	else
	{
		print_maybe_s(states, subs);
	}
}

void	print_num_sub(char format, va_list *subs)
{
	if (ft_strchr("di", format))
	{
		print_di(va_arg(*subs, int));
	}
	else if (format == 'u')
	{
		print_u(va_arg(*subs, unsigned int));
	}
	else if (format == 'X')
	{
		print_x_upper(va_arg(*subs, unsigned int));
	}
	else
	{
		print_xp(va_arg(*subs, unsigned int));
	}
}

void	print_prefix(char format, t_parser *states)
{
	if (format == 'p' || (ft_strchr("xX", format) && has_flag(states, '#')))
	{
		print_0x();
	}
	else if (has_flag(states, '+'))
	{
		print_plus();
	}
	else if (has_flag(states, ' '))
	{
		print_spaces(1);
	}
}

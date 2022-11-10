/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution_printer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:51:51 by htsang            #+#    #+#             */
/*   Updated: 2022/11/10 19:59:38 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_maybe_s(t_parser *states, va_list *subs)
{
	char	*str;

	str = va_arg(*subs, char *);
	if (str)
	{
		print_s(str, states->strlen);
	}
	else
	{
		print_null(states->strlen);
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

void	print_num_sub(char format, char write_zero, va_list *subs)
{
	if (write_zero <= 0)
	{
		va_arg(*subs, int);
		return ;
	}
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
	else if (format == 'x')
	{
		print_x(va_arg(*subs, unsigned int));
	}
	else
	{
		print_p(va_arg(*subs, size_t));
	}
}

void	print_prefix(char format, t_parser *states, va_list *subs)
{
	if (format == 'p' || (ft_strchr("xX", format) && \
	has_flag(states, '#') && !sub_is_zero(format, subs)))
	{
		print_0x(ft_isupper(format));
	}
	else if (ft_strchr("di", format) && peek(subs, &va_is_minus))
	{
		print_minus();
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

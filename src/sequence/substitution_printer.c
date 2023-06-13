/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution_printer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:51:51 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 03:00:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sequence.h"

static int	printf_maybe_s(struct s_printf_parser *states, va_list *subs)
{
	char	*str;

	str = va_arg(*subs, char *);
	if (str)
	{
		return (printf_s(str, states->strlen));
	}
	else
	{
		return (printf_null(states->strlen));
	}
}

int	printf_str_sub(char format, struct s_printf_parser *states, va_list *subs)
{
	if (format == 'c')
	{
		return (printf_c(va_arg(*subs, int)));
	}
	else if (format == '%')
	{
		return (printf_c('%'));
	}
	else
	{
		return (printf_maybe_s(states, subs));
	}
}

int	printf_num_sub(char format, char write_zero, va_list *subs)
{
	if (write_zero <= 0)
	{
		va_arg(*subs, int);
		return (0);
	}
	if (ft_strchr("di", format))
	{
		return (printf_di(va_arg(*subs, int)));
	}
	else if (format == 'u')
	{
		return (printf_u(va_arg(*subs, unsigned int)));
	}
	else if (format == 'X')
	{
		return (printf_x_upper(va_arg(*subs, unsigned int)));
	}
	else if (format == 'x')
	{
		return (printf_x(va_arg(*subs, unsigned int)));
	}
	else
	{
		return (printf_p(va_arg(*subs, size_t)));
	}
}

int	printf_prefix(char format, struct s_printf_parser *states, va_list *subs)
{
	if (format == 'p' || (ft_strchr("xX", format) && \
		printf_has_flag(states, '#') && !printf_sub_is_zero(format, subs)))
	{
		return (printf_0x(ft_isupper(format)));
	}
	else if (ft_strchr("di", format) && \
		printf_va_peek(subs, &printf_va_is_minus))
	{
		return (printf_minus());
	}
	else if (printf_has_flag(states, '+'))
	{
		return (printf_plus());
	}
	else if (printf_has_flag(states, ' '))
	{
		return (printf_spaces(1));
	}
	return (0);
}

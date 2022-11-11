/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:15:07 by htsang            #+#    #+#             */
/*   Updated: 2022/11/10 19:52:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsers.h"

int	peek(va_list *subs, t_peek_func getter)
{
	va_list		copy;
	long long	result;

	va_copy(copy, *subs);
	result = getter(&copy);
	va_end(copy);
	return (result);
}

long long	va_is_minus(va_list *subs)
{
	return ((int) va_arg(*subs, int) < 0);
}

long long	va_is_zero(va_list *subs)
{
	return ((int) va_arg(*subs, long long) == 0);
}

long long	va_ptr_is_zero(va_list *subs)
{
	return ((size_t) va_arg(*subs, size_t) == 0);
}

int	sub_is_zero(char format, va_list *subs)
{
	if (format == 'p')
	{
		return (peek(subs, va_ptr_is_zero));
	}
	return (peek(subs, va_is_zero));
}

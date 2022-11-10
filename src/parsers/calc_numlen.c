/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_numlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:18:47 by htsang            #+#    #+#             */
/*   Updated: 2022/11/10 19:44:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsers.h"

static long long	va_int_len(va_list *subs)
{
	return ((int) ft_numlen(va_arg(*subs, int), 10));
}

static long long	va_u_int_len_base_10(va_list *subs)
{
	return ((int) ft_numlen(va_arg(*subs, unsigned int), 10));
}

static long long	va_u_int_len_base_16(va_list *subs)
{
	return ((int) ft_numlen(va_arg(*subs, unsigned int), 16));
}

static long long	va_pointer_len(va_list *subs)
{
	return ((int) ft_ptrlen(va_arg(*subs, size_t)));
}

int	calc_numlen(va_list *subs, char format)
{
	if (ft_strchr("di", format))
	{
		return (peek(subs, &va_int_len));
	}
	if (format == 'u')
	{
		return (peek(subs, &va_u_int_len_base_10));
	}
	if (ft_strchr("xX", format))
	{
		return (peek(subs, &va_u_int_len_base_16));
	}
	if (format == 'p')
	{
		return (peek(subs, &va_pointer_len));
	}
	return (-1);
}

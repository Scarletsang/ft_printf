/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_numlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:18:47 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:17:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsers.h"

static long long	printf_va_int_len(va_list *subs)
{
	return ((int) ft_numlen(va_arg(*subs, int), 10));
}

static long long	printf_va_u_int_len_base_10(va_list *subs)
{
	return ((int) ft_numlen(va_arg(*subs, unsigned int), 10));
}

static long long	printf_va_u_int_len_base_16(va_list *subs)
{
	return ((int) ft_numlen(va_arg(*subs, unsigned int), 16));
}

static long long	printf_va_pointer_len(va_list *subs)
{
	return ((int) ft_ptrlen(va_arg(*subs, size_t)));
}

int	printf_calc_numlen(va_list *subs, char format)
{
	if (ft_strchr("di", format))
	{
		return (printf_va_peek(subs, &printf_va_int_len));
	}
	if (format == 'u')
	{
		return (printf_va_peek(subs, &printf_va_u_int_len_base_10));
	}
	if (ft_strchr("xX", format))
	{
		return (printf_va_peek(subs, &printf_va_u_int_len_base_16));
	}
	if (format == 'p')
	{
		return (printf_va_peek(subs, &printf_va_pointer_len));
	}
	return (-1);
}

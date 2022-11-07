/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:18:47 by htsang            #+#    #+#             */
/*   Updated: 2022/11/07 22:34:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsers.h"

static int	peek_int_len(va_list *args)
{
	va_list	copy;
	int		len;

	va_copy(copy, *args);
	len = ft_numlen(va_arg(copy, int), 10);
	va_end(copy);
	return (len);
}

static int	peek_unsigned_int_len(va_list *args, int base)
{
	va_list	copy;
	int		len;

	va_copy(copy, *args);
	len = ft_numlen(va_arg(copy, unsigned int), base);
	va_end(copy);
	return (len);
}

static int	peek_pointer_len(va_list *args)
{
	va_list	copy;
	int		len;

	va_copy(copy, *args);
	len = ft_ptrlen(va_arg(copy, size_t));
	va_end(copy);
	return (len);
}

int	peek_va_arg_numlen(va_list *subs, char format)
{
	if (ft_strchr("di", format))
	{
		return (peek_int_len(subs));
	}
	if (format == 'u')
	{
		return (peek_unsigned_int_len(subs, 10));
	}
	if (ft_strchr("xX", format))
	{
		return (peek_unsigned_int_len(subs, 16));
	}
	if (format == 'p')
	{
		return (peek_pointer_len(subs));
	}
	return (-1);
}

int	peek_va_arg_strlen(va_list *subs)
{
	va_list	copy;
	char	*str;
	int		len;

	va_copy(copy, *subs);
	str = va_arg(copy, char *);
	len = 6;
	if (str)
	{
		len = (int) ft_strlen(str);
	}
	va_end(copy);
	return (len);
}

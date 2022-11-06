/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:18:47 by htsang            #+#    #+#             */
/*   Updated: 2022/11/06 21:38:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	numlen(long n, int base)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

static int	va_arg_intlen(va_list *args)
{
	va_list	copy;
	int		len;

	va_copy(*args, copy);
	len = numlen(va_arg(copy, int), 10);
	va_close(copy);
	return (len);
}

static int	va_arg_unsigned_intlen(va_list *args, int base)
{
	va_list	copy;
	int		len;

	va_copy(*args, copy);
	len = numlen(va_arg(copy, unsigned int), base);
	va_close(copy);
	return (len);
}

int	va_arg_numlen(va_list *subs, char format)
{
	if (ft_strchr("di", format))
	{
		return (va_arg_intlen(subs));
	}
	if (format == 'u')
	{
		return (va_arg_unsigned_intlen(subs, 10));
	}
	if (ft_strchr("xXp", format))
	{
		return (va_arg_unsigned_intlen(subs, 16));
	}
	return (-1);
}

int	va_arg_strlen(va_list *args)
{
	va_list	copy;
	int		len;

	va_copy(*args, copy);
	len = ft_strlen(va_arg(copy, char *));
	va_close(copy);
	return (len);
}

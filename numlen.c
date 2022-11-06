/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:18:47 by htsang            #+#    #+#             */
/*   Updated: 2022/11/06 14:24:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

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

int	va_arg_intlen(va_list *args, int base)
{
	va_list	copy;
	int		len;

	va_copy(*args, copy);
	len = numlen(va_arg(copy, int), base);
	va_close(copy);
	return (len);
}

int	va_arg_unsigned_intlen(va_list *args, int base)
{
	va_list	copy;
	int		len;

	va_copy(*args, copy);
	len = numlen(va_arg(copy, unsigned int), base);
	va_close(copy);
	return (len);
}

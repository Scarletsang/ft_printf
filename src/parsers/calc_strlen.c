/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:18:47 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:08:00 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsers.h"

static long long	printf_va_strlen(va_list *subs)
{
	char	*str;
	int		len;

	str = va_arg(*subs, char *);
	len = 6;
	if (str)
	{
		len = (int) ft_strlen(str);
	}
	return (len);
}

int	printf_calc_strlen(va_list *subs)
{
	return (printf_va_peek(subs, &printf_va_strlen));
}

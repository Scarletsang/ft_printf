/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xXp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:02:49 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:16:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

int	printf_p(size_t p)
{
	return (printf_hex(p, 'a'));
}

int	printf_x(unsigned int n)
{
	return (printf_hex(n, 'a'));
}

int	printf_x_upper(unsigned int n)
{
	return (printf_hex(n, 'A'));
}

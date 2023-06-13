/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:24:36 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 03:35:52 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

int	printf_c(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

int	printf_s(char *str, unsigned int len)
{
	return (write(STDOUT_FILENO, str, len));
}

int	printf_null(unsigned int len)
{
	return (write(STDOUT_FILENO, "(null)", len));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:25:15 by htsang            #+#    #+#             */
/*   Updated: 2022/11/03 00:41:50 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_printer	*init_printer(const char *str)
{
	t_printer	printer;

	printer.location = str;
	printer.size = 0;
	return (&printer);
}

void	print_any(t_printer *printer, char *str, size_t len)
{
	write(1, str, len);
	printer->size += len;
}

void	printf_current(t_printer *printer, size_t len)
{
	write(1, printer->location, len);
	printer->size += len;
}

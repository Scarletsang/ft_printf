/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 00:25:15 by htsang            #+#    #+#             */
/*   Updated: 2022/11/03 17:00:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

int	*printer(char *str, size_t len)
{
	static int	size = 0;

	write(1, str, len);
	size += len;
	return (&size);
}

int	close_printer(void)
{
	int	size;
	int	*size_ptr;

	size_ptr = printer("", 0);
	size = *size_ptr;
	*size_ptr = 0;
	return (size);
}

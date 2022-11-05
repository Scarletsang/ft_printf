/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:22:54 by htsang            #+#    #+#             */
/*   Updated: 2022/11/05 19:59:50 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

void	print_zeros(size_t len)
{
	while (len)
	{
		printer("0", 1);
	}
}

void	print_spaces(size_t len)
{
	while (len)
	{
		printer(" ", 1);
	}
}

void	print_plus(void)
{
	printer("+", 1);
}

void	print_minus(void)
{
	printer("-", 1);
}

void	print_0x(void)
{
	printer("0x", 2);
}
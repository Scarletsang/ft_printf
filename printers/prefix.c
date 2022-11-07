/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:22:54 by htsang            #+#    #+#             */
/*   Updated: 2022/11/07 20:07:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

void	print_zeros(unsigned int len)
{
	while (len)
	{
		printer("0", 1);
		len--;
	}
}

void	print_spaces(unsigned int len)
{
	while (len)
	{
		printer(" ", 1);
		len--;
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

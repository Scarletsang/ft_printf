/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:24:36 by htsang            #+#    #+#             */
/*   Updated: 2022/11/07 21:35:31 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

void	print_c(char c)
{
	printer(&c, 1);
}

void	print_s(char *str, unsigned int len)
{
	printer(str, len);
}

void	print_null(unsigned int len)
{
	printer("(null)", len);
}

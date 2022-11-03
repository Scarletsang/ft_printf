/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:24:36 by htsang            #+#    #+#             */
/*   Updated: 2022/11/03 17:35:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	print_c(va_list *subs)
{
	char	c;

	c = va_arg(*subs, char);
	printer(&c, 1);
}

void	print_s(va_list *subs)
{
	char	*str;

	str = va_arg(*subs, char *);
	printer(str, ft_strlen(str));
}
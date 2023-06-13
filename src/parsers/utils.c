/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:01:42 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 02:16:44 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsers.h"

char	printf_has_flag(struct s_printf_parser *states, char flag)
{
	int	i;

	if (!states->flags_end)
	{
		return (0);
	}
	i = 0;
	while (*(states->flags_end - i) != '%')
	{
		if (*(states->flags_end - i) == flag)
		{
			return (flag);
		}
		i++;
	}
	return (0);
}

char	printf_has_flags(struct s_printf_parser *states, char *flags)
{
	int		i;

	if (!states->flags_end)
	{
		return (0);
	}
	i = 0;
	while (*(states->flags_end - i) != '%')
	{
		if (ft_strchr(flags, *(states->flags_end - i)))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	printf_has_precision(struct s_printf_parser *states)
{
	return (states->precision > -1);
}

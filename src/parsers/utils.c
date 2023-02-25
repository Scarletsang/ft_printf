/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:01:42 by htsang            #+#    #+#             */
/*   Updated: 2022/11/10 19:15:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsers.h"

char	has_flag(t_parser *states, char flag)
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

char	has_flags(t_parser *states, char *flags)
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

char	has_precision(t_parser *states)
{
	return (states->precision > -1);
}

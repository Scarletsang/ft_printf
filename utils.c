/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:01:42 by htsang            #+#    #+#             */
/*   Updated: 2022/11/06 21:38:02 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	has_flag(t_parser *states, char flag)
{
	int	i;

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
	char	match;

	i = 0;
	while (*(states->flags_end - i) != '%')
	{
		match = ft_strchr(flags, *(states->flags_end - i));
		if (match)
		{
			return (match);
		}
		i++;
	}
	return (0);
}

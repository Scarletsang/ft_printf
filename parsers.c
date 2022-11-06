/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:13:10 by htsang            #+#    #+#             */
/*   Updated: 2022/11/06 14:28:08 by htsang           ###   ########.fr       */
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

void	run_parser(char format, t_parser *states, )
{

}

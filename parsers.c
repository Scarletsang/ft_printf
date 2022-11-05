/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:47:24 by htsang            #+#    #+#             */
/*   Updated: 2022/11/05 19:19:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_parser	*init_parser(void)
{
	t_parser	parser;

	parser.flags_end = NULL;
	parser.width = 0;
	parser.precision = -1;
	parser.check_failed = 1;
	return (&parser);
}

void	run_parser(char **str, t_parser *states, t_parser_func parser)
{
	while (**str)
	{
		parser(*str, &states);
		if (states->check_failed)
		{
			return ;
		}
		else
		{
			*str++;
		}
	}
}

void	parse_flags(const char *str, t_parser *states)
{
	states->check_failed = 1;
	if (ft_strchr("+ #0-", *str))
	{
		states->flags_end = str;
		states->check_failed = 0;
	}
}

void	parse_width(const char *str, t_parser *states)
{
	states->check_failed = 1;
	if (ft_isdigit(*str))
	{
		states->width = states->width * 10 + (*str - '0');
		states->check_failed = 0;
	}
}

void	parse_precision(const char *str, t_parser *states)
{
	states->check_failed = 1;
	if (ft_isdigit(*str))
	{
		states->precision = states->precision * 10 + (*str - '0');
		states->check_failed = 0;
	}
}

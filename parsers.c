/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:47:24 by htsang            #+#    #+#             */
/*   Updated: 2022/11/03 00:41:43 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_parser	*init_parser(void)
{
	t_parser	parser;

	parser.flags_end = NULL;
	parser.min_width = 0;
	parser.max_width = -1;
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

void	parse_min(const char *str, t_parser *states)
{
	states->check_failed = 1;
	if (ft_isdigit(*str))
	{
		states->min_width = states->min_width * 10 + (*str - '0');
		states->check_failed = 0;
	}
}

void	parse_max(const char *str, t_parser *states)
{
	states->check_failed = 1;
	if (ft_isdigit(*str))
	{
		states->max_width = states->max_width * 10 + (*str - '0');
		states->check_failed = 0;
	}
}

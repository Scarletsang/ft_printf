/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:47:24 by htsang            #+#    #+#             */
/*   Updated: 2022/11/09 15:40:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsers.h"

void	init_parser(t_parser *parser)
{
	parser->flags_end = NULL;
	parser->width = 0;
	parser->precision = -1;
	parser->strlen = 0;
}

void	run_parser(const char **str, t_parser *states, t_lexer_func parser)
{
	while (*str)
	{
		if (parser(*str, states))
		{
			return ;
		}
		else
		{
			(*str)++;
		}
	}
}

char	parse_flags(const char *str, t_parser *states)
{
	char	check_failed;

	check_failed = 1;
	if (ft_strchr("+ #0-", *str))
	{
		states->flags_end = (char *) str;
		check_failed = 0;
	}
	return (check_failed);
}

char	parse_width(const char *str, t_parser *states)
{
	char	check_failed;

	check_failed = 1;
	if (ft_isdigit(*str))
	{
		states->width = states->width * 10 + (*str - '0');
		check_failed = 0;
	}
	return (check_failed);
}

char	parse_precision(const char *str, t_parser *states)
{
	char	check_failed;

	check_failed = 1;
	if (ft_isdigit(*str))
	{
		states->precision = states->precision * 10 + (*str - '0');
		check_failed = 0;
	}
	return (check_failed);
}

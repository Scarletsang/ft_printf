/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:47:24 by htsang            #+#    #+#             */
/*   Updated: 2022/11/06 14:38:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_parser	*init_lexer(void)
{
	t_parser	lexer;

	lexer.flags_end = NULL;
	lexer.width = 0;
	lexer.precision = -1;
	lexer.sub_strlen = 0;
	return (&lexer);
}

void	run_lexer(char **str, t_parser *states, t_lexer_func lexer)
{
	while (**str)
	{
		if (lexer(*str, &states))
		{
			return ;
		}
		else
		{
			*str++;
		}
	}
}

char	lex_flags(const char *str, t_parser *states)
{
	char	check_failed;

	check_failed = 1;
	if (ft_strchr("+ #0-", *str))
	{
		states->flags_end = str;
		check_failed = 0;
	}
	return (check_failed);
}

char	lex_width(const char *str, t_parser *states)
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

char	lex_precision(const char *str, t_parser *states)
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

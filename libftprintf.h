/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:39:24 by htsang            #+#    #+#             */
/*   Updated: 2022/11/05 19:27:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_parser
{
	char	*flags_end;
	int		width;
	int		precision;
	char	check_failed;
}				t_parser;

typedef void	(*t_parser_func)(const char *, t_parser *);

///////////////////////////
//////    Parsers    //////
///////////////////////////

t_parser	*init_parser(void);

void		run_parser(char **str, t_parser *states, t_parser_func parser);

void		parse_flags(const char *str, t_parser *states);

void		parse_width(const char *str, t_parser *states);

void		parse_precision(const char *str, t_parser *states);

//////////////////////////////
//////    Core logic    //////
//////////////////////////////

const char	*run_printer_logic(const char *str, \
t_parser states, va_list *subs);

const char	*run_parser_logic(const char *str, va_list *subs);

int			simple_printer_logic(const char *str, va_list *subs);

#endif
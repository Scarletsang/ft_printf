/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:39:24 by htsang            #+#    #+#             */
/*   Updated: 2022/11/06 14:19:14 by htsang           ###   ########.fr       */
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
	int		sub_strlen;
}				t_parser;

typedef char	(*t_lexer_func)(const char *, t_parser *);

///////////////////////////
//////    Lexers    //////
///////////////////////////

t_parser	*init_lexer(void);

void		run_lexer(char **str, t_parser *states, t_lexer_func parser);

char		lex_flags(const char *str, t_parser *states);

char		lex_width(const char *str, t_parser *states);

char		lex_precision(const char *str, t_parser *states);

///////////////////////////
//////    Parsers    //////
///////////////////////////

int			va_arg_intlen(va_list *args, int base);

int			va_arg_unsigned_intlen(va_list *args, int base);

//////////////////////////////
//////    Core logic    //////
//////////////////////////////

const char	*run_printer_logic(const char *str, \
t_parser *states, va_list *subs);

const char	*run_parser_logic(const char *str, va_list *subs);

int			simple_printer_logic(const char *str, va_list *subs);

#endif
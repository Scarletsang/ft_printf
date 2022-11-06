/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:39:24 by htsang            #+#    #+#             */
/*   Updated: 2022/11/06 21:44:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

/**
 * in cs%:
 * width = fill_len
 * precision = -1
 * 
 * in diuxXp:
 * width = space_len / fill_len
 * precision = zero_len
*/
typedef struct s_parser
{
	char	*flags_end;
	int		width;
	int		precision;
	int		sub_strlen;
}				t_parser;

typedef char	(*t_lexer_func)(const char *, t_parser *);

///////////////////////////////
//////    Target func    //////
///////////////////////////////

int			ft_printf(const char *str, ...);

///////////////////////////
//////    Parsers    //////
///////////////////////////

t_parser	*init_parser(void);

void		run_parser(char **str, t_parser *states, t_lexer_func parser);

char		parse_flags(const char *str, t_parser *states);

char		parse_width(const char *str, t_parser *states);

char		parse_precision(const char *str, t_parser *states);

///////////////////////////////
//////    Calculators    //////
///////////////////////////////

int			va_arg_numlen(va_list *subs, char format);

int			va_arg_strlen(va_list *args);

void		calc_states_str(char format, t_parser *states, va_list *subs);

void		calc_states_num(char format, t_parser *states, va_list *subs);

///////////////////////////
//////     Utils     //////
///////////////////////////

char		has_flag(t_parser *states, char flag);

char		has_flags(t_parser *states, char *flags);

//////////////////////////////
//////    Core logic    //////
//////////////////////////////

const char	*run_printer_logic(const char *str, \
t_parser *states, va_list *subs);

const char	*run_parser_logic(const char *str, va_list *subs);

int			main_logic(const char *str, va_list *subs);

#endif
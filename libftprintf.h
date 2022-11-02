/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:39:24 by htsang            #+#    #+#             */
/*   Updated: 2022/11/03 00:46:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
# include "libft/libft.h"

typedef struct s_parser
{
	char	*flags_end;
	int		min_width;
	int		max_width;
	char	check_failed;
}				t_parser;

typedef struct s_printer_states
{
	const char	*location;
	int			size;
}				t_printer;

typedef void	(*t_parser_func)(const char *, t_parser *);

///////////////////////////
//////    Parsers    //////
///////////////////////////

t_parser	*init_parser(void);

void		run_parser(char **str, t_parser *states, t_parser_func parser);

void		parse_flags(const char *str, t_parser *states);

void		parse_min(const char *str, t_parser *states);

void		parse_max(const char *str, t_parser *states);

////////////////////////////
//////    Printers    //////
////////////////////////////

t_printer	*init_printer(const char *str);

void		print_any(t_printer *printer, char *str, size_t len);

void		printf_current(t_printer *printer, size_t len);

//////////////////////////////
//////    Core logic    //////
//////////////////////////////

t_printer	*substitution_printer_logic(t_printer *printer, \
t_parser states, va_list subs);

t_printer	*substitution_logic(t_printer *printer, va_list subs);

void	simple_printer_logic(const char *str, va_list subs);

#endif
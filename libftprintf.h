/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:39:24 by htsang            #+#    #+#             */
/*   Updated: 2022/11/03 17:25:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_parser
{
	char	*flags_end;
	int		min_width;
	int		max_width;
	char	check_failed;
}				t_parser;

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

int			*printer(char *str, size_t len);

int			close_printer(void);

//////////////////////////////
//////    Core logic    //////
//////////////////////////////

const char	*run_printer_logic(const char *str, \
t_parser states, va_list *subs);

const char	*run_parser_logic(const char *str, va_list *subs);

int			simple_printer_logic(const char *str, va_list *subs);

#endif
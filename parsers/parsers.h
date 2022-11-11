/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:39:24 by htsang            #+#    #+#             */
/*   Updated: 2022/11/10 19:43:31 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSERS_H
# define PARSERS_H

# include <stdarg.h>
# include "../libft/libft.h"

/**
 * @brief A strict to be constructed by parsers, and passed
 * to printers to print out the substitution with the correct
 * format.
 * 
 * @details during the initial parsing, the struct wouuld be used
 * to store values collected by the parsers. After that, calculators
 * would perform calculations on the struct itself, and they have
 * slightly different meaning in string(cs%) and number(diuxXp)
 * substitution:
 * 
 * @param flags_end: The end of an array of flags, array always started
 * with a '%'.
 * @param width: length of filler chars (in cs%), 
 * length of spaces (with .) or filler chars (in diuxXp).
 * @param precision: unused (in cs%), length of zeros (in diuxXp)
 * @param strlen: characters to print of the substitution string
*/
typedef struct s_parser
{
	char	*flags_end;
	int		width;
	int		precision;
	int		strlen;
}				t_parser;

typedef char		(*t_lexer_func)(const char *, t_parser *);

typedef long long	(*t_peek_func)(va_list *);

///////////////////////////
//////    Parsers    //////
///////////////////////////

void		init_parser(t_parser *parser);

void		run_parser(const char **str, t_parser *states, t_lexer_func parser);

char		parse_flags(const char *str, t_parser *states);

char		parse_width(const char *str, t_parser *states);

char		parse_precision(const char *str, t_parser *states);

///////////////////////////////
//////    Calculators    //////
///////////////////////////////

int			calc_numlen(va_list *subs, char format);

int			calc_strlen(va_list *subs);

void		calc_states_str(char format, t_parser *states, va_list *subs);

void		calc_states_num(char format, t_parser *states, va_list *subs);

///////////////////////////
//////     Utils     //////
///////////////////////////

char		has_flag(t_parser *states, char flag);

char		has_flags(t_parser *states, char *flags);

char		has_precision(t_parser *states);

int			peek(va_list *subs, t_peek_func getter);

long long	va_is_minus(va_list *subs);

long long	va_is_zero(va_list *subs);

long long	va_ptr_is_zero(va_list *subs);

int			sub_is_zero(char format, va_list *subs);

#endif
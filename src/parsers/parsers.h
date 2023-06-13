/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:39:24 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 02:35:52 by htsang           ###   ########.fr       */
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
struct s_printf_parser
{
	char	*flags_end;
	int		width;
	int		precision;
	int		strlen;
};

typedef char		(*t_parser_func)(const char *, struct s_printf_parser *);

typedef long long	(*t_peek_func)(va_list *);

///////////////////////////
//////    Parsers    //////
///////////////////////////

void		printf_parser_init(struct s_printf_parser *parser);

void		printf_parser_run(char **str, struct s_printf_parser *states, \
t_parser_func parser);

char		printf_parse_flags(const char *str, struct s_printf_parser *states);

char		printf_parse_width(const char *str, struct s_printf_parser *states);

char		printf_parse_precision(const char *str, \
struct s_printf_parser *states);

///////////////////////////////
//////    Calculators    //////
///////////////////////////////

int			printf_calc_numlen(va_list *subs, char format);

int			printf_calc_strlen(va_list *subs);

void		printf_calc_states_str(char format, struct s_printf_parser *states, \
va_list *subs);

void		printf_calc_states_num(char format, struct s_printf_parser *states, \
va_list *subs);

///////////////////////////
//////     Utils     //////
///////////////////////////

char		printf_has_flag(struct s_printf_parser *states, char flag);

char		printf_has_flags(struct s_printf_parser *states, char *flags);

char		printf_has_precision(struct s_printf_parser *states);

int			printf_va_peek(va_list *subs, t_peek_func getter);

long long	printf_va_is_minus(va_list *subs);

long long	printf_va_is_zero(va_list *subs);

long long	printf_va_ptr_is_zero(va_list *subs);

int			printf_sub_is_zero(char format, va_list *subs);

#endif
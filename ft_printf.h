/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:39:24 by htsang            #+#    #+#             */
/*   Updated: 2022/11/08 17:16:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "parsers/parsers.h"
# include "printers/printers.h"

///////////////////////////////
//////    Target func    //////
///////////////////////////////

int			ft_printf(const char *str, ...);

//////////////////////////////
//////    Core logic    //////
//////////////////////////////

const char	*run_parser_logic(const char *str, t_parser *states, va_list *subs);

int			run_main_logic(const char *str, va_list *subs);

//////////////////////////////
//////    Sequencers    //////
//////////////////////////////

void		print_sequence_num(char format, t_parser *states, \
va_list *subs);

void		print_sequence_str(char format, t_parser *states, \
va_list *subs);

void		print_str_sub(char format, t_parser *states, va_list *subs);

void		print_num_sub(char format, char write_zero, va_list *subs);

void		print_prefix(char format, t_parser *states, va_list *subs);

#endif
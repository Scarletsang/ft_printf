/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:39:24 by htsang            #+#    #+#             */
/*   Updated: 2022/11/07 14:37:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "parsers/parsers.h"
# include "printers/printers.h"

///////////////////////////////
//////    Target func    //////
///////////////////////////////

int			ft_printf(const char *str, ...);

//////////////////////////////
//////    Core logic    //////
//////////////////////////////

const char	*run_printer_logic(const char *str, \
t_parser *states, va_list *subs);

const char	*run_parser_logic(const char *str, va_list *subs);

int			main_logic(const char *str, va_list *subs);

#endif
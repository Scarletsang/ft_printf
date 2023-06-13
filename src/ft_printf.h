/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:39:24 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 02:09:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "parsers/parsers.h"
# include "printers/printers.h"

///////////////////////////////
//////    Target func    //////
///////////////////////////////

int	ft_printf(const char *str, ...);

//////////////////////////////
//////    Core logic    //////
//////////////////////////////

int	printf_control(const char *str, va_list *subs);

//////////////////////////////
//////    Sequencers    //////
//////////////////////////////

int	printf_sequence_num(char format, struct s_printf_parser *states, \
va_list *subs);

int	printf_sequence_str(char format, struct s_printf_parser *states, \
va_list *subs);

#endif
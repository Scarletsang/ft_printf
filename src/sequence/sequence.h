/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:26:56 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 02:09:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEQUENCE_H
# define SEQUENCE_H

# include "../parsers/parsers.h"
# include "../printers/printers.h"

int	printf_str_sub(char format, struct s_printf_parser *states, va_list *subs);

int	printf_num_sub(char format, char write_zero, va_list *subs);

int	printf_prefix(char format, struct s_printf_parser *states, va_list *subs);

///////////////////////
////// private ////////
///////////////////////

int	printf_sequence_num_with_precision(char format, \
struct s_printf_parser *states, va_list *subs);

#endif
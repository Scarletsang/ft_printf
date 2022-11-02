/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:39:20 by htsang            #+#    #+#             */
/*   Updated: 2022/11/03 00:46:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

t_printer	*substitution_printer_logic(t_printer *printer, \
t_parser states, va_list subs)
{
}

t_printer	*substitution_logic(t_printer *printer, va_list subs)
{
	char		*original_runner;
	t_parser	*parser_info;

	original_runner = printer->location;
	parser_info = init_parser();
	run_parser(&printer->location, parser_info, &parse_flags);
	run_parser(&printer->location, parser_info, &parse_min);
	if (*printer->location++ == '.')
	{
		run_parser(&printer->location, parser_info, &parse_max);
	}
	if (ft_strchr(*printer->location, "cspdiuxX"))
	{
		return (substitution_printer_logic(printer, *parser_info, subs));
	}
	printer->location = original_runner;
	return (printer);
}

void	simple_printer_logic(const char *str, va_list subs)
{
	t_printer	*printer;

	printer = init_printer(str);
	while (*printer->location)
	{
		if (*printer->location == '%')
		{
			if (*++printer->location != '%')
			{
				printer = substitution_logic(printer, subs);
				continue ;
			}
		}
		printf_current(printer, 1);
		printer->location++;
	}
}

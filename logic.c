/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:39:20 by htsang            #+#    #+#             */
/*   Updated: 2022/11/03 17:25:06 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char	*run_printer_logic(const char *str, \
t_parser states, va_list *subs)
{
}

const char	*run_parser_logic(const char *str, va_list *subs)
{
	const char	*original_str;
	t_parser	*states;

	original_str = str;
	states = init_parser();
	run_parser(&str, states, &parse_flags);
	run_parser(&str, states, &parse_min);
	if (*str++ == '.')
	{
		states->max_width = 0;
		run_parser(&str, states, &parse_max);
	}
	if (ft_strchr(*str, "cspdiuxX%"))
	{
		return (run_printer_logic(str, *states, subs));
	}
	return (original_str);
}

int	simple_printer_logic(const char *str, va_list *subs)
{
	while (*str)
	{
		if (*++str == '%')
		{
			str = run_parser_logic(str, subs);
			continue ;
		}
		printer(str, 1);
		str++;
	}
	return (close_printer());
}

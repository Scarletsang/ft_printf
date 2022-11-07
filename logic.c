/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:39:20 by htsang            #+#    #+#             */
/*   Updated: 2022/11/07 21:57:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*run_parser_logic(const char *str, t_parser *states, va_list *subs)
{
	const char	*original_str;

	original_str = str;
	run_parser(&str, states, &parse_flags);
	run_parser(&str, states, &parse_width);
	if (*str == '.')
	{
		states->precision = 0;
		str++;
		run_parser(&str, states, &parse_precision);
	}
	if (ft_strchr("cs%", *str))
	{
		calc_states_str(*str, states, subs);
		print_sequence_str(*str, states, subs);
		return (++str);
	}
	else if (ft_strchr("diuxXp", *str))
	{
		calc_states_num(*str, states, subs);
		print_sequence_num(*str, states, subs);
		return (++str);
	}
	return (original_str);
}

int	run_main_logic(const char *str, va_list *subs)
{
	t_parser	states;

	while (*str)
	{
		if (*str == '%')
		{
			init_parser(&states);
			str = run_parser_logic(++str, &states, subs);
			continue ;
		}
		printer(str, 1);
		str++;
	}
	return (close_printer());
}

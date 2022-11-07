/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:39:20 by htsang            #+#    #+#             */
/*   Updated: 2022/11/07 17:04:23 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char	*run_parser_logic(const char *str, va_list *subs)
{
	const char	*original_str;
	t_parser	states;

	original_str = str;
	init_parser(&states);
	run_parser(&str, &states, &parse_flags);
	run_parser(&str, &states, &parse_width);
	if (*str++ == '.')
	{
		states.precision = 0;
		run_parser(&str, &states, &parse_precision);
	}
	if (ft_strchr("cs%", *str))
	{
		calc_states_str(*str, &states, subs);
		print_sequence_str(*str, &states, subs);
		return (++str);
	}
	else if (ft_strchr("diuxXp", *str))
	{
		calc_states_num(*str, &states, subs);
		print_sequence_num(*str, &states, subs);
		return (++str);
	}
	return (original_str);
}

int	main_logic(const char *str, va_list *subs)
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

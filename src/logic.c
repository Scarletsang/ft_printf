/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:39:20 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:04:39 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printf_control_print(char **str, struct s_printf_parser *states, \
va_list *subs, char *reset_str)
{
	struct s_printf_sequencer	seq;

	printf_sequencer_init(&seq);
	if (ft_strchr("cs%", **str))
	{
		printf_calc_states_str(**str, states, subs);
		if (printf_sequence(&seq, printf_sequence_str(**str, states, subs)))
			return (-1);
	}
	else if (ft_strchr("diuxXp", **str))
	{
		printf_calc_states_num(**str, states, subs);
		if (printf_sequence(&seq, printf_sequence_num(**str, states, subs)))
			return (-1);
	}
	else
	{
		*str = reset_str;
		return (0);
	}
	(*str)++;
	return (seq.sum);
}

static int	printf_control_parse(char **str, struct s_printf_parser *states, \
va_list *subs)
{
	char						*reset_str;
	struct s_printf_sequencer	seq;

	reset_str = *str;
	printf_sequencer_init(&seq);
	printf_parser_run(str, states, &printf_parse_flags);
	printf_parser_run(str, states, &printf_parse_width);
	if (**str == '.')
	{
		states->precision = 0;
		(*str)++;
		printf_parser_run(str, states, &printf_parse_precision);
	}
	if (printf_sequence(&seq, printf_control_print(str, states, subs, \
		reset_str)))
		return (-1);
	return (seq.sum);
}

int	printf_control(const char *str, va_list *subs)
{
	struct s_printf_parser		states;
	struct s_printf_sequencer	seq;
	unsigned int				text_count;

	printf_sequencer_init(&seq);
	text_count = 0;
	while (str[text_count])
	{
		if (str[text_count] == '%')
		{
			if (printf_sequence(&seq, write(STDOUT_FILENO, str, text_count)))
				return (-1);
			str += text_count + 1;
			text_count = 0;
			printf_parser_init(&states);
			if (printf_sequence(&seq, printf_control_parse((char **) &str, \
				&states, subs)))
				return (-1);
			continue ;
		}
		text_count++;
	}
	if (printf_sequence(&seq, write(STDOUT_FILENO, str, text_count)))
		return (-1);
	return (seq.sum);
}

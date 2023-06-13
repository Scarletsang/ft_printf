/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:26:22 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 04:19:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_H
# define PRINTERS_H

# include <stdlib.h>
# include <unistd.h>

////////////////////////
//////    Core    //////
////////////////////////

struct s_printf_sequencer
{
	int	sum;
};

void	printf_sequencer_init(struct s_printf_sequencer *seq);

int		printf_sequence(struct s_printf_sequencer *seq, int ret);

//////////////////////////
//////    Prefix    //////
//////////////////////////

int		printf_zeros(unsigned int len);

int		printf_spaces(unsigned int len);

int		printf_plus(void);

int		printf_minus(void);

int		printf_0x(char is_upper);

//////////////////////////
//////    Format    //////
//////////////////////////

int		printf_c(char c);

int		printf_s(char *str, unsigned int len);

int		printf_null(unsigned int len);

int		printf_di(int n);

int		printf_u(unsigned int n);

int		printf_x(unsigned int n);

int		printf_x_upper(unsigned int n);

int		printf_p(size_t p);

//////////////////////////
//////   Private	//////
//////////////////////////

int		printf_hex(size_t n, char alphabet_case);

#endif
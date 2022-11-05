/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:26:22 by htsang            #+#    #+#             */
/*   Updated: 2022/11/05 20:02:34 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_H
# define PRINTERS_H

# include <stdarg.h>
# include "../libft/libft.h"

////////////////////////
//////    Core    //////
////////////////////////

int		*printer(char *str, size_t len);

int		close_printer(void);

//////////////////////////
//////    Prefix    //////
//////////////////////////

void	print_zeros(size_t len);

void	print_spaces(size_t len);

void	print_plus(void);

void	print_minus(void);

void	print_0x(void);

//////////////////////////
//////    Format    //////
//////////////////////////

void	print_c(char c);

void	print_s(char *str, size_t len);

void	print_di(int n);

void	print_u(unsigned int n);

#endif
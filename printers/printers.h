/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:26:22 by htsang            #+#    #+#             */
/*   Updated: 2022/11/06 13:24:50 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_H
# define PRINTERS_H

////////////////////////
//////    Core    //////
////////////////////////

int		*printer(char *str, unsigned int len);

int		close_printer(void);

//////////////////////////
//////    Prefix    //////
//////////////////////////

void	print_zeros(unsigned int len);

void	print_spaces(unsigned int len);

void	print_plus(void);

void	print_minus(void);

void	print_0x(void);

//////////////////////////
//////    Format    //////
//////////////////////////

void	print_c(char c);

void	print_s(char *str, unsigned int len);

void	print_di(int n);

void	print_u(unsigned int n);

void	print_xp(unsigned int n);

void	print_X(unsigned int n);

#endif
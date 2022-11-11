/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_big_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:06:17 by htsang            #+#    #+#             */
/*   Updated: 2022/11/11 16:20:35 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_big_num(void)
{
	printf("%#5.x, %#5.x, %#5.x\n\n", 0, 5, -1);
	ft_printf("%#5.x, %#5.x, %#5.x\n\n", 0, 5, -1);

	printf("%0#33.32x\n", 4537415152);
	ft_printf("%0#33.32x\n", 4537415152);
	
	printf("%#5.x\n\n", 0x1234);
	ft_printf("%#5.x\n\n", 0x1234);
	printf("%#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x\n\n", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
	ft_printf("%#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x\n\n", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
	printf("%#5.X, %#5.X, %#5.X, %#5.X, %#5.X, %#5.X, %#5.X, %#5.X, %#5.X, %#5.X\n\n", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
	ft_printf("%#5.X, %#5.X, %#5.X, %#5.X, %#5.X, %#5.X, %#5.X, %#5.X, %#5.X, %#5.X\n\n", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);

	printf("%#5x\n", 0);
	ft_printf("%#5x\n", 0);
	printf(" [%-9p] [%-10p] \n", LONG_MIN, LONG_MAX);
	ft_printf(" [%-9p] [%-10p] \n", LONG_MIN, LONG_MAX);
	printf("[%1.c]\n", 'a');
	ft_printf("[%1.c]\n", 'a');
	printf("[%-2.9c]\n", 'a');
	ft_printf("[%-2.9c]\n", 'a');
	printf(" %-12d \n", LONG_MIN);
	ft_printf(" %-12d \n", LONG_MIN);
	printf(" [%-12d] %-13d [%-14d] %-15d\n", LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" [%-12d] %-13d [%-14d] %-15d\n", LONG_MIN, ULONG_MAX, 0, -42);
	printf(" %-13i \n", UINT_MAX);
	ft_printf(" %-13i \n", UINT_MAX);
	printf(" %-1u \n", 0);
	ft_printf(" %-1u \n", 0);
	printf(" %-13u \n", UINT_MAX);
	ft_printf(" %-13u \n", UINT_MAX);
	printf(" %-1x \n", 0);
	ft_printf(" %-1x \n", 0);
	printf(" %-13x \n", UINT_MAX);
	ft_printf(" %-13x \n", UINT_MAX);
	printf(" %-1X \n", 0);
	ft_printf(" %-1X \n", 0);
	printf(" %-13X \n", UINT_MAX);
	ft_printf(" %-13X \n", UINT_MAX);

	printf(" %012d \n", LONG_MIN);
	ft_printf(" %012d \n", LONG_MIN);
	printf(" %09d %010d %011d %012d %013d %014d %015d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %09d %010d %011d %012d %013d %014d %015d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf(" %013i \n", UINT_MAX);
	ft_printf(" %013i \n", UINT_MAX);
	printf(" %01u \n", 0);
	ft_printf(" %01u \n", 0);
	printf(" %013u \n", UINT_MAX);
	ft_printf(" %013u \n", UINT_MAX);
	printf(" %01x \n", 0);
	ft_printf(" %01x \n", 0);
	printf(" %013x \n", UINT_MAX);
	ft_printf(" %013x \n", UINT_MAX);
	printf(" %01X \n", 0);
	ft_printf(" %01X \n", 0);
	printf(" %013X \n", UINT_MAX);
	ft_printf(" %013X \n", UINT_MAX);

	printf(" %.8d %.9d %.10d %.11d %.12d %.13d %.14d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %.8d %.9d %.10d %.11d %.12d %.13d %.14d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf(" %.8i %.9i %.10i %.11i %.12i %.13i %.14i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %.8i %.9i %.10i %.11i %.12i %.13i %.14i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf(" %.8u %.9u %.10u %.11u %.12u %.13u %.14u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %.8u %.9u %.10u %.11u %.12u %.13u %.14u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf(" %.8x %.9x %.10x %.11x %.12x %.13x %.14x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %.8x %.9x %.10x %.11x %.12x %.13x %.14x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf(" %.8X %.9X %.10X %.11X %.12X %.13X %.14X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %.8X %.9X %.10X %.11X %.12X %.13X %.14X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	printf(" %#x \n", 0);
	ft_printf(" %#x \n", 0);
	printf(" %#x \n", LONG_MIN);
	ft_printf(" %#x \n", LONG_MIN);
	printf(" %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf(" %#X \n", 0);
	ft_printf(" %#X \n", 0);
	printf(" %#X \n", LONG_MIN);
	ft_printf(" %#X \n", LONG_MIN);
	printf(" %#X %#X %#X %#X %#X %#X %#X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %#X %#X %#X %#X %#X %#X %#X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_formats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:22:54 by htsang            #+#    #+#             */
/*   Updated: 2022/11/08 22:47:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_unsigned_int(void)
{
	printf("u - unsigned int test \n");
	ft_printf("u - unsigned int test \n");
	printf("f %u\n", 4294967295u);
	ft_printf("f %u\n", 4294967295u);
	printf("%u\n", 42);
	ft_printf("%u\n", 42);
	printf("Kashim a %u histoires à raconter\n", 1001);
	ft_printf("Kashim a %u histoires à raconter\n", 1001);
	printf("Il fait au moins %u\n", -8000);
	ft_printf("Il fait au moins %u\n", -8000);
	printf("%u\n", -0);
	ft_printf("%u\n", -0);
	printf("%u\n", 0);
	ft_printf("%u\n", 0);
	printf("%u\n", INT_MAX);
	ft_printf("%u\n", INT_MAX);
	printf("%u\n", INT_MIN);
	ft_printf("%u\n", INT_MIN);
	printf("%u\n", INT_MIN - 1);
	ft_printf("%u\n", INT_MIN - 1);
	printf("%u\n", INT_MAX + 1);
	ft_printf("%u\n", INT_MAX + 1);
	printf("%%u 0000042 == |%u|\n", 0000042);
	ft_printf("%%u 0000042 == |%u|\n", 0000042);
	printf("%%u \t == |%u|\n", '\t');
	ft_printf("%%u \t == |%u|\n", '\t');
	printf("%%u Lydie == |%u|\n\n", 'L'+'y'+'d'+'i'+'e');
	ft_printf("%%u Lydie == |%u|\n\n", 'L'+'y'+'d'+'i'+'e');
}

void	test_unsigned_hex(void)
{
	printf("X - unsigned hexadecimal test \n");
	ft_printf("X - unsigned hexadecimal test \n");
	printf("f %%X = [%X]\n", 4294967295u);
	ft_printf("f %%X = [%X]\n", 4294967295u);
	printf("f %%-X = [%-X]\n", 42);
	ft_printf("f %%-X = [%-X]\n", 42);
	printf("f Kashim a [%X] histoires à raconter\n", 1001);
	ft_printf("f Kashim a [%X] histoires à raconter\n", 1001);
	printf("f Il fait au moins [%X]\n", -8000);
	ft_printf("f Il fait au moins [%X]\n", -8000);
	printf("f %%08X = [%08X]\n", -0);
	ft_printf("f %%08X = [%08X]\n", -0);
	printf("f %%.8X = [%.8X]\n", 0);
	ft_printf("f %%.8X = [%.8X]\n", 0);
	printf("f %%#X = [%#X]\n", INT_MAX);
	ft_printf("f %%#X = [%#X]\n", INT_MAX);
	printf("f %%8.0X = [%8.0X]\n", INT_MIN);
	ft_printf("f %%8.0X = [%8.0X]\n", INT_MIN);
	printf("f %%0.8X = [%0.8X]\n", INT_MIN - 1);
	ft_printf("f %%0.8X = [%0.8X]\n", INT_MIN - 1);
	printf("f %%8X = [%8X]\n", INT_MAX + 1);
	ft_printf("f %%8X = [%8X]\n", INT_MAX + 1);
	printf("f %%8X 0000042 == |%8X|\n", 0000042);
	ft_printf("f %%8X 0000042 == |%8X|\n", 0000042);
	printf("f %%-8X \t == |%-8X|\n", '\t');
	ft_printf("f %%-8X \t == |%-8X|\n", '\t');
	printf("f %%-8.0X Lydie == |%-8.0X|\n\n", 'L'+'y'+'d'+'i'+'e');
	ft_printf("f %%-8.0X Lydie == |%-8.0X|\n\n", 'L'+'y'+'d'+'i'+'e');

	printf("x - unsigned hexadecimal test \n");
	ft_printf("x - unsigned hexadecimal test \n");
	printf("f %%x = [%x]\n", 4294967295u);
	ft_printf("f %%x = [%x]\n", 4294967295u);
	printf("f %%-x = [%-x]\n", 42);
	ft_printf("f %%-x = [%-x]\n", 42);
	printf("f Kashim a [%x] histoires à raconter\n", 1001);
	ft_printf("f Kashim a [%x] histoires à raconter\n", 1001);
	printf("f Il fait au moins [%x]\n", -8000);
	ft_printf("f Il fait au moins [%x]\n", -8000);
	printf("f %%08x = [%08x]\n", -0);
	ft_printf("f %%08x = [%08x]\n", -0);
	printf("f %%.8x = [%.8x]\n", 0);
	ft_printf("f %%.8x = [%.8x]\n", 0);
	printf("f %%#x = [%#x]\n", INT_MAX);
	ft_printf("f %%#x = [%#x]\n", INT_MAX);
	printf("f %%8.0x = [%8.0x]\n", INT_MIN);
	ft_printf("f %%8.0x = [%8.0x]\n", INT_MIN);
	printf("f %%0.8x = [%0.8x]\n", INT_MIN - 1);
	ft_printf("f %%0.8x = [%0.8x]\n", INT_MIN - 1);
	printf("f %%8x = [%8x]\n", INT_MAX + 1);
	ft_printf("f %%8x = [%8x]\n", INT_MAX + 1);
	printf("f %%8x 0000042 == |%8x|\n", 0000042);
	ft_printf("f %%8x 0000042 == |%8x|\n", 0000042);
	printf("f %%-8x \t == |%-8x|\n", '\t');
	ft_printf("f %%-8x \t == |%-8x|\n", '\t');
	printf("f %%-8.0x Lydie == |%-8.0x|\n\n", 'L'+'y'+'d'+'i'+'e');
	ft_printf("f %%-8.0x Lydie == |%-8.0x|\n\n", 'L'+'y'+'d'+'i'+'e');
}

void	test_char(void)
{
	printf("c - char test \n");
	ft_printf("c - char test \n");
	printf("[%c]\n", 42);
	ft_printf("[%c]\n", 42);
	printf("[Kashim a [%c] histoires à raconter\n", 1001);
	ft_printf("[Kashim a [%c] histoires à raconter\n", 1001);
	printf("[Il fait au moins [%c]\n", -8000);
	ft_printf("[Il fait au moins [%c]\n", -8000);
	printf("[%c]\n", -0);
	ft_printf("[%c]\n", -0);
	printf("[%c]\n", 0);
	ft_printf("[%c]\n", 0);
	printf("[%c]\n", INT_MAX);
	ft_printf("[%c]\n", INT_MAX);
	printf("[%4c]\n", 'c');
	ft_printf("[%4c]\n", 'c');
	printf("[%-2c]\n", '\n');
	ft_printf("[%-2c]\n", '\n');
	printf("[%04c]\n", 'l');
	ft_printf("[%04c]\n", 'l');
	printf("[% c]\n", 'y');
	ft_printf("[% c]\n", 'y');
	printf("[%c]\n", ' ');
	ft_printf("[%c]\n", ' ');
	printf("[%#c]\n", 'e');
	ft_printf("[%#c]\n", 'e');
	printf("[%+c]\n", 's');
	ft_printf("[%+c]\n", 's');
	printf("[%.2c]\n", 't');
	ft_printf("[%.2c]\n", 't');
	printf("[%c]\n", ' ');
	ft_printf("[%c]\n", ' ');
	printf("[%c]\n", 'f');
	ft_printf("[%c]\n", 'f');
	printf("[%c]\n", '\r');
	ft_printf("[%c]\n", '\r');
	printf("[%c]\n\n", '\t');
	ft_printf("[%c]\n\n", '\t');
}

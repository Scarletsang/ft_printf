/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_width_and_precision.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:22:54 by htsang            #+#    #+#             */
/*   Updated: 2022/11/08 21:44:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_precision(void)
{
	printf("id precision test \n");
	ft_printf("id precision test \n");
	printf("f %%.i = 2, [%.i]\n", 2);
	ft_printf("f %%.i = 2, [%.i]\n", 2);
	printf("f %%.d = -3, [%.d]\n", -3);
	ft_printf("f %%.d = -3, [%.d]\n", -3);
	printf("f %%.5i = 2, [%.5i]\n", 2);
	ft_printf("f %%.5i = 2, [%.5i]\n", 2);
	printf("f %%.6d = -3, [%.6d]\n", -3);
	ft_printf("f %%.6d = -3, [%.6d]\n", -3);
	printf("f %%.3i = 0, [%.3i]\n", 0);
	ft_printf("f %%.3i = 0, [%.3i]\n", 0);
	printf("f %%.5d = 5263,  [%.5d]\n", 5263);
	ft_printf("f %%.5d = 5263,  [%.5d]\n", 5263);
	printf("f %%.5d = -2372, [%.5d]\n", -2372);
	ft_printf("f %%.5d = -2372, [%.5d]\n", -2372);
	printf("f %%.7i = 13862,  [%.7i]\n", 13862);
	ft_printf("f %%.7i = 13862,  [%.7i]\n", 13862);
	printf("f %%.7i = -23646, [%.7i]\n\n",-23646);
	ft_printf("f %%.7i = -23646, [%.7i]\n\n",-23646);

	system("leaks test > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
}

void	test_width(void)
{
	printf("%% test\n");
	ft_printf("%% test\n");
	printf("f %%%%, [%%]\n");
	ft_printf("f %%%%, [%%]\n");
	printf("f %%5%%, [%5%]\n");
	ft_printf("f %%5%%, [%5%]\n");
	printf("f %%-5%%, [%-5%]\n");
	ft_printf("f %%-5%%, [%-5%]\n");
	printf("f %%05%%, [%05%]\n");
	ft_printf("f %%05%%, [%05%]\n");
	printf("f %%-05%%, [%-05%]\n\n");
	ft_printf("f %%-05%%, [%-05%]\n\n");

	printf("id basic test n width test \n");
	ft_printf("id basic test n width test \n");
	printf("f %%i = 2147483647, [%i]\n", 2147483647);
	ft_printf("f %%i = 2147483647, [%i]\n", 2147483647);
	printf("f %%d = -2147483648, [%d]\n", (int)(-2147483678));
	ft_printf("f %%d = -2147483648, [%d]\n", (int)(-2147483678));
	printf("f %%d = 0, [%d]\n", 0);
	ft_printf("f %%d = 0, [%d]\n", 0);
	printf("f %%7i = 33,  [%7i]\n", 33);
	ft_printf("f %%7i = 33,  [%7i]\n", 33);
	printf("f %%7d = -14, [%7d]\n", -14);
	ft_printf("f %%7d = -14, [%7d]\n", -14);
	printf("f %%3i = 0, [%3i]\n", 0);
	ft_printf("f %%3i = 0, [%3i]\n", 0);
	printf("f %%5d = 52625, [%5d]\n", 52625);
	ft_printf("f %%5d = 52625, [%5d]\n", 52625);
	printf("f %%5i = -2562, [%5i]\n", -2562);
	ft_printf("f %%5i = -2562, [%5i]\n", -2562);
	printf("f %%4d = 94827, [%4d]\n", 94827);
	ft_printf("f %%4d = 94827, [%4d]\n", 94827);
	printf("f %%4i = -2464, [%4i]\n", -2464);
	ft_printf("f %%4i = -2464, [%4i]\n", -2464);
	printf("f %%-7d = 33,  [%-7d]\n", 33);
	ft_printf("f %%-7d = 33,  [%-7d]\n", 33);
	printf("f %%-7i = -14, [%-7i]\n", -14);
	ft_printf("f %%-7i = -14, [%-7i]\n", -14);
	printf("f %%-5i = 52625, [%-5i]\n", 52625);
	ft_printf("f %%-5i = 52625, [%-5i]\n", 52625);
	printf("f %%-5d = -2562, [%-5d]\n", -2562);
	ft_printf("f %%-5d = -2562, [%-5d]\n", -2562);
	printf("f %%-4d = 94827, [%-4d]\n", 94827);
	ft_printf("f %%-4d = 94827, [%-4d]\n", 94827);
	printf("f %%-4i = -2464, [%-4i]\n\n", -2464);
	ft_printf("f %%-4i = -2464, [%-4i]\n\n", -2464);

	printf("id zero field width padding test \n");
	ft_printf("id zero field width padding test \n");
	printf("f %%05i = 43, [%05i]\n", 43);
	ft_printf("f %%05i = 43, [%05i]\n", 43);
	printf("f %%07d = -54, [%07d]\n", -54);
	ft_printf("f %%07d = -54, [%07d]\n", -54);
	printf("f %%03i = 0, [%03i]\n", 0);
	ft_printf("f %%03i = 0, [%03i]\n", 0);
	printf("f %%04d = 634, [%04d]\n", 634);
	ft_printf("f %%04d = 634, [%04d]\n", 634);
	printf("f %%04i = -532, [%04i]\n", -532);
	ft_printf("f %%04i = -532, [%04i]\n", -532);
	printf("f %%04d = -4825, [%04d]\n\n", -4825);
	ft_printf("f %%04d = -4825, [%04d]\n\n", -4825);

	system("leaks test > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
}

void	test_width_and_precision(void)
{
	printf("id width and precision test \n");
	ft_printf("id width and precision test \n");
	printf("f %%8.5i = 34, [%8.5i]\n", 34);
	ft_printf("f %%8.5i = 34, [%8.5i]\n", 34);
	printf("f %%8.5i = 0, [%8.5i]\n", 0);
	ft_printf("f %%8.5i = 0, [%8.5i]\n", 0);
	printf("f %%8.3d = 8375,  [%8.3d]\n", 8375);
	ft_printf("f %%8.3d = 8375,  [%8.3d]\n", 8375);
	printf("f %%8.3i = -8473, [%8.3i]\n", -8473);
	ft_printf("f %%8.3i = -8473, [%8.3i]\n", -8473);
	printf("f %%3.7d = 3267,  [%3.7d]\n", 3267);
	ft_printf("f %%3.7d = 3267,  [%3.7d]\n", 3267);
	printf("f %%3.7i = -2375, [%3.7i]\n", -2375);
	ft_printf("f %%3.7i = -2375, [%3.7i]\n", -2375);
	printf("f %%3.3d = 6983,  [%3.3d]\n", 6983);
	ft_printf("f %%3.3d = 6983,  [%3.3d]\n", 6983);
	printf("f %%3.3i = -8462, [%3.3i]\n", -8462);
	ft_printf("f %%3.3i = -8462, [%3.3i]\n", -8462);
	printf("f %%-8.5i = 34, [%-8.5i]\n", 34);
	ft_printf("f %%-8.5i = 34, [%-8.5i]\n", 34);
	printf("f %%-8.5i = 0, [%-8.5i]\n", 0);
	ft_printf("f %%-8.5i = 0, [%-8.5i]\n", 0);
	printf("f %%-3.8d = 8375,  [%-3.8d]\n", 8375);
	ft_printf("f %%-3.8d = 8375,  [%-3.8d]\n", 8375);
	printf("f %%-3.8i = -8473, [%-3.8i]\n", -8473);
	ft_printf("f %%-3.8i = -8473, [%-3.8i]\n", -8473);
	printf("f %%-3.7d = 3267,  [%-3.7d]\n", 3267);
	ft_printf("f %%-3.7d = 3267,  [%-3.7d]\n", 3267);
	printf("f %%-3.7i = -2375, [%-3.7i]\n", -2375);
	ft_printf("f %%-3.7i = -2375, [%-3.7i]\n", -2375);
	printf("f %%-3.3d = 6983,  [%-3.3d]\n", 6983);
	ft_printf("f %%-3.3d = 6983,  [%-3.3d]\n", 6983);
	printf("f %%-3.3i = -8462, [%-3.3i]\n\n", -8462);
	ft_printf("f %%-3.3i = -8462, [%-3.3i]\n\n", -8462);

	printf("id width and precision with zeropadding test \n");
	ft_printf("id width and precision with zeropadding test \n");
	printf("f %%08.5i = 34, [%08.5i]\n", 34);
	ft_printf("f %%08.5i = 34, [%08.5i]\n", 34);
	printf("f %%010.5d = -216, [%010.5d]\n", -216);
	ft_printf("f %%010.5d = -216, [%010.5d]\n", -216);
	printf("f %%08.5i = 0, [%08.5i]\n", 0);
	ft_printf("f %%08.5i = 0, [%08.5i]\n", 0);
	printf("f %%08.3d = 8375,  [%08.3d]\n", 8375);
	ft_printf("f %%08.3d = 8375,  [%08.3d]\n", 8375);
	printf("f %%08.3i = -8473, [%08.3i]\n", -8473);
	ft_printf("f %%08.3i = -8473, [%08.3i]\n", -8473);
	printf("f %%03.7d = 3267,  [%03.7d]\n", 3267);
	ft_printf("f %%03.7d = 3267,  [%03.7d]\n", 3267);
	printf("f %%03.7i = -2375, [%03.7i]\n", -2375);
	ft_printf("f %%03.7i = -2375, [%03.7i]\n", -2375);
	printf("f %%03.3d = 6983,  [%03.3d]\n", 6983);
	ft_printf("f %%03.3d = 6983,  [%03.3d]\n", 6983);
	printf("f %%03.3i = -8462, [%03.3i]\n\n", -8462);
	ft_printf("f %%03.3i = -8462, [%03.3i]\n\n", -8462);

	printf("id width and precision, left-justified with zeropadding test \n");
	printf("id wft_idth and precision, left-justified with zeropadding test \n");
	printf("f %%0-8.5i = 34, [%0-8.5i]\n", 34);
	ft_printf("f %%0-8.5i = 34, [%0-8.5i]\n", 34);
	printf("f %%0-10.5d = -216, [%0-10.5d]\n", -216);
	ft_printf("f %%0-10.5d = -216, [%0-10.5d]\n", -216);
	printf("f %%0-8.5i = 0, [%0-8.5i]\n", 0);
	ft_printf("f %%0-8.5i = 0, [%0-8.5i]\n", 0);
	printf("f %%0-8.3d = 8375,  [%0-8.3d]\n", 8375);
	ft_printf("f %%0-8.3d = 8375,  [%0-8.3d]\n", 8375);
	printf("f %%0-8.3i = -8473, [%0-8.3i]\n", -8473);
	ft_printf("f %%0-8.3i = -8473, [%0-8.3i]\n", -8473);
	printf("f %%0-3.7d = 3267,  [%0-3.7d]\n", 3267);
	ft_printf("f %%0-3.7d = 3267,  [%0-3.7d]\n", 3267);
	printf("f %%0-3.7i = -2375, [%0-3.7i]\n", -2375);
	ft_printf("f %%0-3.7i = -2375, [%0-3.7i]\n", -2375);
	printf("f %%0-3.3d = 6983,  [%0-3.3d]\n", 6983);
	ft_printf("f %%0-3.3d = 6983,  [%0-3.3d]\n", 6983);
	printf("f %%0-3.3i = -8462, [%0-3.3i]\n\n", -8462);
	ft_printf("f %%0-3.3i = -8462, [%0-3.3i]\n\n", -8462);

	system("leaks test > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
} 

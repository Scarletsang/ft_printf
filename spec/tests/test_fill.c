/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:39:04 by htsang            #+#    #+#             */
/*   Updated: 2022/11/08 21:40:09 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_zero(void)
{
	printf("id zero test \n");
	ft_printf("id zero test \n");
	printf("f %%i = 0,   [%i]\n", 0);
	ft_printf("f %%i = 0,   [%i]\n", 0);
	printf("f %%5i = 0,   [%5i]\n", 0);
	ft_printf("f %%5i = 0,   [%5i]\n", 0);
	printf("f %%.0i = 0,   [%.0i]\n", 0);
	ft_printf("f %%.0i = 0,   [%.0i]\n", 0);
	printf("f %%.i = 0,    [%.i]\n", 0);
	ft_printf("f %%.i = 0,    [%.i]\n", 0);
	printf("f %%5.0i = 0,  [%5.0i]\n", 0);
	ft_printf("f %%5.0i = 0,  [%5.0i]\n", 0);
	printf("f %%5.i = 0,   [%5.i]\n", 0);
	ft_printf("f %%5.i = 0,   [%5.i]\n", 0);
	printf("f %%-5.0i = 0, [%-5.0i]\n", 0);
	ft_printf("f %%-5.0i = 0, [%-5.0i]\n", 0);
	printf("f %%-5.i = 0,  [%-5.i]\n\n", 0);
	ft_printf("f %%-5.i = 0,  [%-5.i]\n\n", 0);

	system("leaks test > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
}

void	test_space(void)
{
	printf("id space test \n");
	ft_printf("id space test \n");
	printf("f %% i = 34, [% i]\n", 34);
	ft_printf("f %% i = 34, [% i]\n", 34);
	printf("f %% d = -216, [% d]\n", -216);
	ft_printf("f %% d = -216, [% d]\n", -216);
	printf("f %% 3.3d = 8375,  [% 3.3d]\n", 8375);
	ft_printf("f %% 3.3d = 8375,  [% 3.3d]\n", 8375);
	printf("f %% 3.3i = -8473, [% 3.3i]\n", -8473);
	ft_printf("f %% 3.3i = -8473, [% 3.3i]\n", -8473);
	printf("f %% 8.3d = 8375,  [% 8.3d]\n", 8375);
	ft_printf("f %% 8.3d = 8375,  [% 8.3d]\n", 8375);
	printf("f %% 8.3i = -8473, [% 8.3i]\n", -8473);
	ft_printf("f %% 8.3i = -8473, [% 8.3i]\n", -8473);
	printf("f %% 3.7d = 3267,  [% 3.7d]\n", 3267);
	ft_printf("f %% 3.7d = 3267,  [% 3.7d]\n", 3267);
	printf("f %% 3.7i = -2375, [% 3.7i]\n\n", -2375);
	ft_printf("f %% 3.7i = -2375, [% 3.7i]\n\n", -2375);

	system("leaks test > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
}

void	test_plus(void)
{
	printf("id plus sign test \n");
	ft_printf("id plus sign test \n");
	printf("f %%+i = 34, [%+i]\n", 34);
	ft_printf("f %%+i = 34, [%+i]\n", 34);
	printf("f %%+d = -216, [%+d]\n", -216);
	ft_printf("f %%+d = -216, [%+d]\n", -216);
	printf("f %%+3.3d = 8375,  [%+3.3d]\n", 8375);
	ft_printf("f %%+3.3d = 8375,  [%+3.3d]\n", 8375);
	printf("f %%+3.3i = -8473, [%+3.3i]\n", -8473);
	ft_printf("f %%+3.3i = -8473, [%+3.3i]\n", -8473);
	printf("f %%+8.3d = 8375,  [%+8.3d]\n", 8375);
	ft_printf("f %%+8.3d = 8375,  [%+8.3d]\n", 8375);
	printf("f %%+8.3i = -8473, [%+8.3i]\n", -8473);
	ft_printf("f %%+8.3i = -8473, [%+8.3i]\n", -8473);
	printf("f %%+3.7d = 3267,  [%+3.7d]\n", 3267);
	ft_printf("f %%+3.7d = 3267,  [%+3.7d]\n", 3267);
	printf("f %%+3.7i = -2375, [%+3.7i]\n\n", -2375);
	ft_printf("f %%+3.7i = -2375, [%+3.7i]\n\n", -2375);

	system("leaks test > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
}

void	test_space_plus(void)
{
	printf("id space with plus sign test \n");
	ft_printf("id space with plus sign test \n");
	printf("f %%+ i = 34, [%+ i]\n", 34);
	ft_printf("f %%+ i = 34, [%+ i]\n", 34);
	printf("f %%+ d = -216, [%+ d]\n", -216);
	ft_printf("f %%+ d = -216, [%+ d]\n", -216);
	printf("f %%+ 3.3d = 8375,  [%+ 3.3d]\n", 8375);
	ft_printf("f %%+ 3.3d = 8375,  [%+ 3.3d]\n", 8375);
	printf("f %%+ 3.3i = -8473, [%+ 3.3i]\n", -8473);
	ft_printf("f %%+ 3.3i = -8473, [%+ 3.3i]\n", -8473);
	printf("f %%+ 8.3d = 8375,  [%+ 8.3d]\n", 8375);
	ft_printf("f %%+ 8.3d = 8375,  [%+ 8.3d]\n", 8375);
	printf("f %%+ 8.3i = -8473, [%+ 8.3i]\n", -8473);
	ft_printf("f %%+ 8.3i = -8473, [%+ 8.3i]\n", -8473);
	printf("f %%+ 3.7d = 3267,  [%+ 3.7d]\n", 3267);
	ft_printf("f %%+ 3.7d = 3267,  [%+ 3.7d]\n", 3267);
	printf("f %%+ 3.7i = -2375, [%+ 3.7i]\n\n", -2375);
	ft_printf("f %%+ 3.7i = -2375, [%+ 3.7i]\n\n", -2375);

	system("leaks test > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
}

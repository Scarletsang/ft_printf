/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:02:21 by htsang            #+#    #+#             */
/*   Updated: 2022/11/08 21:49:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_pointer(void)
{
	printf("p - pointer test \n");
	ft_printf("p - pointer test \n");
	printf("%%p [%p]\n", NULL);
	ft_printf("%%p [%p]\n", NULL);
	printf("%%5p: [%5p]\n", NULL);
	ft_printf("%%5p: [%5p]\n", NULL);
	printf("%%2p [%2p]\n", NULL);
	ft_printf("%%2p [%2p]\n", NULL);
	printf("%.p\n", NULL);
	ft_printf("%.p\n", NULL);
	printf("%5.p\n", NULL);
	ft_printf("%5.p\n", NULL);
	printf("%2.p\n", NULL);;
	ft_printf("%2.p\n", NULL);;
	printf("%9.2p\n", 1234);
	ft_printf("%9.2p\n", 1234);
	printf("%2.9p\n", 1234);
	ft_printf("%2.9p\n", 1234);
	printf("%.5p\n", 0);
	ft_printf("%.5p\n", 0);
	printf("%.0p\n", 0);
	ft_printf("%.0p\n", 0);
	printf("%5p\n\n", 0);
	ft_printf("%5p\n\n", 0);

	system("leaks test > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
}

void	test_string(void)
{
	printf("s - string test \n");
	ft_printf("s - string test \n");
	printf("hello, %8s.\n", "gavin");
	ft_printf("hello, %8s.\n", "gavin");
	printf("%-8s\n", "testing testing");
	ft_printf("%-8s\n", "testing testing");
	printf("%08s%8.3s\n", "hello", "world");
	ft_printf("%08s%8.3s\n", "hello", "world");
	printf("..%#8s stuff % 8s\n", "a", "b");
	ft_printf("..%#8s stuff % 8s\n", "a", "b");
	printf("this %s is empty\n", "");
	ft_printf("this %s is empty\n", "");
	printf("%s !", "Ceci n'est pas un \0 exercice !\n\n");
	ft_printf("%s !", "Ceci n'est pas un \0 exercice !\n\n");
	char *null_str = NULL;
	printf("%s everywhere\n", null_str);
	ft_printf("%s everywhere\n", null_str);

	system("leaks test > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
}

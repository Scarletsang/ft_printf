/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:52:46 by htsang            #+#    #+#             */
/*   Updated: 2022/11/08 22:46:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"

int	main(void)
{
	test_zero();
	test_space();
	test_plus();
	test_space_plus();

	test_precision();
	test_width();
	test_width_and_precision();

	test_unsigned_int();
	test_unsigned_hex();
	test_char();
	test_pointer();
	test_string();

	system("leaks test > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	return (0);
}

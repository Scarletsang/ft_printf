/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:52:46 by htsang            #+#    #+#             */
/*   Updated: 2022/11/11 16:21:00 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"

int	main(int argc, char **argv)
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
	test_big_num();

	return (0);
}

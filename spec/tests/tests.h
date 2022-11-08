#ifndef TESTS_H
# define TESTS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include "../../src/ft_printf.h"

void	test_unsigned_int(void);

void	test_unsigned_hex(void);

void	test_char(void);

void	test_pointer(void);

void	test_string(void);


void	test_precision(void);

void	test_width(void);

void	test_width_and_precision(void);


void	test_zero(void);

void	test_space(void);

void	test_plus(void);

void	test_space_plus(void);

#endif
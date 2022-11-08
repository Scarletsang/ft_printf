NAME=test.out
TESTS= \
	tests/test_fill.c \
	tests/test_formats.c \
	tests/test_pointer.c \
	tests/test_width_and_precision.c
TARGET_DIR=../src
TARGET=${TARGET_DIR}/libftprintf.a
TESTS_OBJS=${TESTS:.c=.o}
CC=cc
CFLAGS= -g

all: ${NAME}

${NAME}: main.c ${TESTS_OBJS}
	${CC} main.c ${TESTS} ${TARGET} -o test.out

clean: 
	rm -f ${TESTS_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

# Debugging use

debug: target ${TESTS_OBJS}
	rm -f debug.out && \
	${CC} -g -Wformat main.c ${TESTS_OBJS} -L${TARGET} -o debug.out

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

debugclean: clean
	make clean -C ${TARGET_DIR}

debugfclean: fclean
	make fclean -C ${TARGET_DIR}
	rm -f debug.out

target:
	make CFLAGS="-g -Wall -Wextra -Werror" re -C ${TARGET_DIR}
# Please only change the following line
TARGET_NAME=libftprintf.a

NAME=debug.out
TARGET_DIR=..
TESTS:= $(shell find tests -name '*.c')
TARGET=${TARGET_DIR}/${TARGET_NAME}
TESTS_OBJS=${TESTS:.c=.o}
CC=cc
CFLAGS= -g

all: ${NAME}

${NAME}: targetall ${TESTS_OBJS}
ifeq ($(findstring .a, ${TARGET}),)
	@${CC} -g -Wformat main.c ${TESTS_OBJS} ${TARGET} -o ${NAME} && \
	echo "Success compiling with the target binary ${TARGET_NAME}!"
else
	@${CC} -g -Wformat main.c ${TESTS_OBJS} -L./${TARGET_DIR} -l$(patsubst lib%.a,%,${TARGET_NAME}) -o ${NAME} && \
	echo "Success compiling with the target library ${TARGET_NAME}!"
endif

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean: targetclean
	@rm -f ${TESTS_OBJS}

fclean: targetfclean clean
	@rm -f ${NAME}

re: fclean all

# Target rules

targetall:
	@make CFLAGS="-g -Wall -Wextra -Werror" re -C ${TARGET_DIR}

targetclean:
	@make clean -C ${TARGET_DIR}

targetfclean:
	@make fclean -C ${TARGET_DIR}
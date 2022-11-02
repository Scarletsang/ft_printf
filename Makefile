NAME=
SRC= 
OBJS=${SRC:.c=.o}
CC=cc
FLAGS= -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

${OBJS}: ${SRC}
	${CC} ${FLAGS} -c ${SRC}

clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

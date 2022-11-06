NAME=libftprintf.a
SRC= \
	libftprintf.c \
	logic.c \
	parsers.c \
	calc_len.c \
	calc_states.c \
	utils.c \
	printers/cs.c \
	printers/diu.c \
	printers/xXp.c \
	printers/prefix.c \
	printers/printer.c \
	libft/ft_strchr.c \
	libft/ft_strlen.c
OBJS=${SRC:.c=.o}
CC=cc
CFLAGS= -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

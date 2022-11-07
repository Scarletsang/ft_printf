NAME=libftprintf.a
LIBFT_SRC= \
	libft/ft_strchr.c \
	libft/ft_strlen.c \
	libft/ft_ptrlen.c \
	libft/ft_numlen.c \
	libft/ft_isdigit.c
PRINTERS_SRC= \
	printers/cs.c \
	printers/diu.c \
	printers/xXp.c \
	printers/prefix.c \
	printers/printer.c
PARSERS_SRC= \
	parsers/parsers.c \
	parsers/calc_len.c \
	parsers/calc_states.c \
	parsers/utils.c
MAIN_SRC= \
	ft_printf.c \
	logic.c \
	sequencers.c \
	utils.c
LIBFT_OBJS=${LIBFT_SRC:.c=.o}
PRINTERS_OBJS=${PRINTERS_SRC:.c=.o}
PARSERS_OBJS=${PARSERS_SRC:.c=.o}
MAIN_OBJS=${MAIN_SRC:.c=.o}
OBJS=${LIBFT_OBJS} ${PRINTERS_OBJS} ${PARSERS_OBJS} ${MAIN_OBJS}
CC=cc
CFLAGS= -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

${MAIN_OBJS}: ${PARSERS_OBJS} ${PRINTERS_OBJS}

${PARSERS_OBJS}: ${LIBFT_OBJS}

clean: 
	rm -f ${LIBFT_OBJS} ${PRINTERS_OBJS} ${PARSERS_OBJS} ${MAIN_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

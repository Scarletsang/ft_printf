################################
######     Variables     #######
################################

NAME:=libftprintf.a

CC:=cc
CFLAGS:= -Wall -Wextra -Werror
ifdef FSANITIZE
	CFLAGS+= -g3 -fsanitize=address
	LDFLAGS+= -g3 -fsanitize=address
endif
INCLUDE_DIR=

###################################
######     Source files     #######
###################################

# To add souce files, create a varaible for each folder, and then
# contatenate them in the SRC variable like this:
LIBFT_SRC= \
	libft/ft_strchr.c \
	libft/ft_strlen.c \
	libft/ft_ptrlen.c \
	libft/ft_numlen.c \
	libft/ft_isdigit.c \
	libft/ft_isupper.c
PRINTERS_SRC= \
	printers/cs.c \
	printers/diu.c \
	printers/xXp.c \
	printers/prefix.c \
	printers/hex_printer.c \
	printers/sequencer.c
PARSERS_SRC= \
	parsers/parsers.c \
	parsers/calc_numlen.c \
	parsers/calc_strlen.c \
	parsers/calc_states.c \
	parsers/peek.c \
	parsers/utils.c
SEQUENCE_SRC= \
	sequence/substitution_printer.c \
	sequence/str_sequence.c \
	sequence/num_sequence.c \
	sequence/num_precision_sequence.c
MAIN_SRC= \
	ft_printf.c \
	logic.c

SRC:= $(LIBFT_SRC) $(PRINTERS_SRC) $(PARSERS_SRC) $(SEQUENCE_SRC) $(MAIN_SRC)

####################################
######     Library files     #######
####################################

# To compile a library, store a variable for their library file like this
# and add a rule for it after the main rules:

# To add a library, add the library header file like this:

# Then add the library to the linking process in one of the following ways:
# LDFLAGS+= -Llib/LIBRARY_NAME -lLIBRARY_NAME
# LDFLAGS+= lib/LIBRARY_NAME/libLIBRARY_NAME.a

###########################################
######     Object name reformat     #######
###########################################

# This in effect makes all the object files to be compiled in the OBJ_DIR directory

SRC_DIR:=src
OBJ_DIR:=obj
OBJ:= $(addprefix $(OBJ_DIR)/,$(subst /,@,$(SRC:.c=.o)))

#################################
######     Main rules     #######
#################################

all:
	@$(MAKE) $(NAME) -j

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ) && echo "Compilation of $(NAME) successful"

bonus: re

##########################################
######     Library compilation     #######
##########################################

# To compile a library, add a rule like this:

# $(LIBRARY_NAME):
# 	@${MAKE} $(if $(FSANITIZE),FSANITIZE=yes,) -C lib/LIBRARY_NAME

#########################################
######     Object compilation     #######
#########################################

.SECONDEXPANSION:
$(OBJ_DIR)/%.o: $(SRC_DIR)/$$(subst @,/,$$*).c
	@$(CC) $(CFLAGS) $(addprefix -iquote ,$(INCLUDE_DIR)) $(addprefix -I ,$(LIB_INCLUDE_DIR)) -c $< -o $@

$(OBJ): $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

###############################
######     Cleaning     #######
###############################

clean: 
	@rm -f $(OBJ_DIR)/*.o

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
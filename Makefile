# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweverli <mweverli@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2022/07/11 17:41:13 by mweverli      #+#    #+#                  #
#    Updated: 2022/07/13 20:18:43 by mweverli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#========================================#
#=========  GENERAL VARIABLES:  =========#
#========================================#

NAME		:=	fdf
EXE			:=	$(NAME).exe
ARCH		:=	$(NAME).a

OBJ_DIR		:=	./OBJ
SRC_DIR		:=	./src
INC_DIR		:=	./include
HEA_DIR		:=	./headers
LIB_DIR		:=	./lib

LIB			:=	$(wildcard $(LIB_DIR)/*)
#LIB_ARC		:=	$(addsuffix .a,$(notdir $(LIB)))
LIB_ARC		:=	./lib/libft/libft.a

SRC			:=	$(wildcard $(SRC_DIR)/*.c)
OBJ			:=	$(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

CC			:=	gcc
CFL			:=	-Wall -Werror -Wextra#-g -fsanitize=address

COMPILE		:=	$(CC) $(CFL)

#========================================#
#============== RECIPIES  ===============#
#========================================#

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(NAME): $(LIB_ARC) $(OBJ)
	ar rcs $(ARCH) $^

test: obj $(OBJ)
	$(COMPILE) -o $(EXE) $(OBJ)

db: FORCE
	$(LIB_ARC)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(COMPILE) -o $@ -c $<

clean:
	@mkdir -p $(OBJ_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(ARCH)

tclean: fclean
	rm -f $(EXE)

re: fclean all

#========================================#
#============== LIBRARIES ===============#
#========================================#

$(LIB_DIR)/%/%.a:
	@make -C $@



#========================================#
#============ MISCELLANEOUS =============#
#========================================#

.PHONY: all clean fclean tclean re

.DEFAULT_GOAL := all

FORCE:

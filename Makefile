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

LIBFT		:=	libft
LIB_LIBFT	:=	$(LIB_DIR)/$(LIBFT)
LIB_LIB_ARC	:=	$(LIB_LIBFT)/libft.a

SRC			:=	$(wildcard $(SRC_DIR)/*.c)
OBJ			:=	$(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

CC			:=	gcc
CFL			:=	-Wall -Werror -Wextra
CFL_DB		:=	-Wall -Werror -Wextra -g -fsanitize=address

ifdef DB
COMPILE_DB	:=	$(CC) $(CFL_DB)
else
COMPILE		:=	$(CC) $(CFL)
endif

#========================================#
#============== RECIPIES  ===============#
#========================================#

all: $(NAME) | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(LIB_LIB_ARC) $(LIB_MLX_ARC) $(OBJ)
	ar rcs $(ARCH) $^

test: obj $(OBJ)
	$(COMPILE) -o $(EXE) $(OBJ)

test_db: clean
	@ $(MAKE) test DB=1

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(COMPILE) -o $@ -c $<

clean: | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	rm -rf $(OBJ_DIR)
	@make -C $(LIB_MLX) clean 
	@make -C $(LIB_LIBFT) clean

fclean: clean
	rm -f $(ARCH)
	@make -C $(LIB_MLX) fclean
	@make -C $(LIB_LIBFT) fclean

tclean: fclean
	rm -f $(EXE)

re: fclean all

#========================================#
#============== LIBRARIES ===============#
#========================================#

$(LIB_MLX_ARC):
	@make -C $(LIB_MLX) 

$(LIB_LIB_ARC):
	@make -C $(LIB_LIBFT)


#========================================#
#============ MISCELLANEOUS =============#
#========================================#

.PHONY: all clean fclean tclean re

.DEFAULT_GOAL := all

FORCE:

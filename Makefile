# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweverli <mweverli@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2022/07/11 17:41:13 by mweverli      #+#    #+#                  #
#    Updated: 2022/09/28 14:48:38 by mweverli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#========================================#
#=========  GENERAL VARIABLES:  =========#
#========================================#

NAME		:=	fdf

OBJ_DIR		:=	./OBJ
SRC_DIR		:=	./src
INC_DIR		:=	./include
LIB_DIR		:=	./lib

SRC			:=	$(shell ls src/)
OBJ			:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

#============== LIBRARIES ===============#

MLX			:=	mlx
LIB_MLX		:=	$(LIB_DIR)/$(MLX)
LIB_MLX_ARC	:=	$(LIB_MLX)/libmlx42.a

LIBFT		:=	libft
LIB_LIBFT	:=	$(LIB_DIR)/$(LIBFT)
LIB_LIB_ARC	:=	$(LIB_LIBFT)/$(LIBFT).a

PINT		:=	printf
LIB_PINT	:=	$(LIB_DIR)/$(PINT)
LIB_PINT_ARC:=	$(LIB_PINT)/$(PINT).a

LIB_LIST	:=	$(LIB_MLX_ARC) \
				$(LIB_LIB_ARC) \
				$(LIB_PINT_ARC)

#=============== COLOURS ================#

BOLD	:= \033[1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
CYAN	:= \033[36;1m
RESET	:= \033[0m

#============= COMPILATION ==============#

HEADER		:=	-I $(INC_DIR) \
				-I $(LIB_MLX)/include/MLX42 \
				-I $(LIB_LIBFT)/include \
				-I $(LIB_PINT)

LIB			:=	-lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

CC			:=	gcc
CFL			:=	-Wall -Werror -Wextra 
CFL_DB		:=	-Wall -Werror -Wextra -fsanitize=address

ifdef DB
COMPILE		:=	$(CC) $(CFL_DB)
else
COMPILE		:=	$(CC) $(CFL)
endif

#========================================#
#============== RECIPIES  ===============#
#========================================#

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $@

$(NAME): $(LIB_LIST) $(OBJ) 
	@$(COMPILE) $^ $(HEADER) -o $(NAME) $(LIB) $(LIB_LIST) 
	@echo "$(CYAN)$(BOLD)COMPILING COMPLETE$(RESET)"

test:	$(NAME)
	@echo "$(CYAN)$(BOLD) RUNNING ./$(NAME)$(RESET)"

test_42: test
	./fdf $(ARG_3)

db: clean
	@make $(NAME) DB=1

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(COMPILE) -o $@ -c $< $(HEADER)
	@echo "$(CYAN)COMPILING: $(notdir $<) $(RESET)"

lclean:
	@make -C $(LIB_MLX) clean
	@make -C $(LIB_LIBFT) clean
	@make -C $(LIB_PINT) clean

clean:
	@mkdir -p $(OBJ_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(BOLD)Cleaning FDF$(RESET)"

fclean: clean 
	@rm -f $(NAME)
	@rm -f $(LIB_MLX_ARC)
	@rm -f $(LIB_LIB_ARC)
	@rm -f $(LIB_PINT_ARC)

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

$(LIB_PINT_ARC):
	@make -C $(LIB_PINT)

#========================================#
#============ MISCELLANEOUS =============#
#========================================#

.PHONY: all clean fclean tclean re test test_db

.DEFAULT_GOAL := all

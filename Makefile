# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweverli <mweverli@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2022/07/11 17:41:13 by mweverli      #+#    #+#                  #
#    Updated: 2022/10/10 20:03:15 by mweverli      ########   odam.nl          #
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


LIB_LIST	:=	$(LIB_MLX_ARC) \
				$(LIB_LIB_ARC)

#=============== COLOURS ================#

BOLD	:= \033[1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
CYAN	:= \033[36;1m
RESET	:= \033[0m

#============= COMPILATION ==============#

HEADER		:=	-I $(INC_DIR) \
				-I $(LIB_MLX)/include/MLX42 \
				-I $(LIB_LIBFT)/include

LIB			:=	-lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

CC			:=	gcc
CFL			:=	-Wall -Werror -Wextra -g
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

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(COMPILE) -o $@ -c $< $(HEADER)
	@echo "$(CYAN)COMPILING: $(notdir $<) $(RESET)"

flclean: lclean fclean

lclean:
	@make -C $(LIB_MLX) clean
	@make -C $(LIB_LIBFT) clean

clean:
	@mkdir -p $(OBJ_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(BOLD)Cleaning FDF$(RESET)"

fclean: clean 
	@rm -f $(NAME)
	@rm -f $(LIB_MLX_ARC)
	@rm -f $(LIB_LIB_ARC)

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

.PHONY: all clean fclean tclean re test test_db

.DEFAULT_GOAL := all

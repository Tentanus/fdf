# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweverli <mweverli@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2022/07/11 17:41:13 by mweverli      #+#    #+#                  #
#    Updated: 2022/07/28 18:27:51 by mweverli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#========================================#
#=========  GENERAL VARIABLES:  =========#
#========================================#

NAME		:=	fdf

OBJ_DIR		:=	./OBJ
SRC_DIR		:=	./src
INC_DIR		:=	./include
HEA_DIR		:=	./headers
LIB_DIR		:=	./lib

MLX			:=	mlx
LIB_MLX		:=	$(LIB_DIR)/$(MLX)
LIB_MLX_ARC	:=	$(LIB_MLX)/libmlx42.a

LIBFT		:=	libft
LIB_LIBFT	:=	$(LIB_DIR)/$(LIBFT)
LIB_LIB_ARC	:=	$(LIB_LIBFT)/libft.a

SRC			:=	$(shell ls src/)
OBJ			:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

HEADER		:=	-I ./include -I $(LIB_MLX)/include/MLX42 -I $(LIB_LIBFT)
LIB			:=	-lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/

CC			:=	gcc
CFL			:=	-Wall -Werror -Wextra
CFL_DB		:=	-Wall -Werror -Wextra -g -fsanitize=address

ifdef DB
COMPILE		:=	$(CC) $(CFL_DB)
else
COMPILE		:=	$(CC) $(CFL)
endif

test_var: $(FORCE)
	$(OBJ)

#========================================#
#============== RECIPIES  ===============#
#========================================#

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(LIB_LIB_ARC) $(LIB_MLX_ARC) $(OBJ)
	$(COMPILE) $^ $(HEADER) -o $(NAME)

test: $(OBJ)
	$(COMPILE) -o $(EXE) $(OBJ) $(HEADER)

test_db: clean
	@make test DB=1

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c | $(OBJ_DIR)
	$(COMPILE) -o $@ -c $< $(HEADER) $(LIB)

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

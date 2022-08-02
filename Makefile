# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweverli <mweverli@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2022/07/11 17:41:13 by mweverli      #+#    #+#                  #
#    Updated: 2022/08/02 13:08:04 by mweverli      ########   odam.nl          #
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

GNL		:=	get_next_line
LIB_GNL	:=	$(LIB_DIR)/$(GNL)
LIB_GNL_ARC	:=	$(LIB_GNL)/$(GNL).a

#=============== COLOURS ================#

BOLD	:= \033[1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
CYAN	:= \033[36;1m
RESET	:= \033[0m

#============ TEST ARGUMENTS ============#

ARG_	:=	./maps/
ARG_2	:=	./maps/SQ_2x2.fdf
ARG_2	:=	./maps/SQ_4x4.fdf

#============= COMPILATION ==============#

HEADER		:=	-I $(INC_DIR) \
				-I $(LIB_MLX)/include/MLX42 \
				-I $(LIB_LIBFT)/include \
				-I $(LIB_GNL)/include
LIB			:=	-lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

CC			:=	gcc
CFL			:=	-Wall -Werror -Wextra
CFL_DB		:=	-Wall -Werror -Wextra -g -fsanitize=address

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

$(NAME): $(LIB_MLX_ARC) $(LIB_LIB_ARC) $(LIB_GNL_ARC) $(OBJ)
	@$(COMPILE) $^ $(HEADER) -o $(NAME) $(LIB)
	@echo "$(CYAN)$(BOLD)COMPILING COMPLETE: $(NAME) READY$(RESET)"

test:	$(NAME)
	./fdf

test_db: clean
	@make $(NAME) DB=1

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(COMPILE) -o $@ -c $< $(HEADER)
	@echo "$(CYAN)COMPILING: $(notdir $<) $(RESET)"

clean:
	@mkdir -p $(OBJ_DIR)
	@rm -rf $(OBJ_DIR)
	@make -C $(LIB_MLX) clean
	@make -C $(LIB_LIBFT) clean
	@make -C $(LIB_GNL) clean
	@echo "$(RED)$(BOLD)Cleaning FDF$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIB_MLX_ARC)
	@rm -f $(LIB_LIB_ARC)
	@rm -f $(LIB_GNL_ARC)

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

$(LIB_GNL_ARC):
	@make -C $(LIB_GNL)

#========================================#
#============ MISCELLANEOUS =============#
#========================================#

.PHONY: all clean fclean tclean re test test_db

.DEFAULT_GOAL := all

FORCE:

test_var: $(FORCE)
	$(SRC)

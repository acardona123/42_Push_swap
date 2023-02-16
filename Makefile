
NAME			=	push_swap
NAME_BONUS		=	checker

C_SRC_CIRCLST	=	circlst_building \
					circlst_print \
					circlst_rotate \
					circlst_swap_push \
					circlst_tools

C_RSC			=	indexation_fusion_sort \
					parsing \
					parsing_bis \
					piles_op_optimisation \
					piles_op_optimisation_bis \
					piles_op_optimisation_tris \
					sorting_main \
					sorting_pivots \
					main 

C_INCLUDES_GNL	=	get_next_line_utils \
					get_next_line
			
C_SRC_ALL		=	$(addprefix circlst/, $(C_SRC_CIRCLST))  $(C_RSC)
C_FILES			=	$(addprefix srcs/, $(addsuffix .c, $(C_SRC_ALL))) $(addprefix includes/gnl/, $(addsuffix .c, $(C_INCLUDES_GNL)))
O_FILES			= $(C_FILES:.c=.o)
O_FILES_DEBUG	= $(C_FILES:.c=_debug.o)

C_BONUS			=	circlst_bonus/circlst_building \
					circlst_bonus/circlst_rotate \
					circlst_bonus/circlst_swap_push \
					circlst_bonus/circlst_tools \
					tools \
					parsing \
					parsing_bis \
					piles_op_optimisation \
					checker
C_FILES_BONUS	=	$(addsuffix _bonus.c, $(addprefix bonus/, $(C_BONUS))) $(addprefix includes/gnl/, $(addsuffix .c, $(C_INCLUDES_GNL)))
O_FILES_BONUS	=	$(C_FILES_BONUS:.c=.o)

C_TEST 			=	
C_FILES_TEST	=	$(addsuffix .c, $(addprefix test/, $(C_TEST)))
O_FILES_TEST			=	$(C_FILES_TEST:.c=.o)

LIB_NAME = libftprintf.a
LIB_DIR = includes/libftprintf/
LIB_INCLUDE = -L./$(LIB_DIR) -lftprintf

INCLUDE = push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: lib $(NAME)
	@echo ""
	@echo "End of compilation"
	@echo "__________________"

%.o : %.c $(LIB_DIR)$(LIB_NAME) $(INCLUDE)
	$(CC) -g -c $< -o $@

$(NAME) : $(LIB_DIR)$(LIB_NAME) $(O_FILES) $(O_FILES_TEST)
	$(CC) $(C_FLAGS) $(C_FLAGS) $(O_FILES) $(O_FILES_TEST) $(LIB_INCLUDE) -o $(NAME)

lib :
	@printf '\e[94mmake libftprintf :\n[\n'
	@make --no-print-directory -C $(LIB_DIR)
	@printf ']\e[0m'
	@printf '\n\nCompilation push_swap/checker :\n'

clean :
	@make --no-print-directory clean -C $(LIB_DIR)
	rm -rf $(O_FILES) $(O_FILES_TEST) $(O_FILES_DEBUG) $(O_FILES_BONUS)

fclean : clean
	@make --no-print-directory fclean -C $(LIB_DIR)
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all

bonus : lib  $(NAME_BONUS)
	@echo ""
	@echo "End of compilation"
	@echo "__________________"

$(NAME_BONUS) : $(O_FILES_BONUS)
	$(CC) $(CFLAGS) -g $(O_FILES_BONUS) $(LIB_INCLUDE) -o $(NAME_BONUS)

.PHONY : all lib clean fclean re bonus
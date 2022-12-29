
NAME =	push_swap

C_SRC_CIRCLST	=	circlst_building \
					circlst_print \
					circlst_rotate \
					circlst_swap_push \
					circlst_tools

C_RSC			=	indexation_fusion_sort \
					parsing \
					piles_op_optimisation \
					piles_op_optimisation_bis \
					sorting 
#					main 
					
			
C_SRC_ALL		=	$(addprefix circlst/, $(C_SRC_CIRCLST)) $(C_RSC)
C_FILES			=	$(addprefix srcs/, $(addsuffix .c, $(C_SRC_ALL)))

O_FILES			= $(C_FILES:.c=.o)
O_FILES_DEBUG	= $(C_FILES:.c=_debug.o)

C_TEST 			=	test_op_optimisation
C_FILES_TEST	=	$(addsuffix .c, $(addprefix test/, $(C_TEST)))
O_TEST			=	$(C_FILES_TEST:.c=.o)

LIB_NAME = libftprintf.a
LIB_DIR = includes/libftprintf/
LIB_INCLUDE = -L./$(LIB_DIR) -lftprintf

INCLUDE = push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c $(LIB_DIR)$(LIB_NAME) $(INCLUDE)
	$(CC) -c $< -o $@

$(NAME) : $(O_FILES) $(O_TEST) $(LIB_DIR)$(LIB_NAME)
	$(CC) $(C_FLAGS) $(C_FLAGS) $(O_FILES) $(O_TEST) $(LIB_INCLUDE) -o $(NAME)

$(LIB_DIR)$(LIB_NAME) :
	@make --no-print-directory -C $(LIB_DIR)

clean :
	@make --no-print-directory clean -C $(LIB_DIR)
	rm -rf $(O_FILES) $(O_TEST) $(O_FILES_DEBUG)

fclean : clean
	@make --no-print-directory fclean -C $(LIB_DIR)
	rm -rf $(NAME)

re : fclean all

norm :
	norminette $(C_FILES) $(INCLUDE)

%_debug.o : %.c $(LIB_DIR)$(LIB_NAME)
	$(CC) $(C_FLAGS) -g -c $< -o $@

debug : $(O_FILES_DEBUG)
	$(CC) $(C_FLAGS) -g $(O_FILES_DEBUG) $(LIB_INCLUDE) -o $(NAME)
	echo "Valgrind : "
	valgrind ./$(NAME)


.PHONY : all clean fclean re norm debug
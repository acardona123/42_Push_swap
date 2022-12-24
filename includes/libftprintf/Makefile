NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

C_ROOT = add_arg0 add_arg1 add_arg2 add_arg3 add_str lst main

C_FILES = $(addsuffix .c, $(addprefix ft_printf_, $(C_ROOT)))

O_FILES = $(C_FILES:.c=.o)

LIBFT = libft/libft.a

H_INCLUDES = -I.
A_INCLUDES = -L. -lft

all : $(NAME)

%.o : %.c $(H_INCLUDES) $(A_INCLUDES)
	$(CC) $(CFLAGS) $(H_INCLUDES) $(A_INCLUDES) -c $< -o $@

$(NAME) : $(O_FILES) $(LIBFT)
	cp $(LIBFT) .
	mv libft.a $(NAME)
	ar -rcs $(NAME) $(O_FILES)

$(LIBFT) :
	@make bonus --no-print-directory -C libft/

clean :
	@make --no-print-directory clean -C libft/
	rm -f $(O_FILES)

fclean :
	@make --no-print-directory fclean -C libft/
	rm -rf $(O_FILES) $(NAME)

re : fclean all

.PHONY : all clean fclean re
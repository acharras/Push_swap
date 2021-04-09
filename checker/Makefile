BLUE =\033[0;38;5;123m
LIGHT_PINK = \033[0;38;5;200m
PINK = \033[0;38;5;198m
DARK_BLUE = \033[1;38;5;110m
GREEN = \033[1;32;111m
LIGHT_GREEN = \033[0;38;5;121m
LIGHT_RED = \033[0;31;5;110m
FLASH_GREEN = \033[33;32m
WHITE_BOLD = \033[37m
GREY = \033[3;90m
ORANGE = \033[3;91m
YELLOW = \033[0;33m

SRCS		=	main.c parse.c
SRCS_PATH	=	srcs/
OBJ_NAME	=	$(SRCS:.c=.o)
OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_NAME)) ../Libft/libft.a
OBJ_PATH	=	obj/
NAME		=	checker
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g3 -fsanitize=address
RM			=	rm -rf
HEADER		=	../includes


all		:	$(OBJ_PATH) $(NAME)

$(NAME) : $(OBJ) $(HEADER)
		@make -C ../Libft
		@$(CC) $(CFLAGS) $(OBJ_NAME) -I $(HEADERS) $(LIB) -o $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c $(HEADER)
			${CC} ${CFLAGS} -c $< -o $@ -I $(INCLUDE)
			@echo "\033[34m$(NAME): Loading... \033[0m"

$(OBJ_PATH):
			@mkdir -p obj/ 2> /dev/null

clean	:
			@$(RM) obj/
			@make clean -C ../Libft
			@echo "\033[91m$(NAME):\033[31m Deleting *.o...\033[0m"
			@echo "\033[91m\n$(NAME)\033[31m is now clean\033[0m"

fclean	:	clean
			@$(RM) $(NAME)
			@make fclean -C ../Libft

re		:	fclean all

run		:	${NAME}
			@./{NAME}

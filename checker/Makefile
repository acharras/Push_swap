DARK_BLUE = \033[1;38;5;110m
FLASH_GREEN = \033[33;32m
GREY = \033[3;90m
RESET = \033[0m
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

SRCS		=	main.c parse.c
SRCS_PATH	=	srcs/
OBJ_NAME	=	$(SRCS:.c=.o)
OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_NAME)) ../Libft/libft.a
OBJ_PATH	=	obj/
NAME		=	checker
CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra -g3 -fsanitize=address
RM			=	rm -rf
HEADER		=	../includes
LIBFT_PATH	=	../Libft


all		:	libft_all $(OBJ_PATH) $(NAME)

$(NAME) : $(OBJ)
		@$(CC) $(CFLAGS) -o $@ $(OBJ)
		@printf "\033[2K\r$(DARK_BLUE)checker\t:\t$(GREEN)Updated\n\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c $(HEADER)
			@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)
			@printf "$(BLUE)$(NAME): Loading... \033[0m\n"
			@printf "\033[2K\r\033[0;31;5;110mCompiling...	\033[37m$<\033[36m \033[0m"

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

libft_all :
			@make -C $(LIBFT_PATH) all

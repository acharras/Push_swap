SRCS		=	main.c parse.c

SRCS_PATH	=	srcs/

OBJ_NAME	=	${SRCS:.c=.o}

OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))

OBJ_PATH	=	obj/

NAME		=	checker

GCC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra -g3 -fsanitize=address

RM			=	rm -rf

HEADER		=	../includes

all :	$(OBJ_PATH) ${NAME}

$(NAME) : $(OBJ) $(HEADER)

$(OBJ_PATH)%.o: $(SRCS)%.c $(HEADER)
			@(GCC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)
			@echo "\033[34m$(NAME): Loading... \033[0m"

clean	:
	@$(RM) obj/
	@make clean -C libft
	@echo "\033[91m$(NAME):\033[31m Deleting *.o...\033[0m"
	@echo "\033[91m\n$(NAME)\033[31m is now clean\033[0m"

fclean	:	clean
	@$(RM) $(NAME)
	@make fclean -C libft

re		:	fclean all

run		:	${NAME}
			@./{NAME}

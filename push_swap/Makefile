# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/12 08:38:47 by aurbuche          #+#    #+#              #
#    Updated: 2021/04/15 14:15:21 by acharras         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

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

SRCS_TOOLS			=	$(addprefix tools/, ft_sqrt.c check_args.c check_stack_a.c ft_atoi_ps.c)
SRCS_ALGO			=	$(addprefix algo/, ft_algo_hundred_more.c find_min_max.c)
SRCS_NAME			=	main.c $(SRCS_TOOLS) $(SRCS_ALGO) $(SRCS_TOOLS_CHECKER)
SRCS_PATH			=	srcs/
SRCS				=	$(addprefix $(SRCS_PATH), $(SRCS_TOOLS) $(SRCS_ALGO))
OBJ_NAME			=	$(SRCS_NAME:.c=.o)
OBJ					=	$(addprefix $(OBJ_PATH), $(OBJ_NAME)) ../libft/libft.a
OBJ_PATH			=	obj/
NAME				=	push_swap
CC					=	clang
CFLAGS				=	-Wall -Werror -Wextra -g3 #-fsanitize=address
RM					=	rm -rf
HEADER				=	../includes
LIBFT_PATH			=	../libft
all		:	libft_all $(OBJ_PATH) $(NAME)
$(NAME) : $(OBJ)
			@$(CC) $(CFLAGS) -o $@ $(OBJ)
			@printf "\033[2K\r$(DARK_BLUE)checker\t:\t$(GREEN)Updated\n\033[0m"
$(OBJ_PATH)%.o: $(SRCS_PATH)%.c $(HEADER) Makefile
			@printf "\033[2K\r\033[0;31;5;110mCompiling...	\033[37m$<\033[36m \033[0m"
			@$(CC) $(FLAG) -g3 -I ${HEADER} -c $< -o $@
$(OBJ_PATH):
			@mkdir -p obj/ 2> /dev/null
			@mkdir -p obj/tools 2> /dev/null
			@mkdir -p obj/algo 2> /dev/null

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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/12 08:38:47 by acharras          #+#    #+#              #
#    Updated: 2021/04/29 15:09:29 by acharras         ###   ########lyon.fr    #
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

SRCS_OPTION			=	$(addprefix ../../checker/srcs/option/, ft_push.c ft_reverse_rotate.c ft_rotate.c ft_swap.c utils.c)
SRCS_PRINT			=	$(addprefix ../../checker/srcs/print/, print_stack.c)
SRCS_TOOLS			=	$(addprefix tools/, check_args.c check_stack_a.c ft_atoi_ps.c ft_sqrt.c check_option.c)
SRCS_ALGO			=	$(addprefix algo/, find_max.c ft_algo_hundred_more.c ft_algo_til_ten.c sort_stack.c stack.c pa_til_end.c\
								algo_three.c if_forrest.c final_sort_a.c final_sort_stack_two.c)
SRCS_NAME			=	main.c $(SRCS_TOOLS) $(SRCS_ALGO) $(SRCS_OPTION) $(SRCS_PRINT)
SRCS_PATH			=	srcs/
OPTION_PATH			=	../checker/srcs/
SRCS				=	$(addprefix $(SRCS_PATH), $(SRCS_TOOLS) $(SRCS_ALGO) $(SRCS_PRINT))
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
			@printf "\033[2K\r$(DARK_BLUE)push_swap:\t$(GREEN)Updated\n\033[0m"
$(OBJ_PATH)%.o: $(SRCS_PATH)%.c $(HEADER) Makefile
			@printf "\033[2K\r\033[0;31;5;110mCompiling...	\033[37m$<\033[36m \033[0m"
			@$(CC) $(FLAG) -g3 -I ${HEADER} -c $< -o $@
$(OBJ_PATH):
			@mkdir -p obj/ 2> /dev/null
			@mkdir -p obj/tools 2> /dev/null
			@mkdir -p obj/algo 2> /dev/null

clean	:
			@$(RM) obj/
			@$(RM) ../checker/srcs/option/*.o
			@$(RM) ../checker/srcs/print/*.o
			@make clean -C ../Libft
			@echo "\033[91m$(NAME):\033[31m Deleting *.o...\033[0m"
			@echo "\033[91m\n$(NAME)\033[31m is now clean\033[0m"
fclean	:	clean
			@$(RM) $(NAME)
			@make fclean -C ../Libft
re		:	fclean all
libft_all :
			@make -C $(LIBFT_PATH) all

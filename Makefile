# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acharras <acharras@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/12 08:38:47 by acharras          #+#    #+#              #
#    Updated: 2021/04/29 15:09:23 by acharras         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

OBJ					=	./push_swap/push_swap ./checker/checker ./libft/libft.a
RM					=	rm -rf
LIBFT_PATH			=	./libft
PUSH_SWAP_PATH		=	./push_swap
CHECKER_PATH		=	./checker

all		:	libft_all push_swap_all checker_all

clean	:
			@$(RM)
			@make clean -C ./libft
			@make clean -C ./push_swap
			@make clean -C ./checker
			
fclean	:	clean
			@$(RM)
			@make fclean -C ./libft
			@make fclean -C ./push_swap
			@make fclean -C ./checker
			
re		:	fclean all

libft_all :
			@make -C $(LIBFT_PATH) all

push_swap_all :
			@make -C $(PUSH_SWAP_PATH) all

checker_all :
			@make -C $(CHECKER_PATH) all

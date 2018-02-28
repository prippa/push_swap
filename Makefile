# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prippa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 14:20:39 by prippa            #+#    #+#              #
#    Updated: 2018/01/15 14:29:46 by prippa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP		=	push_swap

#FLAGS			= 	-Wall -Werror -Wextra

CC				=	gcc

DIR_LIB			=	./libft/
LIBFT			=	$(DIR_LIB)libft.a
DIR_LIB_INC		=	$(DIR_LIB)includes/
DIR_INC			=	./includes/
DIR_PUSH_SWAP	=	./push_swap_src/
DIR_OBJ			= 	./obj/

HEAD_PUSH_SWAP	=	push_swap.h

C_PUSH_SWAP		=	main.c


OBJ_PUSH_SWAP 	= 	$(C_PUSH_SWAP:.c=.o)
OBJ 			= 	$(addprefix $(DIR_OBJ), $(OBJ_PUSH_SWAP))
INC_LIB 		= 	$(addprefix -I, $(DIR_INC) $(DIR_LIB_INC))
INC_PUSH_SWAP 	= 	$(addprefix $(DIR_INC), $(HEAD_PUSH_SWAP))


all: lib obj $(PUSH_SWAP)

obj:
	@mkdir -p $(DIR_OBJ)

lib:
	@make -C $(DIR_LIB)

$(PUSH_SWAP): $(OBJ) $(LIBFT)
	@$(CC) -o $(PUSH_SWAP) $(OBJ) $(LIBFT)
	@echo "Compiling" [ $(PUSH_SWAP) ]

$(DIR_OBJ)%.o: $(DIR_PUSH_SWAP)%.c $(INC_PUSH_SWAP)
	@$(CC) $(FLAGS) $(INC_LIB) -c -o $@ $<
	@echo "Linking" [ $< ]

clean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files push_swap ]"
	@make -C $(DIR_LIB) clean

fclean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files push_swap ]"
	@rm -f $(PUSH_SWAP)
	@echo "Clean" [ $(PUSH_SWAP) ]
	@make -C $(DIR_LIB) fclean

re: fclean all

.PHONY: all clean fclean re 

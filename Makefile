# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prippa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 14:20:39 by prippa            #+#    #+#              #
#    Updated: 2018/03/12 21:52:51 by prippa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP			=	push_swap
CHECKER				=	checker

#FLAGS				= 	-Wall -Werror -Wextra

CC					=	gcc

DIR_LIB				=	./libft/
LIBFT				=	$(DIR_LIB)libft.a
DIR_LIB_INC			=	$(DIR_LIB)includes/
DIR_INC				=	./includes/
DIR_PUSH_SWAP		=	./push_swap_src/
DIR_CHECKER			=	./checker_src/
DIR_SRC				=	./src/
DIR_OBJ_PUSH_SWAP	= 	./push_swap_obj/
DIR_OBJ_CHECKER		= 	./checker_obj/

HEAD_PUSH_SWAP		=	push_swap.h

C_PUSH_SWAP			=	main.c ps_simple_algorithm.c\
						ps_quicksort_algorithm.c


C_CHECKER			=	main.c ch_parser.c\
						ch_visualize.c ch_vis_print_stack.c\
						ch_vis_get_op_num.c ch_solves.c\
						ch_vis_dispatcher.c ch_vis_helpers.c


C_SRC				=	ps_trash.c ps_init.c ps_free.c ps_parser.c\
						ps_list_push_pop.c ps_list_revers.c\
						ps_print_operation.c\
						ps_op_sa_sb_ss.c ps_op_pa_pb.c\
						ps_op_ra_rb_rr.c ps_op_rra_rrb_rrr.c\
						ps_make_operation.c ps_stack_is_sorted.c


LINK_PUSH_SWAP 		= 	$(C_PUSH_SWAP:.c=.o)
LINK_CHECKER		=	$(C_CHECKER:.c=.o)
LINK_SRC			=	$(C_SRC:.c=.o)

OBJ_PUSH_SWAP 		= 	$(addprefix $(DIR_OBJ_PUSH_SWAP), $(LINK_PUSH_SWAP) $(LINK_SRC))
OBJ_CHECKER 		= 	$(addprefix $(DIR_OBJ_CHECKER), $(LINK_CHECKER) $(LINK_SRC))
INC_LIB 			= 	$(addprefix -I, $(DIR_INC) $(DIR_LIB_INC))
INC_PUSH_SWAP 		= 	$(addprefix $(DIR_INC), $(HEAD_PUSH_SWAP))


all: lib obj $(PUSH_SWAP) $(CHECKER)

obj:
	@mkdir -p $(DIR_OBJ_PUSH_SWAP)
	@mkdir -p $(DIR_OBJ_CHECKER)

lib:
	@make -C $(DIR_LIB)

#-----------PUSH_SWAP---------------------------------
$(PUSH_SWAP): $(OBJ_PUSH_SWAP) $(LIBFT)
	@$(CC) -o $(PUSH_SWAP) $(OBJ_PUSH_SWAP) $(LIBFT)
	@echo "Compiling" [ $(PUSH_SWAP) ]

$(DIR_OBJ_PUSH_SWAP)%.o: $(DIR_PUSH_SWAP)%.c $(INC_PUSH_SWAP)
	@$(CC) $(FLAGS) $(INC_LIB) -c -o $@ $<
	@echo "Linking" [ $< ]

$(DIR_OBJ_PUSH_SWAP)%.o: $(DIR_SRC)%.c $(INC_PUSH_SWAP)
	@$(CC) $(FLAGS) $(INC_LIB) -c -o $@ $<
	@echo "Linking" [ $< ]
#-----------------------------------------------------

#-----------CHECKER-----------------------------------
$(CHECKER): $(OBJ_CHECKER) $(LIBFT)
	@$(CC) -o $(CHECKER) $(OBJ_CHECKER) $(LIBFT)
	@echo "Compiling" [ $(CHECKER) ]

$(DIR_OBJ_CHECKER)%.o: $(DIR_CHECKER)%.c $(INC_PUSH_SWAP)
	@$(CC) $(FLAGS) $(INC_LIB) -c -o $@ $<
	@echo "Linking" [ $< ]

$(DIR_OBJ_CHECKER)%.o: $(DIR_SRC)%.c $(INC_PUSH_SWAP)
	@$(CC) $(FLAGS) $(INC_LIB) -c -o $@ $<
	@echo "Linking" [ $< ]
#-----------------------------------------------------

clean:
	@rm -rf $(DIR_OBJ_PUSH_SWAP)
	@rm -rf $(DIR_OBJ_CHECKER)
	@echo "Clean [ obj files push_swap ]"
	@echo "Clean [ obj files checker ]"
	@make -C $(DIR_LIB) clean

fclean:
	@rm -rf $(DIR_OBJ_PUSH_SWAP)
	@rm -rf $(DIR_OBJ_CHECKER)
	@echo "Clean [ obj files push_swap ]"
	@echo "Clean [ obj files checker ]"
	@rm -f $(PUSH_SWAP)
	@rm -f $(CHECKER)
	@echo "Clean" [ $(PUSH_SWAP) ]
	@echo "Clean" [ $(CHECKER) ]
	@make -C $(DIR_LIB) fclean

re: fclean all

.PHONY: all clean fclean re 

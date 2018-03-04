# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prippa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 14:20:39 by prippa            #+#    #+#              #
#    Updated: 2017/11/13 14:21:04 by prippa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

FLAGS		= 	-Wall -Werror -Wextra

CC			=	gcc

DIR_INC		=	./includes/
DIR_LIBC	=	./libc/
DIR_FPF		=	./printf/
DIR_OBJ		= 	./obj/

HEAD_LIBC	=	libft.h
HEAD_FPF	=	ft_printf.h

C_LIBC		= 	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c\
			ft_isascii.c ft_isdigit.c ft_islowercase.c ft_isprint.c ft_isspace.c\
			ft_isstralpha.c ft_isstrdigit.c ft_isstrlowercase.c ft_isstruppercase.c\
			ft_isuppercase.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c\
			ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c\
			ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
			ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c\
			ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c\
			ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c\
			ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c\
			ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c\
			ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c\
			ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c\
			ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c\
			ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c\
			ft_strtrim.c ft_tolower.c ft_tostrlowercase.c ft_tostruppercase.c\
			ft_toupper.c ft_itoa_base.c get_next_line.c\
			ft_arr_free.c ft_str_free.c ft_arrlen.c ft_nbrlen.c ft_atoi_base.c\
			ft_clear.c ft_arrnew.c ft_putarr.c ft_putarr_fd.c ft_atoi_max.c

C_FPF		= 	ft_printf.c ft_dprintf.c\
				ft_pf_strjoin.c ft_charjoin.c\
				ft_unicode.c ft_conv_sig_int.c ft_conv_unsig_int.c\
				ft_get_flags.c ft_get_type.c\
				ft_get_oux.c ft_get_di.c ft_get_c.c ft_get_s.c\
				ft_output_c_modul.c ft_output_s_modul.c ft_output_d_modul.c\
				ft_output_u_modul.c ft_output_ox_modul.c\
				ft_output_p_modul.c\
				ft_fpf_color.c



OBJ_LIBC 	= 	$(C_LIBC:.c=.o)
OBJ_FPF 	= 	$(C_FPF:.c=.o)

OBJ 		= 	$(addprefix $(DIR_OBJ),$(OBJ_LIBC))
OBJ 		+= 	$(addprefix $(DIR_OBJ),$(OBJ_FPF))

INC 		= 	$(addprefix -I,$(DIR_INC))
INC_LIBC 	= 	$(addprefix $(DIR_INC),$(HEAD_LIBC))
INC_FPF 	= 	$(addprefix $(DIR_INC),$(HEAD_FPF))



all: obj $(NAME)

obj:
	@mkdir -p $(DIR_OBJ)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compiling" [ $(NAME) ]

$(DIR_OBJ)%.o: $(DIR_LIBC)%.c $(INC_LIBC)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

$(DIR_OBJ)%.o: $(DIR_FPF)%.c $(INC_FPF)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

clean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files libft ]"

fclean: clean
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re

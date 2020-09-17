# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/04 03:51:05 by mbrizion          #+#    #+#              #
#    Updated: 2020/09/04 04:52:06 by mbrizion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_printf_error.a

C_DIR		=	srcs/
O_DIR		=	objs/

C_FILES		=	ft_printf.c \
         		conv_init.c \
    	 		conv_c.c \
          		flag_parser.c \
          		tools.c

SRCS		=	$(addprefix $(C_DIR), $(C_FILES))
OBJS		=	$(addprefix $(O_DIR), $(C_FILES:.c=.o))

CC			= 	gcc

CFLAGS		=	-I../inc 

LIBS		=	../libft/libft.a

RM			= 	rm -f

$(O_DIR)%.o:	$(C_DIR)%.c
				@mkdir -p $(O_DIR)
				@${CC} ${CFLAGS} -c $< -o $@

$(NAME): 		${OBJS}
				@ar rc ${NAME} ${OBJS}
				@echo ${GREEN}[ft_printf_error.a DONE]${END}

all:			${NAME}

clean: 
				@${RM} ${OBJS}

fclean: 		clean
				@${RM} ${NAME}
				@rm -rf objs

re: 			fclean all

GREEN		=	'\033[0;32m'
END			=	'\033[0m'

.PHONY: re fclean clean .c.o all

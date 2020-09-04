# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/04 03:41:23 by mbrizion          #+#    #+#              #
#    Updated: 2020/09/04 04:34:28 by mbrizion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Cub3D

C_DIR		=	srcs/
O_DIR		=	objs/

C_FILES		=	main.c \
				map_parser.c \
				tools.c \
				raycasting.c \
				move.c \
				keypress.c \
				sprite_raycast.c \
				raycasting2.c \
				map_checker.c \
				bmp.c \
				free_all.c

SRCS 		= 	$(addprefix $(C_DIR), $(C_FILES))
OBJS 		= 	$(addprefix $(O_DIR), $(C_FILES:.c=.o))

CC			=	clang

CFLAGS		=	-I./ -fsanitize=address #-Wall -Wextra -Werror 

LIBS		=	libft/libft.a ft_printf_error/ft_printf_error.a

LINUX_FLAGS =	-lmlx -lbsd -lXext -lX11 -lm 

MAC_FLAGS 	= 	-lmlx -framework OpenGL -framework AppKit -lm

RM			= 	rm -f

all:			${NAME}


$(O_DIR)%.o:	$(C_DIR)%.c
				@mkdir -p $(O_DIR)
				@${CC} ${CFLAGS} -c $< -o $@

${NAME}:		${OBJS}
				@make -C libft
				@make -C ft_printf_error
				@${CC} ${OBJS} ${MAC_FLAGS} ${CFLAGS} ${LIBS} -o ${NAME}
				@echo ${GREEN}[Comp.DONE]${END}

clean:
				@${RM} ${OBJS}
				@make clean -C libft
				@make clean -C ft_printf_error
				@echo ${BLUE}[All clean]${END}

fclean:			clean
				@${RM} ${NAME}
				@make fclean -C libft
				@make fclean -C ft_printf_error
				@rm -rf objs

re:				fclean all

GREEN		= 	'\033[0;32m'
BLUE		= 	'\033[0;36m'
END			= 	'\033[0m'

.PHONY:			clean fclean re .c.o all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/04 03:41:23 by mbrizion          #+#    #+#              #
#    Updated: 2020/09/24 02:55:05 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D
NAME_BONUS		=	cub3D_BONUS

C_DIR			=	srcs/
O_DIR			=	objs/
CB_DIR			=	srcs_bonus/
OB_DIR			=	objs_bonus/

C_FILES			=	main.c					\
					map_parser.c			\
					parser_utils.c			\
					parser_utils2.c 		\
					parser_utils3.c		 	\
					parser_utils4.c 		\
					tools.c					\
					tools2.c				\
					tools3.c				\
					raycasting.c			\
					raycasting2.c			\
					raycasting3.c			\
					move.c					\
					keypress.c				\
					sprite_raycast.c		\
					sprite_raycast_utils.c	\
					map_checker.c			\
					bmp.c 					\
					free_all.c

SRCS 			= 	$(addprefix $(C_DIR), $(C_FILES))
SRCS_BONUS		=	$(addprefix $(CB_DIR), $(C_FILES))
OBJS 			= 	$(addprefix $(O_DIR), $(C_FILES:.c=.o))
OBJS_BONUS 		= 	$(addprefix $(OB_DIR), $(C_FILES:.c=.o))

CC				=	clang

CFLAGS			=	-I./inc -Wall -Wextra -Werror #-fsanitize=address
CFLAGS_BONUS	=	-I./inc -Wall -Wextra -Werror #-fsanitize=address 

LIBS			=	libft/libft.a minilibx-linux/libmlx_Linux.a

LINUX_FLAGS 	=	-lbsd -lXext -lX11 -lm 

MAC_FLAGS 		= 	-lmlx -framework OpenGL -framework AppKit -lm

RM				= 	rm -f

all:			${NAME}


$(O_DIR)%.o:	$(C_DIR)%.c
				@mkdir -p $(O_DIR)
				@${CC} ${CFLAGS} -c $< -o $@

$(OB_DIR)%.o:	$(CB_DIR)%.c
				@mkdir -p $(OB_DIR)
				@${CC} ${CFLAGS_BONUS} -c $< -o $@

${NAME}:		${OBJS}
				@make -sC libft
				@make -sC minilibx-linux
				@${CC} ${OBJS} ${LINUX_FLAGS} ${CFLAGS} ${LIBS} -o ${NAME}
				@echo ${GREEN}[Comp.DONE]${END}

clean:
				@${RM} ${OBJS} 
				@make clean -sC libft
				@make clean -sC minilibx-linux
				@echo ${BLUE}[All clean]${END}

bonus:			${OBJS_BONUS}
				@make -sC libft
				@make -sC minilibx-linux
				@${CC} ${OBJS_BONUS} ${LINUX_FLAGS} ${CFLAGS_BONUS} ${LIBS} -o ${NAME_BONUS}
				@echo ${GREEN}[Comp.DONE]${END}

fclean:			clean
				@${RM} ${NAME} ${NAME_BONUS}
				@make fclean -sC libft
				@rm -rf objs objs_bonus screenshot.bmp

re:				fclean all

GREEN			= 	'\033[0;32m'
BLUE			= 	'\033[0;36m'
END				= 	'\033[0m'

.PHONY: clean fclean re .c.o all
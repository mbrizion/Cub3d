SRCS	= 	srcs/main.c \
			srcs/map_parser.c \
			GNL/get_next_line.c \
			GNL/get_next_line_utils.c \
			srcs/tools.c \
			srcs/raycasting.c \
			srcs/move.c \
			srcs/keypress.c \
			srcs/sprite_raycast.c \
			srcs/raycasting2.c \
			srcs/map_checker.c \
			srcs/bmp.c

OBJS	= ${SRCS:.c=.o}

NAME	= Cub3D

CC		= gcc -fsanitize=address

CFLAGS	= #-Wall -Wextra -Werror 

RM		= rm -rf

$(NAME): ${OBJS}
	make -C libft
	make -C ft_printf_error
	${CC} -lbsd -lm -lmlx -lXext -lX11 ${SRCS} -o ${NAME} libft/libft.a ft_printf_error/ft_printf_error.a /home/jacktatoume/minilibx_linux/libmlx.a
	echo ${GREEN}[Comp.DONE]${END}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
	make fclean -C libft
	make fclean -C ft_printf_error

re: 	fclean all

GREEN	= '\033[0;32m'
END		= '\033[0m'

.PHONY: re fclean clean .c.o all

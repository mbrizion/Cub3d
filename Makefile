NAME	=	Cub3D

C_DIR	=	srcs

C_FILES	=	main.c \
			map_parser.c \
			get_next_line.c \
			get_next_line_utils.c \
			tools.c \
			raycasting.c \
			move.c \
			keypress.c \
			sprite_raycast.c \
			raycasting2.c \
			map_checker.c \
			bmp.c \
			free_all.c 
			
SRCS	=	$(addprefix ${C_DIR}/, ${C_FILES})

OBJS	=	${SRCS:.c=.o}

CC		=	clang

CFLAGS	=	-I./inc/ #-Wall -Wextra -Werror -fsanitize=address

LIBS	=	libft/libft.a ft_printf_error/ft_printf_error.a

RM		= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			make -C libft
			make -C ft_printf_error
			${CC} ${OBJS} -lmlx -lbsd -lXext -lX11 -lm ${LIBS} -o ${NAME}
			echo ${GREEN}[Comp.DONE]${END}

.c.o:
			${CC} ${CFLAGS} -c $< -o $@

.PHONY:		clean fclean re .c.o all

clean:
			${RM} ${OBJS}
			make clean -C libft
			make clean -C ft_printf_error

fclean:		clean
			${RM} ${NAME}
			make fclean -C libft
			make fclean -C ft_printf_error

re:			fclean all

GREEN	= '\033[0;32m'
END		= '\033[0m'
SRCS	= printf/ft_printf.c \
          printf/conv_init.c \
    	  printf/conv_c.c \
          printf/flag_parser.c \
          printf/tools.c

OBJS	= ${SRCS:.c=.o} 

NAME	= ft_printf_error.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror 

RM		= rm -rf

$(NAME): ${OBJS}
	ar rc ${NAME} ${OBJS}
	@echo ${GREEN}[ft_printf_error.a DONE]${END} ../libft/libft.a

.c.o:
	@${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} 

re: 	fclean all

GREEN	= '\033[0;32m'
END		= '\033[0m'

.PHONY: re fclean clean .c.o all

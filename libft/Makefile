# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 14:31:44 by mbrizion          #+#    #+#              #
#    Updated: 2020/09/04 04:52:02 by mbrizion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	libft.a

C_DIR		=	srcs/
O_DIR		=	objs/

C_FILES		= 	ft_isprint.c \
				ft_strlen.c \
				ft_isalpha.c \
				ft_isalnum.c \
				ft_isdigit.c \
				ft_isascii.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_strchr.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strncmp.c \
				ft_strrchr.c \
				ft_atoi.c \
				ft_strnstr.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strmapi.c \
				ft_split.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_substr.c \
				ft_itoa.c \
				ft_strtrim.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				get_next_line.c \
				get_next_line_utils.c


SRCS		=	$(addprefix $(C_DIR), $(C_FILES))
OBJS		=	$(addprefix $(O_DIR), $(C_FILES:.c=.o))

CC			=	gcc

CFLAGS		=	-I./

RM			=	rm -f

$(O_DIR)%.o:	$(C_DIR)%.c
				@mkdir -p $(O_DIR)
				@${CC} ${CFLAGS} -c $< -o $@

$(NAME): 		${OBJS}
				@ar rc ${NAME} ${OBJS}
				@echo ${GREEN}[libft.a DONE]${END}

all:			${NAME}

clean:
				@${RM} ${OBJS}

fclean: 		clean
				@${RM} ${NAME}
				@rm -rf objs

re: 			fclean all

GREEN		= 	'\033[0;32m'
END			= 	'\033[0m'

.PHONY: re fclean clean .c.o all

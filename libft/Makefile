# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 14:31:44 by mbrizion          #+#    #+#              #
#    Updated: 2020/02/12 16:21:17 by mbrizion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isprint.c ft_strlen.c ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_isascii.c ft_tolower.c ft_toupper.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_strrchr.c ft_atoi.c ft_strnstr.c ft_bzero.c ft_calloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strdup.c ft_strjoin.c ft_strmapi.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_itoa.c ft_strtrim.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS	= ${SRCS:.c=.o}


NAME	= libft.a

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

$(NAME): ${OBJS}
	@ar rc ${NAME} ${OBJS}
	@echo ${GREEN}[libft.a DONE]${END}

.c.o:	
	@${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

clean:
	@${RM} ${OBJS} ${OBJBNS}

fclean: clean
	@${RM} ${NAME} ${OBJBNS}

re: 	fclean all

GREEN	= '\033[0;32m'
END		= '\033[0m'

.PHONY: re fclean clean .c.o all

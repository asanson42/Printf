# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asanson <asanson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/25 15:51:59 by asanson           #+#    #+#              #
#    Updated: 2021/02/01 14:11:11 by asanson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_is_it.c ft_conv_u.c ft_conv_s.c ft_conv_c.c ft_conv_p.c ft_conv_base.c printf_utils.c ft_conv_x.c ft_check_flags.c ft_printf.c ft_conv_di.c ft_conv_perc.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC		= gcc

CFLAGS		= -Wall -Wextra -Werror

RM		= rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		ar -rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re

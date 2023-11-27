# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghun <seunghun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 16:49:11 by seunghun          #+#    #+#              #
#    Updated: 2023/11/27 16:48:23 by seunghun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm
RMFLAGS		=	-f

AR			=	ar
ARFLAGS		=	rcs

SRCS		=	ft_printf.c			ft_printf_chr.c		\
				ft_printf_pt.c		ft_printf_u.c		\
				ft_printf_int.c		ft_printf_str.c		\
				ft_printf_utils.c	ft_printf_x.c		\

OBJS		=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(RMFLAGS) $(OBJS)
fclean : clean
	$(RM) $(RMFLAGS) $(NAME)
re : 
	make fclean
	make all

.PHONY : all clean fclean re

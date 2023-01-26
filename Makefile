# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 17:37:07 by tduprez           #+#    #+#              #
#    Updated: 2023/01/26 15:54:00 by tduprez          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

SRCS = 	ft_printf.c \
		ft_putnbr.c	\
		ft_putstr.c \
		ft_putchar.c \
		ft_putstrerr.c \
		ft_putmemory.c \
		ft_putnbr_base.c \
		ft_print_memory.c \
		ft_putnbr_unsign.c \

HEADER = ft_printf.h

OBJS = $(SRCS:.c=.o)

FLAGS	= -Wall -Wextra -Werror

CC = gcc

RM = rm -f

AR = ar rcs

%.o:	%.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER)

all:	$(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;34m Compiling ft_printf"
	@$(AR) $(NAME) $(OBJS)
	@echo "\033[0;32m Ft_printf successfully compiled !"

clean:
	@echo "\033[0;33m Cleaning objects files"
	@$(RM) $(OBJS)
	@echo "\033[0;32m Objects files successfully cleaned !"

fclean:
	@echo "\033[0;35m Cleaning objects files an library"
	@$(RM) $(NAME)
	@$(RM) $(OBJS)
	@echo "\033[0;32m Objects files and library successfully cleaned !"


re: fclean all

.PHONY = all clean fclean re

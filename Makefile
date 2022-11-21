# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 17:37:07 by tduprez           #+#    #+#              #
#    Updated: 2022/11/18 17:42:36 by tduprez          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_print_memory.c	ft_printf.c	ft_putchar.c	ft_putnbr_base.c	ft_putnbr_unsign.c	ft_putnbr.c	\
		ft_putstr_x_print_memory.c	ft_putstr.c

# SRCS_BONUS = ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c	ft_lstmap.c

HEADER = ..

OBJS = $(SRCS:.c=.o)

# OBJS_BONUS = $(SRCS_BONUS:.c=.o)

FLAGS	= -Wall -Wextra -Werror

CC = gcc

RM = rm -f

AR = ar rcs

%.o:	%.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I $(HEADER)

all:	$(NAME)
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# bonus: $(NAME) $(OBJS_BONUS)
#	$(AR) $(NAME) $(OBJS_BONUS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htomohit <htomohit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 17:12:33 by kyuki             #+#    #+#              #
#    Updated: 2020/10/22 22:28:00 by htomohit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libft.a

CC	= gcc

CFLAGS	= -Wall	-Wextra	-Werror

RM		=	rm -f

MAIN	= main.c

INCDIR	=	./libft

SRCDIR	=	./

SRCNAME	=	ft_bzero.c ft_memccpy.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlen.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_memcmp.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isalnum.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strrchr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS	=	$(addprefix $(SRCDIR), $(SRCNAME))

OBJS	=	$(SRCS:.c=.o)



.c.o:
			$(CC) $(CFLAGS)	-I $(INCDIR) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar	rc	$(NAME)	$(OBJS)

all:		$(NAME)

com:
			$(CC) $(MAIN) -L. -lft

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:	all clean fclean re

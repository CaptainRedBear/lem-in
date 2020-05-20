# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 12:47:14 by cglanvil          #+#    #+#              #
#    Updated: 2019/07/25 12:50:41 by cglanvil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES =	ft_atoi.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putstr.c	\
		ft_range.c \
		ft_strcmp.c \
		ft_strlen.c \
		ft_strrev.c \
		ft_swap.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strstr.c \
		ft_strncmp.c \
		ft_strupcase.c \
		ft_strlowcase.c \
		ft_strcapitalize.c \
		ft_strdup.c \
		ft_itoa.c \
		ft_strnstr.c \
		ft_isupper.c \
		ft_islower.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_bzero.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_putendl.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_iswhitespace.c \
		ft_nbrlen.c \
		ft_strsplit.c \
		ft_wordcount.c \
		ft_wordlen.c \
		ft_lstnew.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstmap.c \
		ft_strcattoc.c \
		get_next_line.c
all: $(NAME)
$(NAME):
	gcc -c -Wall -Wextra -Werror $(FILES)
	ar rc $(NAME) *.o
	ranlib $(NAME)
	rm -f *.o
clean:
fclean: clean
	rm -f $(NAME)
re: fclean all

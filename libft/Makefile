# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sstanfel <sstanfel@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 12:19:23 by sstanfel          #+#    #+#              #
#    Updated: 2023/07/23 17:03:15 by sstanfel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFILE =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c\
	ft_memcpy.c ft_strlcpy.c ft_strlcat.c ft_toupper.c\
	ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
	ft_memcmp.c ft_atoi.c ft_memchr.c ft_putchar_fd.c\
	ft_putstr_fd.c ft_calloc.c ft_strdup.c ft_strnstr.c\
	ft_itoa.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c\
	ft_strjoin.c ft_putendl_fd.c ft_substr.c ft_memmove.c\
	ft_strtrim.c ft_split.c ft_strncmp.c\
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
	ft_lstmap.c get_next_line.c get_next_line_utils.c\
	ft_printf.c ft_put_hexa.c ft_putint.c ft_putnbr_base.c ft_putunsigned.c\
	ft_utilities.c

NAME = libft.a

FLAGZ = -Wall -Werror -Wextra

CC = cc

OFILE = $(CFILE:.c=.o)

$(NAME):
	$(CC) -c $(FLAGZ) $(CFILE)
	ar -src $(NAME) $(OFILE) 

all: $(NAME) 

fclean:
	@rm -f $(NAME)

clean: 
	@rm -f $(OFILE)

re: fclean all

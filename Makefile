# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sstanfel <sstanfel@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 16:17:16 by sstanfel          #+#    #+#              #
#    Updated: 2023/07/28 16:54:24 by sstanfel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := so_long
CC        := cc
FLAGS    := -Wall -Wextra -Werror -g

SRCS        :=  sources/free_exit.c \
				sources/map_check_utils.c \
				sources/map_check1.c \
				sources/map_check2.c \
				sources/map_check3.c \
				sources/mlx_utils.c \
				sources/mlx.c \
				sources/movement.c\
				sources/play_game.c \
				sources/main.c
						  
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

CLR_RMV     := \033[0m
RED         := \033[1;31m
GREEN       := \033[1;32m
YELLOW      := \033[1;33m
BLUE        := \033[1;34m
CYAN        := \033[1;36m
RM          := rm -f

$(NAME): ${OBJS}
	@echo "$(GREEN)Linux-Kompilierung ${CLR_RMV}von ${YELLOW}$(NAME) ${CLR_RMV}..."
	@chmod 777 mlx_linux/configure
	@$(MAKE) -C mlx_linux all
	@$(MAKE) -C libft
	@$(CC) $(OBJS) $(FLAGS) -o $(NAME) -Imlx_linux -Lmlx_linux -lmlx -lXext -lX11 -lm libft/libft.a
	@echo "$(GREEN)$(NAME) erstellt[0m ✔️"

all: $(NAME)

clean:
	@${RM} $(OBJS)
	@$(MAKE) -C mlx_linux clean
	@$(MAKE) -C libft clean 
	@echo "$(RED)Lösche $(CYAN)$(CLR_RMV)Objekte ✔️"

fclean: clean
	@${RM} $(NAME)
	@$(MAKE) -C libft fclean
	@echo "$(RED)Lösche $(CYAN)$(NAME) $(CLR_RMV)ausführbare Datei ✔️"

re: fclean all

.PHONY: all clean fclean re



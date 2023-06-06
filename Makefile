# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 15:32:24 by abourgue          #+#    #+#              #
#    Updated: 2023/06/06 05:02:03 by abourgue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC_DIR = ./

SRC = \
	main.c console.c check_args.c libft.c utils.c \
	lib_itoa.c state.c

SOURCES = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(SOURCES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

G		= \033[0;90m #gray
R		= \033[0;91m #red
GR		= \033[0;92m #green
Y		= \033[0;93m #yellow
B		= \033[0;94m #blue
M		= \033[0;95m #magenta
C		= \033[0;96m #cyan
W		= \033[0;97m #white
ENDCOLOR	= \033[0m #reset
BG_G		= \033[42m #bg_g

all: $(NAME)

$(NAME): $(OBJS)
	@echo "${GR}"
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o: %.c
	@$(CC) -c $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo fclean: OK

re: fclean all
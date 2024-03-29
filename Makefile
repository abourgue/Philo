# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 15:32:24 by abourgue          #+#    #+#              #
#    Updated: 2023/09/19 14:26:23 by abourgue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC_DIR = src/
SRC = check_args.c libft.c main.c init.c activity.c philocontrol.c time.c\

SOURCES = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

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
	${CC} ${CFLAGS} ${OBJS}  -o ${NAME}

%.o: %.c
	$(CC) -c $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	echo fclean: OK

re: fclean all
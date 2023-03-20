# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguedes <lguedes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 13:43:30 by lguedes           #+#    #+#              #
#    Updated: 2023/03/14 05:54:13 by lguedes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers


#TODO Change this to cc compiler later on
CC = clang
CFLAGS = -Wall -Werror -Wextra -pthread


SRCS = $(addprefix Src/, main.c init_philos.c mutexes_init.c)

OBJS = ${SRCS:.c=.o}

LIBFT_A = ./Includes/libft/libft.a
LIBFT_PATH = ./Includes/libft/

.c.o:
			${CC} ${CFLAG} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: LIBFT ${OBJS}
	${CC} ${OBJS} ${LIBFT_A} ${CLAFGS}  -o $(NAME)


LIBFT:
	make -C $(LIBFT_PATH)

clean:
	@rm -rf ${OBJS}
	make -C $(LIBFT_PATH) clean

fclean:
	@rm -rf ${OBJS}
	@rm -rf ${NAME}
	make -C $(LIBFT_PATH) fclean




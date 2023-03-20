# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguedes <lguedes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 13:43:30 by lguedes           #+#    #+#              #
#    Updated: 2023/03/20 20:04:02 by lguedes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers


#TODO Change this to cc compiler later on
CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread


SRCS = $(addprefix Src/, main.c init_philos.c mutexes_init.c actions.c routines.c dinner.c) 

OBJS = ${SRCS:.c=.o}

LIBFT_A = ./Includes/libft/libft.a
LIBFT_PATH = ./Includes/libft/

.c.o:
			${CC} ${CFLAG} -g -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: LIBFT ${OBJS}
	${CC} -g ${OBJS} ${LIBFT_A} ${CLAFGS} -g  -o $(NAME)


LIBFT:
	make -C $(LIBFT_PATH)

clean:
	@rm -rf ${OBJS}
	make -C $(LIBFT_PATH) clean

fclean:
	@rm -rf ${OBJS}
	@rm -rf ${NAME}
	make -C $(LIBFT_PATH) fclean

re: fclean all



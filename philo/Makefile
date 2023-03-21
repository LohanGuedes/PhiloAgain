# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguedes <lguedes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 13:43:30 by lguedes           #+#    #+#              #
#    Updated: 2023/03/20 22:52:37 by lguedes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo


#TODO Change this to cc compiler later on
CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread


SRCS = $(addprefix Src/, utils.c  main.c init_philos.c mutexes_init.c actions.c routines.c dinner.c) 

OBJS = ${SRCS:.c=.o}

LIBFT_A = ./Includes/libft/libft.a
LIBFT_PATH = ./Includes/libft/


.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${LIBFT_A} ${OBJS}
	${CC} ${CLAFGS} ${OBJS} ${LIBFT_A}  -o $(NAME)


${LIBFT_A}: 
	make -C $(LIBFT_PATH)

clean:
	@rm -rf ${OBJS}
	make -C $(LIBFT_PATH) clean

fclean:
	@rm -rf ${OBJS}
	@rm -rf ${NAME}
	make -C $(LIBFT_PATH) fclean

re: fclean all



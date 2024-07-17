# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hawild <hawild@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 13:52:26 by hawild            #+#    #+#              #
#    Updated: 2024/07/16 19:21:55 by hawild           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = -Iinclude

SRCS = argument_check.c calc.c costs.c ft_split.c list.c push_swap.c push.c reverse_rotate.c \
		rotate.c small_nbr_sort.c sort_best_friend.c swap.c utils.c utils_stack.c

OBJS = ${SRCS:.c=.o}


CFLAGS = -Wall -Wextra -Werror -g

CC = gcc

.c.o:		
			@gcc ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

all: 		${NAME}

${NAME}: 	${OBJS}
						@${CC} ${OBJS} -o ${NAME}
						@echo "\033[0;32mPush_swap compiled\033[0m"

clean: 
						@rm -f ${OBJS}
						@echo "\033[0;35mObjects removed\033[0m"

fclean: 	clean
						@rm -f ${NAME}
						@echo "\033[0;36mEverything removed\033[0m"

re: 		fclean all

.PHONY:      all clean fclean re
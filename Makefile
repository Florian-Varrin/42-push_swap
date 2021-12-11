# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 10:27:38 by fvarrin           #+#    #+#              #
#    Updated: 2021/12/11 16:30:54 by fvarrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef DEBUG
	DEBUG		= 0
endif

ifeq (${DEBUG}, 1)
	DEBUG_FLAGS	= -D DEBUG=${DEBUG} -Wno-unused-variable -g
else
	DEBUG_FLAGS	=
endif

ROOT_DIR		?= $(shell pwd)
SRC_DIR			= ${ROOT_DIR}/srcs/
STACK_SRC_DIR		= ${ROOT_DIR}/stack-srcs/
HEADER_DIR		= ${ROOT_DIR}/includes/
LIBFT_DIR		= ${ROOT_DIR}/libft/
STACK_SRC		= $(addprefix ${STACK_SRC_DIR}, init.c push.c swap.c rotate.c \
			  reverse-rotate.c debug.c utils.c sorting-utils.c)
SRC			= $(addprefix ${SRC_DIR}, main.c parse.c insert.c swap-in-stack.c \
			  sort-utils.c small-sort.c quick-sort-2.c)
OBJ			= $(SRC:.c=.o)
STACK_OBJ		= $(STACK_SRC:.c=.o)
NAME 			= push_swap
NORM_BIN		= norminette
NORM_FLAGS		= -RCheckForbiddenSourceHeader -RCheckDefine
RM			= rm -f
CFLAGS			= -Wall -Wextra -Werror -I${HEADER_DIR} -I${LIBFT_DIR}includes -I${LIBSTACK_DIR}includes
CC			= gcc
LIBFT_FLAGS		= -L${LIBFT_DIR} -lft

.PHONY: 	all clean fclean re

${NAME}:	${OBJ} ${STACK_OBJ}
		@make -C ${LIBFT_DIR} all || true
		${CC} ${CFLAGS} ${OBJ} ${STACK_OBJ} ${LIBFT_FLAGS} -o ${NAME}

all: 		${NAME}

clean:
		${RM} ${OBJ}
		${RM} ${STACK_OBJ}

fclean: 	clean
		@make -C ${LIBFT_DIR} fclean || true
		${RM} ${NAME}

re:		fclean ${NAME}

norm:		fclean
		echo "\n\n"
		${NORM_BIN} ${NORM_FLAGS} ${SRC}

debug:
		@make -C ./ DEBUG=1 ${NAME} || true

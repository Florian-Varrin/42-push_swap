# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 10:27:38 by fvarrin           #+#    #+#              #
#    Updated: 2021/12/11 17:02:52 by fvarrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# DIRS
ROOT_DIR		?= $(shell pwd)
PUSH_SWAP_SRC_DIR	= ${ROOT_DIR}/srcs/
STACK_SRC_DIR		= ${ROOT_DIR}/stack-srcs/
CHECKER_SRC_DIR		= ${ROOT_DIR}/checker-srcs/
HEADER_DIR		= ${ROOT_DIR}/includes/
LIBFT_DIR		= ${ROOT_DIR}/libft/

# SRCS
PUSH_SWAP_SRC		= $(addprefix ${PUSH_SWAP_SRC_DIR}, main.c parse.c insert.c swap-in-stack.c \
			  sort-utils.c small-sort.c quick-sort-2.c)
STACK_SRC		= $(addprefix ${STACK_SRC_DIR}, init.c push.c swap.c rotate.c \
			  reverse-rotate.c debug.c utils.c sorting-utils.c)
CHECKER_SRC		= $(addprefix ${CHECKER_SRC_DIR}, main.c)

# OBJS
PUSH_SWAP_OBJ		= $(PUSH_SWAP_SRC:.c=.o)
STACK_OBJ		= $(STACK_SRC:.c=.o)
CHECKER_OBJ		= $(CHECKER_SRC:.c=.o)

# NAMES
PUSH_SWAP_NAME 		= push_swap
CHECKER_NAME		= checker

# COMPILER
NORM_BIN		= norminette
NORM_FLAGS		= -RCheckForbiddenSourceHeader -RCheckDefine
RM			= rm -f
CFLAGS			= -Wall -Wextra -Werror -I${HEADER_DIR} -I${LIBFT_DIR}includes -I${LIBSTACK_DIR}includes
CC			= gcc
LIBFT_FLAGS		= -L${LIBFT_DIR} -lft

.PHONY: 	all clean fclean re

all:			${PUSH_SWAP_NAME} ${CHECKER_NAME}

${PUSH_SWAP_NAME}:	${STACK_OBJ} ${PUSH_SWAP_OBJ}
			@make -C ${LIBFT_DIR} all || true
			${CC} ${CFLAGS} ${PUSH_SWAP_OBJ} ${STACK_OBJ} ${LIBFT_FLAGS} -o ${PUSH_SWAP_NAME}

${CHECKER_NAME}:	${STACK_OBJ} ${CHECKER_OBJ}
			@make -C ${LIBFT_DIR} all || true
			${CC} ${CFLAGS} ${CHECKER_OBJ} ${STACK_OBJ} ${LIBFT_FLAGS} -o ${CHECKER_NAME}

clean:
			${RM} ${STACK_OBJ}
			${RM} ${PUSH_SWAP_OBJ}
			${RM} ${CHECKER_OBJ}

fclean: 	clean
		@make -C ${LIBFT_DIR} fclean || true
		${RM} ${PUSH_SWAP_NAME}
		${RM} ${CHECKER_NAME}

re:		fclean ${PUSH_SWAP_NAME} ${CHECKER_NAME}

norm:		fclean
		echo "\n\n"
		${NORM_BIN} ${NORM_FLAGS} ${PUSH_SWAP_SRC} ${CHECKER_SRC}

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 10:27:38 by fvarrin           #+#    #+#              #
#    Updated: 2022/01/04 16:01:16 by fvarrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# DIRS
ROOT_DIR		?= $(shell pwd)
SRCS_DIR		= ${ROOT_DIR}/srcs/
SORT_SRC_DIR		= ${SRCS_DIR}sort/
STACK_SRC_DIR		= ${SRCS_DIR}stack/
CHECKER_SRC_DIR		= ${SRCS_DIR}checker/
HEADER_DIR		= ${ROOT_DIR}/includes/
LIBFT_DIR		= ${ROOT_DIR}/libft/
MLX_DIR			= ${ROOT_DIR}/minilibx/

# SRCS
SORT_SRC		= $(addprefix ${SORT_SRC_DIR}, main.c insert-sorted.c insert-empty.c \
			  sort-utils.c small-sort.c big-sort.c)
STACK_SRC		= $(addprefix ${STACK_SRC_DIR}, init.c push.c swap.c rotate.c \
			  reverse-rotate.c debug.c utils.c sorting-utils.c parse.c error.c \
		 	  instructions.c)
CHECKER_SRC		= $(addprefix ${CHECKER_SRC_DIR}, main.c instructions.c visualise.c draw.c init.c input.c)

# OBJS
SORT_OBJ		= $(SORT_SRC:.c=.o)
STACK_OBJ		= $(STACK_SRC:.c=.o)
CHECKER_OBJ		= $(CHECKER_SRC:.c=.o)

# NAMES
PUSH_SWAP_NAME 		= push_swap
CHECKER_NAME		= checker

# COMPILER
NORM_BIN		= norminette
NORM_FLAGS		= -RCheckForbiddenSourceHeader -RCheckDefine
RM			= rm -f
CFLAGS			= -Wall -Wextra -Werror -I${HEADER_DIR} -I${LIBFT_DIR}includes -I${LIBSTACK_DIR}includes -I${MLX_DIR} -g
CC			= gcc
LIBFT_FLAGS		= -L${LIBFT_DIR} -lft
MLX_FLAGS		= -L${MLX_DIR} -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd
PTHREAD_FLAGS		= -lpthread
CHECKER_FLAGS		= ${LIBFT_FLAGS} ${MLX_FLAGS} ${PTHREAD_FLAGS}

.PHONY:			all clean fclean re

all:			${PUSH_SWAP_NAME} ${CHECKER_NAME}

${PUSH_SWAP_NAME}:	${STACK_OBJ} ${SORT_OBJ}
			@make -C ${LIBFT_DIR} all || true
			${CC} ${CFLAGS} ${SORT_OBJ} ${STACK_OBJ} ${LIBFT_FLAGS} -o ${PUSH_SWAP_NAME}

${CHECKER_NAME}:	${STACK_OBJ} ${CHECKER_OBJ}
			@make -C --silent ${LIBFT_DIR} all || true
			@make -C ${MLX_DIR} all || true
			${CC} ${CFLAGS} ${CHECKER_OBJ} ${STACK_OBJ} ${CHECKER_FLAGS} -o ${CHECKER_NAME}

clean:
			${RM} ${STACK_OBJ}
			${RM} ${SORT_OBJ}
			${RM} ${CHECKER_OBJ}

fclean:			clean
			@make -C ${LIBFT_DIR} fclean || true
			@make -C ${MLX_DIR} clean || true
			${RM} ${PUSH_SWAP_NAME}
			${RM} ${CHECKER_NAME}

re:			fclean ${PUSH_SWAP_NAME} ${CHECKER_NAME}

norm:			fclean
			echo "\n\n"
			${NORM_BIN} ${NORM_FLAGS} ${STACK_SRC} ${SORT_SRC} ${CHECKER_SRC}

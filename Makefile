# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 13:34:19 by dbiguene          #+#    #+#              #
#    Updated: 2022/12/21 18:24:17 by gd-harco         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME			=	fdf.out

NAME_DEBUG		=	fdf_debug.out

# ---- Directories ---- #

DIR_OBJS		=	objs/

DIR_SRCS		=	srcs/

DIR_HEADERS		=	includes/

# ---- Files ---- #

HEADERS_LIST	=	fdf.h

SRCS			=	parsing/chained_to_array.c	\
					parsing/parsing.c			\
					parsing/text_to_list.c		\
					main.c

LIBFT			=	libft.a

LIBFT_DEBUG		=	libft_debug.a

FLAGS_FRAMEWORK	=	-Llib/mlx/linux -Llib/libft -lmlx -lft

MLX				=	libmlx.a

UNAME = $(shell uname)

# ---- Compil MacOS ---- #
ifeq (${UNAME}, Darwin)
OS				=	macos
FLAGS_FRAMEWORK	+=	-framework OpenGL -framework AppKit
endif

# ---- Compil Linux ---- #
ifeq (${UNAME}, Linux)
OS				=	linux
FLAGS_FRAMEWORK	+=	-lXext -lX11 -lm -lz
endif

MLX_DIR			=	lib/mlx/${OS}

HEADERS			=	${HEADERS_LIST:%.h=${DIR_HEADERS}%.h}

OBJS			=	${SRCS:%.c=${DIR_OBJS}%.o}

OBJS_DEBUG		=	${addprefix ${DIR_OBJS},${SRCS:.c=_debug.o}}

# ---- Compilation ---- #

CC				=	cc

FLAGS			=	-Wall -Wextra -Werror

FLAGS_DEBUG		=	-g3 -fsanitize=address

# ---- Commands ---- #

RM				=	rm -rf

MKDIR			=	mkdir -p

# ********* RULES ******** #

all:					${DIR_OBJS}
						@${MAKE} ${NAME}

debug:					${DIR_OBJS_DEBUG}
						@${MAKE} ${NAME_DEBUG} FLAGS="${FLAGS} ${FLAGS_DEBUG}"

# ---- Variables Rules ---- #

${NAME}:				${LIBFT} ${OBJS} ${DIR_HEADERS} ${MLX}
						${CC} ${FLAGS} -I ${DIR_HEADERS} ${OBJS} ${FLAGS_FRAMEWORK} -o ${NAME}

${NAME_DEBUG}:			${LIBFT_DEBUG} ${OBJS_DEBUG} ${MLX}
						${CC} ${FLAGS} -I ${DIR_HEADERS} ${FLAGS_FRAMEWORK} ${OBJS_DEBUG} ${LIBFT_DEBUG} -o ${NAME_DEBUG}

# ---- Compiled Rules ---- #

${DIR_OBJS}:
						@echo ${OBJS} | tr ' ' '\n'\
							| sed 's|\(.*\)/.*|\1|'\
							| sed 's/^/${MKDIR} /'\
							| sh -s
						@# Prints all OBJS. 1 per line
							@# Removes the .o file names
							@# Adds mkdir -p at start of each lines
							@# Executes the script (Creates all folders)

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEADERS}
					${CC} ${CFLAGS} -I ${DIR_HEADERS} -c $< -o $@

${DIR_OBJS}%_debug.o:	${DIR_SRCS}%.c ${DIR_HEADERS}
						${CC} ${FLAGS} -I ${DIR_HEADERS} -c $< -o $@

${LIBFT}:
						make -C lib/libft/

${LIBFT_DEBUG}:
						make -C lib/libft/ debug

${MLX}:
						make -C ${MLX_DIR}
${OBJS}:				| ${DIR_OBJS}


# ---- Usual Rules ---- #

clean:
					${RM} ${OBJS} ${OBJS_DEBUG} ${LIBFT} ${LIBFT_DEBUG} ${MLX}

fclean:				clean
					${RM} ${NAME} ${NAME_DEBUG}

re:					fclean all

.PHONY:	all clean fclean re

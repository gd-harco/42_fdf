# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 13:34:19 by gd-harco          #+#    #+#              #
#    Updated: 2023/01/04 15:52:34 by gd-harco         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME			=	fdf

NAME_DEBUG		=	fdf_debug

# ---- Directories ---- #

DIR_OBJS		=	bin/

DIR_SRCS		=	srcs/

DIR_HEADERS		=	includes/

# ---- Libs variables ---- #

LIBFT			=	libft.a

LIBFT_DEBUG		=	libft_debug.a

MLX				=	libmlx.a

# ---- Files ---- #

HEADERS_LIST	=	fdf.h		\
					libft.h		\
					mlx.h		\
					drawing.h	\
					graphics.h

SRCS_LIST		=	main.c								\
					parsing/chained_to_array.c			\
					parsing/parsing.c					\
					parsing/text_to_list.c				\
					graphics_renders/create_image.c		\
					graphics_renders/fill_info_struct.c	\
					graphics_renders/line_drawing.c		\
					graphics_renders/map_draw.c


HEADERS			=	${HEADERS_LIST:%.h=${DIR_HEADERS}%.h}

OBJS			=	${SRCS_LIST:%.c=${DIR_OBJS}%.o}


# ---- Compilation ---- #

UNAME = $(shell uname)

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

CFLAGS_DEBUG		=	-g3

FRAMEWORKS		=	-Llib/libft -lft

# ---- Compil MacOS ---- #
ifeq (${UNAME}, Darwin)
OS				=	macos
FRAMEWORKS		+=	-Llib/mlx/${OS} -lmlx -framework OpenGL -framework AppKit
endif

# ---- Compil Linux ---- #
ifeq (${UNAME}, Linux)
OS				=	linux
FRAMEWORKS		+=	 -lmlx -lXext -lX11 -lm -lz
endif

# ---- Commands ---- #

RM				=	rm -rf

MKDIR			=	mkdir -p

# ********* RULES ******** #

all				:	${NAME}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} ${LIBFT} ${MLX}
						${CC} ${CFLAGS} -I ${DIR_HEADERS} ${OBJS} ${FRAMEWORKS} -o ${NAME}

# ---- Lib rules ---- #

${LIBFT}		:
					make -C lib/libft

${MLX}			:
					make -C lib/mlx/${OS}

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c
					${CC} ${CFLAGS} -I ${DIR_HEADERS} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}
					${MKDIR} ${DIR_OBJS}parsing
					${MKDIR} ${DIR_OBJS}graphics_renders
					@echo "\033[0;32m [${NAME}/bin] : ✔️ Successfully created bin directory\033[1;36m ${DIR_OBJS} !\033[0;00m"

# ---- Usual Rules ---- #

clean			:
					${RM} ${OBJS}
					@echo "\033[0;31m [${NAME}/bin] : ✔️ Successfully cleaned bin directories\033[1;36m bin/ !\033[0;00m"

fclean:				clean
					${RM} ${NAME}
					make -C lib/libft/ clean
					make -C lib/mlx/${OS} clean

re:					fclean all

run:				${NAME}
					./fdf.out 42.fdf

.PHONY:	all clean fclean re

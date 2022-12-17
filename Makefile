# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 13:34:19 by dbiguene          #+#    #+#              #
#    Updated: 2022/12/17 16:00:42 by gd-harco         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME			=	fdf.out

NAME_DEBUG		=	fdf_debug.out

# ---- Directories ---- #

DIR_OBJS		=	bin/

DIR_SRCS		=	srcs/

DIR_HEADERS		=	includes/

# ---- Files ---- #

HEADERS_LIST	=	fdf.h

C_FILES			=	parsing/chained_to_array.c	\
					parsing/parsing.c			\
					parsing/text_to_list.c

LIBFT			=	libft.a

LIBFT_DEBUG		=	libft_debug.a

SRCS			= $(DIR_SRCS)$(C_FILES)

HEADERS			=	${HEADERS_LIST:%.h=${DIR_HEADERS}%.h}

OBJS			=	${SRCS:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC				=	cc

FLAGS			=	-Wall -Wextra -Werror

FLAGS_DEBUG		=	-g3 -fsanitize=address

# ---- Commands ---- #

RM				=	rm -rf

MKDIR			=	mkdir -p

# ********* RULES ******** #

all				: ${NAME}

debug			: ${NAME_DEBUG}

# ---- Variables Rules ---- #

${NAME}			:	${LIBFT} ${OBJS} ${HEADERS}
					${CC} ${CFLAGS} -I ${DIR_HEADERS}. ${OBJS} ${LIBFT} -o ${NAME}

${NAME_DEBUG}	:	${LIBFT_DEBUG} ${OBJS} ${HEADERS}

# ---- Compiled Rules ---- #

${LIBFT}		:
					make -C libft/
					mv libft/libft.a .

${LIBFT_DEBUG}	:
					make -C libft/ libft_debug
					mv libft/libft_debug.a .

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEADERS}
					${CC} ${CFLAGS} -I ${DIR_HEADERS}. -c $< -o $@

${DIR_OBJS}		:
					@echo ${OBJS} | tr ' ' '\n'\
						| sed 's|\(.*\)/.*|\1|'\
						| sed 's/^/${MKDIR} /'\
						| sh -s
					@echo "\033[0;32m [libft] ✔️ Successfully created binaries directories \033[1;36m${DIR_OBJS} !"

# ---- Usual Rules ---- #

clean			:
					${RM} ${OBJS}
					@echo "\033[0;31m [libft] ✔️ Successfully deleted binaries from directory \033[1;36m${DIR_OBJS} !"

fclean			:	clean
					${RM} ${NAME}
					@echo "\033[0;31m [libft] ✔️ Successfully deleted \033[1;36m${NAME} !"

re				:	fclean all
					@echo "\033[0;32m [libft] ✔️ Successfully re-compiled binaries and lib \033[0;36m${NAME} !"

test            :	all
					${CC} ${CFLAGS} -I ${DIR_HEADERS}. test.c ${NAME} -o test
					@echo "\033[0;32m [libft] ✔️ Successfully compiled \033[0;36mtest \033[0;32mprogram !"
					./test

.PHONY:	all clean fclean re
.SILENT:

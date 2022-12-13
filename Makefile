# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 13:34:19 by dbiguene          #+#    #+#              #
#    Updated: 2022/12/13 20:21:28 by gd-harco         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME			=	fdf.out

# ---- Directories ---- #

DIR_OBJS		=	bin/

DIR_SRCS		=	srcs/

DIR_HEADERS		=	includes/

# ---- Files ---- #

HEADERS_LIST	=	fdf.h

SRCS			=	parsing/parsing.c			parsing/text_to_chained.c

LIBFT			=	libft.a

HEADERS			=	${HEADERS_LIST:%.h=${DIR_HEADERS}%.h}

OBJS			=	${SRCS:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

# ---- Commands ---- #

RM				=	rm -rf

MKDIR			=	mkdir -p

# ********* RULES ******** #

all				: ${NAME}

# ---- Variables Rules ---- #

${NAME}			:	${LIBFT} ${OBJS} ${HEADERS}
					@echo "\033[0;32m [libft] ✔️ Binaries compiled from \033[1;36m${DIR_SRCS} \033[0;32mto \033[1;36m${DIR_OBJS} !"
					${CC} ${CFLAGS} -I ${DIR_HEADERS}. ${OBJS} ${LIBFT} -o ${NAME}
					@echo "\033[0;32m [libft] ✔️ Lib successfully built !"

# ---- Compiled Rules ---- #

${LIBFT}		:
					make -C libft/
					mv libft/libft.a .
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

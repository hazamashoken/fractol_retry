# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 00:32:16 by tliangso          #+#    #+#              #
#    Updated: 2022/10/13 22:35:05 by tliangso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### EXECUTABLE ###
NAME		= fractol


### DIR ###
DIRSRC		= src/
BONUS_SRC	= fractol_set/
HEAD		= include/
LIBFT_SRC	= libft/
SHARE_SRC	= ./

### TESTER GIT URL ###
TESTER1		=
TESTER2		=
TESTER3		=
TESTER4		=

### SOURCE FILE ###
SRC		=	fractol.c color.c hooks.c zoom.c utils.c color_utils.c \
			initiator.c render.c

BONUS	=	julia.c mandelbrot.c burning_ship.c tricorn.c mandelbox.c

SHARE	=

LIBFT	= libft.c libft2.c

### PATH ###
SRCS		= ${addprefix ${DIRSRC}, ${SRC}}
BONUS_SRCS	= ${addprefix ${BONUS_SRC}, ${BONUS}}
EXTRA_SRCS	= ${addprefix ${DIRSRC}, ${EXTRA}}
LIBFT_SRCS	= ${addprefix ${LIBFT_SRC}, ${LIBFT}}
SHARE_SRCS	= ${addprefix ${SHARE_SRC}, ${SHARE}}

### OBJECT FILE ###
OBJS		= ${SRCS:.c=.o}
BONUS_OBJS	= ${BONUS_SRCS:.c=.o}
EXRTA_OBJS	= ${EXTRA_SRCS:.c=.o}
LIBFT_OBJS	= ${LIBFT_SRCS:.c=.o}
SHARE_OBJS	= ${SHARE_SRCS:.c=.o}

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	MLX_DIR		= mlx_Linux
	MINILIBX_CC_FLAGS	= -Imlx_Linux -Lmlx_Linux -lmlx_Linux -lXext -lX11 -lm -lz
	MINILIBX_OBJ_FLAG 	= -I$(HEAD) \
						-I$(LIBFT_DIR) \
						-I/usr/include
	LIBS		= -L/usr/lib
else
	MLX_DIR		= mlx
	MINILIBX_CC_FLAGS	= -L$(MLX_DIR) -lmlx \
				  -framework OpenGL \
				  -framework AppKit
	MINILIBX_OBJ_FLAG 	= -I$(HEAD) \
						-I$(MLX_DIR)
endif

### COMPILATION ###
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -g


### COLORS ###
NOC		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m

### TMP ###
ARGS = 60
MSG = Upload to git

### RULES ###
.c.o:
	@$(CC) ${CFLAGS} -D MAXINTER=${ARGS} ${MINILIBX_OBJ_FLAG} -c $< -o $@
	@echo "$(BLUE)clang $(WHITE)$(notdir $@)$(NOC)"

all: ${NAME} print_option


${NAME}:	${OBJS} ${LIBFT_OBJS} ${SHARE_OBJS} ${BONUS_OBJS}

	@${CC} ${CFLAGS} ${OBJS} ${LIBFT_OBJS} ${SHARE_OBJS} ${BONUS_OBJS} ${MINILIBX_CC_FLAGS} -o ${NAME}
	@echo "$(GREEN)$@$(NOC)"

bonus:		${BONUS_OBJS} ${LIBFT_OBJS} ${SHARE_OBJS}
	@${CC} ${CFLAGS} -o ${BONUS_NAME} ${BONUS_OBJS} ${LIBFT_OBJS} ${SHARE_OBJS}
	@echo "$(GREEN)${BONUS_NAME}$(NOC)"

extra:	${OBJS} ${BONUS_OBJS} ${EXRTA_OBJS} ${LIBFT_OBJS}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${BONUS_OBJS} ${EXRTA_OBJS} ${LIBFT_OBJS}

clean:
	@echo "$(RED)clean$(NOC)"
	@${RM} ${OBJS} ${BONUS_OBJS} ${EXRTA_OBJS} ${LIBFT_OBJS} ${SHARE_OBJS}

fclean: clean
	@echo "$(RED)fclean$(NOC)"
	@${RM} ${NAME} ${BONUS_NAME}

re: fclean	all

print_option:
	@echo "$(YELLOW)You can use 'make ARGS=(number) re' to set max iteration for the fractols.$(NOC)"
	@echo "$(YELLOW)ARGS need to be an int between 1 and 100 else it will default to 60.$(NOC)"

tester:
	@echo "$(YELLOW)Testers are not perfect but its good enough$(NOC)"
	git clone ${TESTER1} TESTER1
	git clone ${TESTER2} TESTER2
	git clone ${TESTER3} TESTER3
	git clone ${TESTER3} TESTER4

norm:
	norminette

gitpush:
	git add .
	git status
	git commit -m "${MSG}"
	git push

help:
	@clear
	@echo "$(GREEN)Avaibles options:$(NOC)"
	@echo "$(RED)==================$(NOC)"
	@echo "$(RED)| $(YELLOW)make ${NAME} $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make bonus     $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make norm      $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make tester    $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make clean     $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make fclean    $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make re        $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make help      $(RED)|$(NOC)"
	@echo "$(RED)==================$(NOC)"

.PHONY:		all	clean	fclean	re bonus norm gitpush tester help print_option

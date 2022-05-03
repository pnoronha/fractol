# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 21:12:28 by pnoronha          #+#    #+#              #
#    Updated: 2022/05/03 15:20:41 by pnoronha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

CC			=	gcc
CFLAGS		=	-O3 -Wall -Wextra -Werror
LINKS		=	-lmlx -lm -Llibft -lft -framework OpenGL -framework AppKit
INC			=	-Iincludes -Ilibft/includes -Imac
RM			=	rm -f

SRC			=	main.c			\
				render.c		\
				color.c		\
				keys_ctrl.c		\
				mouse_ctrl.c	\
				err_ret.c		\
				mandelbrot.c	\
				julia.c

OBJ			:=	$(SRC:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJ) | libft
				@$(CC) $(CFLAGS) $^ $(LINKS) -o $@

%.o: %.c
				@$(CC) $(CFLAGS) $(INC) -c $^ -o $@

norm:
				@norminette -R CheckForbiddenSourceHeader $(SRC)
				@norminette -R CheckDefine includes/*

test:
				valgrind --tool=memcheck --leak-check=yes --show-reachable=yes \
				--num-callers=20 --track-fds=yes ./$(NAME)

libft:
				@$(MAKE) -C libft

clean:
				@$(MAKE) clean -C libft
				@$(RM) $(OBJ)

fclean:		clean
				@$(MAKE) fclean -C libft
				@$(RM) $(NAME)

re:			fclean all

.PHONY : 	all clean fclean re norm test libft

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 21:12:28 by pnoronha          #+#    #+#              #
#    Updated: 2022/03/14 22:30:05 by pnoronha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

CC			=	gcc
CFLAGS		=	-O3 -Wall -Wextra -Werror
LINKS		=	-lmlx -lm -Llibft -lft -framework OpenGL -framework AppKit
INC			=	-Iincludes -Ilibft -Imac

SRC_PATH	=	sources
OBJ_PATH	=	objects
SRC			=	$(SRC_PATH)/fractol.c

OBJ			:=	$(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(SRC))
RM			=	rm -f

all:			$(NAME)

$(NAME):	$(OBJ) | obj_dir norm libft
				@$(CC) $(CFLAGS) $< $(LINKS) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
				@$(CC) $(CFLAGS) $(INC) -c $^ -o $@

obj_dir:
				@mkdir $(OBJ_PATH)

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
				@$(RM) -d $(OBJ_PATH)

fclean:		clean
				@$(MAKE) fclean -C libft
				@$(RM) $(NAME)

re:			fclean all

.PHONY : 	all clean fclean re norm test libft

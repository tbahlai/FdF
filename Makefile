#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/01 10:22:23 by tbahlai           #+#    #+#              #
#    Updated: 2019/02/01 10:22:24 by tbahlai          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME    = fdf

SRC     = src/main.c \
			src/drawer_line.c \
			src/fdf_drawer.c \
			src/effects.c \
			src/menu.c \
			src/reader.c \
			src/rotate.c

OBJ     = $(SRC:.c=.o)
LIBFT   = lib/
HDR  = includes/fdf.h 
CC      = /usr/bin/gcc
CFLAGS  = -Wall -Wextra -Werror
FMLX    = -framework OpenGL -framework AppKit -lmlx
DEL      = /bin/rm -f

all:        $(NAME)

$(NAME):    $(OBJ) $(LIBFT)
	@make -C $(LIBFT)	
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I $(HDR) -L $(LIBFT)  -lft $(FMLX)
	@echo "\x1b[32m -->> Compilation Success: fdf"

%.o : %.c $(HDR) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ -c $< -I .

clean:
	@make fclean -C $(LIBFT)
	@$(DEL) $(OBJ)
	@echo "\x1b[32m -->> Object files are deleted"

fclean:     clean
	@make -C $(LIBFT) fclean
	@$(DEL) $(NAME)
	@echo "\x1b[32m -->> FDF was deleted"


re:     fclean all

.PHONY:     re all clean fclean



	
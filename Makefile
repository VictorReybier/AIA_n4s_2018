##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME =	ai

OBJ	=	$(SRC:.c=.o)

SRC	=	source/ia.c	\
		source/lib.c	\
		source/format.c	\
		source/turns.c	\
		source/end.c

CFLAGS = -g -I include/

$(NAME):	$(OBJ)
		gcc $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
		rm -f *.o

fclean:	clean
		rm -rf $(NAME)

re:		fclean all

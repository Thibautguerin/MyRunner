##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile struct
##

SRC	=	src/main.c	\
		src/readfile.c	\
		src/manual.c	\
		src/event.c	\
		src/move.c	\
		src/display.c	\
		src/destroy.c	\
		src/init.c	\
		src/put_in_list.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(SRC)
	gcc $(SRC)-o $(NAME) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -Iinclude -Llib/my -lmy

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur

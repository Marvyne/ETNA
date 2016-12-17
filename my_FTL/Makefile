##
## Makefile for Makefile in 
## 
## Made by TOKPAHOLOU Marvyne
## Login   <tokpah_m@etna-alternance.net>
## 
## Started on  Mon Oct 24 20:07:33 2016 TOKPAHOLOU Marvyne
## Last update Sat Nov 12 09:53:27 2016 TOKPAHOLOU Marvyne
##

CC	=	gcc

NAME	=	my_ftl

SRC	=	main.c		\
		air_shed.c	\
		container.c	\
		system_control.c\
		system_repair.c	\
		readline.c	\
		game.c		\
		my_string.c	\
		ennemis.c	\
		my_put_nbr.c	\
		fonction.c	\
		command.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -f

$(NAME):	$(OBJ)
		$(CC) -g $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all


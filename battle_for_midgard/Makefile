##
## Makefile for Makefile in /home/marvyne/repertoire_rendu/C/battle_for_midgard/tokpah_m/src
## 
## Made by TOKPAHOLOU Marvyne
## Login   <tokpah_m@etna-alternance.net>
## 
## Started on  Mon Dec  5 16:28:47 2016 TOKPAHOLOU Marvyne
## Last update Fri Dec  9 11:21:43 2016 TOKPAHOLOU Marvyne
##

CC	=	gcc -g

NAME	=	sta

SRC	=	src/main.c		\
		src/my_putmsg.c		\
		src/init_bag.c		\
		src/my_string2.c	\
		src/readline.c		\
		src/getCreature.c	\
		src/monster.c		\
		src/my_command.c	\
		src/my_command2.c	\
		src/magic_catch.c	\
		src/my_command3.c	\
		src/gamble.c		\
		src/my_command4.c	\
		src/attack_monster.c	\
		src/magic_msg.c		\
		src/free_me.c		\
		src/ajoutadd.c		\
		src/reduc_cmd2.c	\
		src/my_cmd5.c		\
		src/my_cmd6.c		\
		src/my_cmd7.c		\
		src/sdl.c		\
		src/sdl2.c		\
		src/sdl3.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

LDFLAGS =	-L. -lmy

RM	=	rm -f

$(NAME):	$(OBJ)
		$(CC) -g $(OBJ) -o $(NAME) $(LDFLAGS) -lSDL

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all


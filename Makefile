##
## Makefile for ms in /home/baurens/Work/Tek1/Projects/CPE/CPE_2016_matchstick/
##
## Made by Arthur Baurens
## Login   <arthur.baurens@epitech.eu>
##
## Started on  Mon Feb 20 12:05:50 2017 Arthur Baurens
## Last update Thu Feb 23 18:31:23 2017 Arthur Baurens
##


CC		=		gcc

NAME	=		matchstick

SRC		=		ia.c							\
					main.c						\
					game.c						\
					random.c					\
					p_string.c				\
					get_next_line.c		\
					memory_gestioner.c

OBJ		=		$(SRC:.c=.o)

INCLUDE	=	-I./include

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

CFLAGS	+=	$(INCLUDE) -g -W -Wall -Wextra -pedantic

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

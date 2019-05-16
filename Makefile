##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## N4S
##

NAME	= ai

CC	= gcc

RM	= rm -f

SRCS	= ./src/main.c	\
			./src/average.c	\
			./src/end_track.c	\
			./src/speed_car.c	\
			./src/turn_car.c	\
		  ./src/str_to_word_array.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I 
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

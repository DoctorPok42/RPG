##
## EPITECH PROJECT, 2023
## navy
## File description:
## Makefile
##

SRC = src/main.c \
	src/utils/error.c \
	src/start_game.c \
	src/change_map.c \
	$(addprefix src/utils/create/, \
		$(addsuffix .c, \
			index \
			start_menu \
			window \
			option \
			map \
			perso \
		) \
	) \
	$(addprefix src/utils/display/, \
		$(addsuffix .c, \
			index \
			window \
			start_menu \
			change_to_game \
			perso \
		) \
	) \
	$(addprefix src/utils/events/, \
		$(addsuffix .c, \
			index \
		) \
	) \
	src/utils/actions.c \
	src/utils/collisions.c \
	# src/utils/menu/start/create.c \
	# src/utils/menu/start/display/main.c \
	# src/utils/menu/start/display/settings.c \
	# src/utils/menu/start/events.c \
	# src/utils/menu/game/create.c \
	# src/utils/menu/game/events.c \
	# src/utils/menu/game/display/main.c \
	# src/utils/menu/game/display/perso.c	\
	# src/utils/menu/game/display/player_move.c	\

OBJ = $(SRC:.c=.o)

CFLAGS = -I include/ -Wall -Wextra -lcsfml-graphics -lcsfml-window \
		-lcsfml-system -lcsfml-audio

NAME = my_rpg

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

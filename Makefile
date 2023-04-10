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
			dialog \
		) \
	) \
	$(addprefix src/utils/display/, \
		$(addsuffix .c, \
			index \
			window \
			start_menu \
			change_to_game \
			perso \
			dialog \
		) \
	) \
	$(addprefix src/utils/events/, \
		$(addsuffix .c, \
			index \
		) \
	) \
	src/utils/actions.c \
	src/utils/collisions.c

OBJ = $(SRC:.c=.o)

CFLAGS = -I include/ -Wall -Wextra -lcsfml-graphics -lcsfml-window \
		-lcsfml-system -lcsfml-audio

NAME = my_rpg

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)
	@if [ -f $(NAME) ]; then \
		echo "\033[1;32mCompilation done\033[0m"; \
	fi

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

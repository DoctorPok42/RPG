##
## EPITECH PROJECT, 2023
## rpg
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
			options/navbar \
			options/fps \
			options/music \
			options/keyboard \
			options/window \
			inventory \
			overlay \
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
			option \
			options/music \
			options/fps \
			options/keyboard \
			options/window \
			options/actions \
			inventory \
			overlay \
			map_iso \
		) \
	) \
	$(addprefix src/utils/events/, \
		$(addsuffix .c, \
			index \
			keys \
			inventory \
			zoom \
		) \
	) \
	src/utils/actions.c \
	src/utils/collisions.c \
	$(addprefix src/utils/functions/, \
		$(addsuffix .c, \
			my_strcmp \
			my_len \
			my_str_to_word_array \
			my_strndup \
			my_getnbr \
		) \
	) \

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

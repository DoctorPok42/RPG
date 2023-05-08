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
			clients \
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
			save \
			go_back \
			inventory \
			overlay \
			menu \
			menu/sidebar \
			menu/character \
			menu/quest \
			mobs \
			npc \
			end \
		) \
	) \
	$(addprefix src/save/, \
		$(addsuffix .c, \
			load_save \
			write_save \
			save \
			open_file \
			tab_handling \
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
			save \
			go_back \
			inventory_bar \
			overlay \
			menu \
			menu/inventory \
			menu/actions \
			menu/character \
			menu/quest \
			map_iso \
			clients \
			mobs \
			npc \
			end \
		) \
	) \
	$(addprefix src/utils/events/, \
		$(addsuffix .c, \
			index \
			inventory \
			zoom \
			menu \
		) \
	) \
	$(addprefix src/utils/mobs/, \
		$(addsuffix .c, \
			manage_mobs \
			set_vector_speed \
			movement \
		) \
	) \
	src/utils/actions.c \
	src/utils/collisions.c \
	$(addprefix src/utils/functions/, \
		$(addsuffix .c, \
			free \
			free2 \
			put_nbr \
			put_nb_float \
			my_strcmp \
			my_len \
			my_str_to_word_array \
			my_strndup \
			my_getnbr \
			my_itoa \
			my_strcat \
		) \
	) \
	$(addprefix src/utils/network/, \
		$(addsuffix .c, \
			connection \
			communication \
		) \
	) \

OBJ = $(SRC:.c=.o)

CFLAGS = -I include/ -Wall -Wextra -lcsfml-graphics -lcsfml-window \
		-lcsfml-system -lcsfml-audio -lcsfml-network \
		-lcsfml-system -lcsfml-audio -lm

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

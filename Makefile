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
	src/flags.c \
	src/menu.c \
	src/input.c \
	$(addprefix src/utils/create/, \
		$(addsuffix .c, \
			raycasting \
			raycasting_entities \
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
			get_map \
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
	$(addprefix src/utils/raycasting/, \
		$(addsuffix .c, \
			calculate_entity \
			define_wall \
			move \
			raycasting \
			sort_walls \
			get_wall \
			map_access \
		) \
	) \

OBJ = $(SRC:.c=.o)

CFLAGS = -I include/ -I/opt/homebrew/opt/csfml/include \
		-I/opt/homebrew/include -I/usr/local/include \
		-Wall -Wextra

LDFLAGS = -L/opt/homebrew/opt/csfml/lib -L/opt/homebrew/lib \
		-L/usr/local/lib

LDLIBS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio \
		-lcsfml-network -lm

NAME = my_rpg

TEST_SRC = $(wildcard tests/*.c)
TEST_NAME = unit_tests
SANITIZE = -g3 -fsanitize=address,undefined
TEST_BUILD = gcc -o $(TEST_NAME) $(filter-out src/main.c, $(SRC)) \
		$(TEST_SRC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -lcriterion

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(TEST_NAME)

re: fclean all

debug: CFLAGS += $(SANITIZE)
debug: LDLIBS += -fsanitize=address,undefined
debug: re

tests_run:
	$(TEST_BUILD)
	./$(TEST_NAME)

tests_asan:
	$(TEST_BUILD) $(SANITIZE)
	./$(TEST_NAME)

valgrind:
	$(TEST_BUILD)
	valgrind --leak-check=full --error-exitcode=1 ./$(TEST_NAME)

.PHONY: all clean fclean re debug tests_run tests_asan valgrind

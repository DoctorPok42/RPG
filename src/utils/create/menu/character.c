/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** character
*/

#include "game.h"

char *my_itoa(int nb);

static void create_text(char *name, char *value, game_t *game,
    int i)
{
    sfText **name_text = game->game_menu->character->name;
    sfText **value_text = game->game_menu->character->value;
    sfFont *font = sfFont_createFromFile("assets/fonts/dialog.ttf");
    sfText_setString(name_text[i], name);
    sfText_setString(value_text[i], value);
    sfText_setFont(name_text[i], font);
    sfText_setFont(value_text[i], font);
    sfText_setCharacterSize(name_text[i], 30);
    sfText_setCharacterSize(value_text[i], 30);
    sfText_setColor(name_text[i], sfWhite);
    sfText_setColor(value_text[i], sfWhite);
    sfText_setPosition(name_text[i],
        (sfVector2f){game->params->window_size.x / 2 + 160,
        game->params->window_size.y / 2 - 150 + (i * 50)});
    sfText_setPosition(value_text[i],
        (sfVector2f){game->params->window_size.x / 2 + 410,
        game->params->window_size.y / 2 - 150 + (i * 50)});
}

void create_character(game_t *game)
{
    game->game_menu->character = malloc(sizeof(character_t));
    game->game_menu->character->name = malloc(sizeof(sfText *) * 7);
    game->game_menu->character->value = malloc(sizeof(sfText *) * 7);
    game->game_menu->character->name[6] = NULL;
    game->game_menu->character->value[6] = NULL;
    char *names[6] =
        {"NAME", "ATTACK", "DEFENSE", "STRENGTH", "SPEED", "LEVEL"};
    char *values[6] = {game->perso->name, my_itoa(game->perso->combat->attack),
        my_itoa(game->perso->combat->defense),
        my_itoa(game->perso->combat->strength),
        my_itoa(game->perso->combat->speed),
        my_itoa(game->perso->combat->level)};

    for (int i = 0; i < 6; i++) {
        game->game_menu->character->name[i] = sfText_create();
        game->game_menu->character->value[i] = sfText_create();
        create_text(names[i], values[i], game, i);
    }
}

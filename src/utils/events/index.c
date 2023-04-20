/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** index
*/

#include <SFML/System/Vector2.h>
#include <math.h>

#include "game.h"

void exit_start_all(game_t *game);
void zoom(game_t *game);
void change_item(game_t *game);

void go_to_raycasting (game_t *game)
{
    sfVector2f player_pos = (sfVector2f) {game->perso->pos.x + (game->map->rect.
    left * 3), game->perso->pos.y + (game->map->rect.top * 3)};

    sfVector2f room_pos = (sfVector2f) {2400, 4218};

    float diff = sqrt(pow(player_pos.x - room_pos.x, 2) + pow(player_pos.y -
    room_pos.y, 2));

    if (diff < 30) {
        game->perso->pos.y += 100;
        game->raycasting->selected_map = 0;
        game->is_raycasting = true;
    }
}

void events_window(game_t *game)
{
    go_to_raycasting(game);

    while (sfRenderWindow_pollEvent(game->window->window,
        &game->window->event)) {
        if (game->window->event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape)) {
            exit_start_all(game);
        }

        zoom(game);
        change_item(game);
    }
}

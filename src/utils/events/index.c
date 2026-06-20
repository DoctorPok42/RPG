/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** index
*/

#include <math.h>

#include "game.h"
#include "events.h"
#include "input.h"

static void go_to_raycasting(game_t *game)
{
    sfVector2f player_pos = {game->perso->pos.x
        + game->map->rect.position.x * 3, game->perso->pos.y
        + game->map->rect.position.y * 3};
    sfVector2f room_pos = {2400, 4218};
    float diff = sqrt(pow(player_pos.x - room_pos.x, 2)
        + pow(player_pos.y - room_pos.y, 2));

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
        input_handle_event(game);
        if (game->window->event.type == sfEvtClosed)
            exit_start_all(game);
        if (game->window->event.type == sfEvtKeyPressed
            && game->window->event.key.code == sfKeyEscape)
            event_menu(game);
        zoom(game);
        change_item(game);
    }
}

/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** music
*/

#include "game.h"

static void set_volume(game_t *game, sfVector2i mouse, sfVector2f pos)
{
    game->params->volume = ((mouse.x - pos.x) / 4.83 < 100 &&
        (mouse.x - pos.x) / 4.83 > 0) ? (mouse.x - pos.x) / 4.83 :
        game->params->volume;

    sfRectangleShape_setSize(game->params->visu->music->bar,
        (sfVector2f){(game->params->volume * 4.83), 35});

    sfMusic_setVolume(game->window->song->music, game->params->volume);
}

void display_music(game_t *game)
{
    if (game->menu != 21)
        return;
    music_t *music = game->params->visu->music;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window->window);
    sfVector2f pos = sfRectangleShape_getPosition(music->bar);
    if (mouse.x >= pos.x && mouse.x <= pos.x + 500 && mouse.y >= pos.y &&
        mouse.y <= pos.y + 50) {
        sfRectangleShape_setFillColor(music->bar,
            (sfColor){25, 118, 210, 150});
        (sfMouse_isButtonPressed(sfMouseLeft)) ? set_volume(game, mouse, pos) :
            0;
    } else
        sfRectangleShape_setFillColor(music->bar,
            (sfColor){25, 118, 210, 100});
    sfRenderWindow_drawRectangleShape(game->window->window,
        music->container, NULL);
    sfRenderWindow_drawRectangleShape(game->window->window, music->bar, NULL);
}

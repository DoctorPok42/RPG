/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** music
*/

#include "game.h"
#include "display.h"
#include "menu.h"

static void set_volume(game_t *game, const sfVector2i *mouse,
    const sfVector2f *pos)
{
    float vol = (mouse->x - pos->x) / 4.83;

    if (vol < 100 && vol > 0)
        game->params->volume = vol;
    sfRectangleShape_setSize(game->params->visu->music->bar,
        (sfVector2f){game->params->volume * 4.83, 35});
    sfMusic_setVolume(game->window->song->music, game->params->volume);
}

void display_music(game_t *game)
{
    music_t *music = game->params->visu->music;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window->window);
    sfVector2f pos = sfRectangleShape_getPosition(music->bar);

    if (!menu_tab_music(game))
        return;
    if (mouse.x >= pos.x && mouse.x <= pos.x + 500 && mouse.y >= pos.y
        && mouse.y <= pos.y + 50) {
        sfRectangleShape_setFillColor(music->bar,
            (sfColor){25, 118, 210, 150});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            set_volume(game, &mouse, &pos);
    } else
        sfRectangleShape_setFillColor(music->bar,
            (sfColor){25, 118, 210, 100});
    sfRenderWindow_drawRectangleShape(game->window->window,
        music->container, NULL);
    sfRenderWindow_drawRectangleShape(game->window->window, music->bar, NULL);
}

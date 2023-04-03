/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** settings
*/

#include "rpg.h"
#include "lists.h"

void create_start_settings(game_t *game)
{
    menu_t *menu = game->menu[0]; sfVector2u size = menu->window_size;
    menu->set = malloc(sizeof(settings_t *) * 3);
    menu->set[0] = malloc(sizeof(settings_t));
    menu->set[0]->container = sfRectangleShape_create();
    sfRectangleShape_setSize(menu->set[0]->container, (sfVector2f){500, 50});
    sfRectangleShape_setPosition(menu->set[0]->container,
        (sfVector2f){(size.x / 4.5) - 250, (size.y / 2) - 250});
    sfRectangleShape_setFillColor(menu->set[0]->container, (sfColor)
        {62, 39, 35, 255}); sfRectangleShape_setOutlineColor(
        menu->set[0]->container, (sfColor){46, 29, 26, 255});
    sfRectangleShape_setOutlineThickness(menu->set[0]->container, 5);
    menu->set[0]->pos = sfRectangleShape_getPosition(menu->set[0]->container);
    menu->set[1] = malloc(sizeof(settings_t)); menu->set[1]->container =
        sfRectangleShape_create(); sfRectangleShape_setSize(
        menu->set[1]->container, (sfVector2f){(game->volume * 4.83), 35});
    sfRectangleShape_setPosition(menu->set[1]->container,
        (sfVector2f){(size.x / 4.4) - 250, (size.y / 2 - 250) + 8.5});
    sfRectangleShape_setFillColor(menu->set[1]->container,
        (sfColor){95, 59, 53, 255});
    menu->set[1]->pos = sfRectangleShape_getPosition(menu->set[1]->container);
}

static void display_music(game_t *game, sfVector2i mpos)
{
    menu_t *menu = game->menu[0]; for (int i = 0; i < 2; i++) {
        sfVector2f pos = menu->set[i]->pos; if (mpos.x >= pos.x &&
            mpos.x <= pos.x + 500 && mpos.y >= pos.y && mpos.y <= pos.y + 50) {
            sfRectangleShape_setOutlineColor(menu->set[i]->container, (sfColor)
            {255, 255, 255, 255}); (sfMouse_isButtonPressed(sfMouseLeft)) ?
                sfRectangleShape_setFillColor(menu->set[1]->container,
                (sfColor){32, 58, 62, 255}),
                game->volume = ((mpos.x - pos.x) / 4.83 < 100 &&
                    (mpos.x - pos.x) / 4.83 > 0) ? (mpos.x - pos.x) / 4.83 :
                    game->volume,
                sfRectangleShape_setSize(menu->set[1]->container,
                (sfVector2f){(game->volume * 4.8), 35}),
                sfMusic_setVolume(menu->song->music, game->volume) : 0;
        } else { sfRectangleShape_setOutlineColor(menu->set[i]->container,
                (sfColor){46, 29, 26, 255});
            sfRectangleShape_setFillColor(menu->set[1]->container,
                (sfColor){95, 59, 53, 255});
        } sfRenderWindow_drawRectangleShape(menu->window,
            menu->set[i]->container, NULL);
    }
}

void display_start_settings(game_t *game, menu_t *menu)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(menu->window);
    sfRenderWindow_setTitle(menu->window, "Settings | RPG");
    sfRenderWindow_clear(menu->window, (sfColor){62, 39, 35, 255});
    display_music(game, mpos);
    sfRenderWindow_display(menu->window);
}

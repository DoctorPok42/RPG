/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** settings
*/

#include "rpg.h"
#include "lists.h"

void go_back(menu_t *menu);

void create_button(menu_t *menu)
{
    menu->button = malloc(sizeof(button_t *) * 1);
    menu->button[0] = malloc(sizeof(button_t));
    menu->button[0]->texture = sfTexture_createFromFile(
        "assets/imgs/button.png", NULL);
    menu->button[0]->sprite = sfSprite_create();
    sfSprite_setTexture(menu->button[0]->sprite, menu->button[0]->texture,
        sfTrue);
    sfSprite_setPosition(menu->button[0]->sprite,
        (sfVector2f){50, 50});
    menu->button[0]->pos = (sfVector2f){50, 50};
    menu->button[0]->rect_text = (sfIntRect){0, 400, 100, 105};
    menu->button[0]->callback = (void *)&go_back;
}

void create_start_settings(game_t *game)
{
    menu_t *menu = game->menu[0]; sfVector2u size = game->window_size;
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
            {255, 255, 255, 100}); (sfMouse_isButtonPressed(sfMouseLeft)) ?
                sfRectangleShape_setFillColor(menu->set[1]->container,
                (sfColor){48, 63, 159, 255}),
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

static void display_buttons(menu_t *menu, sfVector2i mpos)
{
        sfVector2f pos = menu->button[0]->pos;
        if (mpos.x >= pos.x && mpos.x <= pos.x + 225 && mpos.y >= pos.y &&
            mpos.y <= pos.y + 105) {
            sfSprite_setTextureRect(menu->button[0]->sprite,
                (sfIntRect){111, 440, 100, 105});
            (sfMouse_isButtonPressed(sfMouseLeft)) ?
                go_back(menu) : 0;
        } else {
            sfSprite_setTextureRect(menu->button[0]->sprite,
                (sfIntRect){0, 440, 110, 105});
        }
        sfRenderWindow_drawSprite(menu->window, menu->button[0]->sprite, NULL);
}

void display_start_settings(game_t *game, menu_t *menu)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(menu->window);
    sfRenderWindow_setTitle(menu->window, "Settings | RPG");
    sfRenderWindow_clear(menu->window, (sfColor){121, 85, 72, 255});
    display_music(game, mpos);
    display_buttons(menu, mpos);
    sfRenderWindow_display(menu->window);
}

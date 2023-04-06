/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** main
*/

#include "lists.h"

void display_perso(game_t *game);

void create_game_all(game_t *game)
{
    menu_t *menu = game->menu[1];
    menu->rect = malloc(sizeof(sfRectangleShape *) * 2);
    menu->rect[0] = sfRectangleShape_create();
    sfRectangleShape_setSize(menu->rect[0], (sfVector2f){
        game->window_size.x * 3, game->window_size.y * 3
    });
    sfTexture *texture =
        sfTexture_createFromFile("assets/imgs/map.png", NULL);
    sfRectangleShape_setTexture(menu->rect[0], texture, sfTrue);
    menu->perso->texture = sfTexture_createFromFile(
        "assets/imgs/perso.png", NULL);
    menu->perso->sprite = sfSprite_create();
    sfSprite_setTexture(menu->perso->sprite, menu->perso->texture, sfTrue);
    sfSprite_setPosition(menu->perso->sprite, (sfVector2f){0, 0});
    menu->perso->rect = (sfIntRect){0, 0, 70, 85};
    sfSprite_setTextureRect(menu->perso->sprite, menu->perso->rect);
    sfSprite_setScale(menu->perso->sprite, (sfVector2f){0.5, 0.5});
}

void display_game_all(game_t *game)
{
    menu_t *menu = game->menu[1];
    sfRenderWindow_clear(menu->window, sfBlack);
    sfRenderWindow_drawRectangleShape(menu->window, menu->rect[0], NULL);
    display_perso(game);
    sfView_zoom(menu->view, 1.1);
    sfRenderWindow_display(menu->window);
}

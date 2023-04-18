/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** menu
*/

#include "game.h"

void create_sidebar(game_t *game);
void create_character(game_t *game);
void display_charracter(game_t *game);

static void create_background(game_t *game, game_menu_t *game_menu)
{
    game_menu->container = sfRectangleShape_create();
    sfRectangleShape_setSize(game_menu->container, (sfVector2f){
        game->params->window_size.x, game->params->window_size.y});
    sfRectangleShape_setPosition(game_menu->container, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(game_menu->container,
        sfColor_fromRGBA(0, 0, 0, 100));
    game_menu->content = sfRectangleShape_create();
    sfRectangleShape_setSize(game_menu->content, (sfVector2f){
        game->params->window_size.x / 1.5, game->params->window_size.y / 1.5});
    sfRectangleShape_setPosition(game_menu->content, (sfVector2f){
        game->params->window_size.x / 6.5, game->params->window_size.y / 6.5});
    sfRectangleShape_setFillColor(game_menu->content,
        sfColor_fromRGBA(85, 61, 51, 255));
}

void create_menu(game_t *game)
{
    game->game_menu = malloc(sizeof(game_menu_t));
    create_background(game, game->game_menu);

    create_sidebar(game);
    create_character(game);
}

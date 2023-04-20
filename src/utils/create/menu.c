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
void create_quest(game_t *game);
int my_strlen(char *str);

sfText *create_text(char *txt, sfVector2f pos, sfFont *font, int size)
{
    sfText *text = sfText_create();
    sfText_setString(text, txt);
    sfText_setPosition(text, pos);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    return (text);
}

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
    game->game_menu->title = malloc(sizeof(sfText *) * 4);
    game->game_menu->font = sfFont_createFromFile("assets/fonts/dialog.ttf");
    char *title[4] = {"INVENTORY", "CHARACTER", "QUEST", NULL};
    for (int i = 0; title[i] != NULL; i++) {
        game->game_menu->title[i] = malloc(sizeof(sfText *));
        game->game_menu->title[i] = create_text(title[i],
            (sfVector2f){game->params->window_size.x / 2.8,
            game->params->window_size.y / 5}, game->game_menu->font, 50);
    }
    create_sidebar(game);
    create_character(game);
    create_quest(game);
}

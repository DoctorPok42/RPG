/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** quest
*/

#include "game.h"

char *my_itoa(int nb);
char *my_strcat(char *str1, char *str2);

void modify_quest(game_t *game)
{
    if (game->game_menu->quest->nb_achievement !=
        game->game_menu->quest->nb_achievement_second &&
        game->game_menu->quest->nb_achievement_second < 3) {
        sfRectangleShape_setSize(game->game_menu->quest->bar,
            (sfVector2f){game->game_menu->quest->size.x *
            game->game_menu->quest->nb_achievement / 3 - 20,
            game->game_menu->quest->size.y - 10});
        char *str = my_strcat(my_itoa(game->game_menu->quest->nb_achievement),
            "-3");
        sfText_setString(game->game_menu->quest->achievement, str);
        game->game_menu->quest->nb_achievement_second =
            game->game_menu->quest->nb_achievement;
    }
}

void display_quest(game_t *game)
{
    if ((game->menu / 10) % 10 != 6 || (game->menu % 10) != 2)
        return;

    sfRenderWindow_drawRectangleShape(game->window->window,
        game->game_menu->quest->container, NULL);
    sfRenderWindow_drawRectangleShape(game->window->window,
        game->game_menu->quest->bar, NULL);
    sfRenderWindow_drawRectangleShape(game->window->window,
        game->game_menu->quest->content, NULL);
    sfRenderWindow_drawText(game->window->window,
        game->game_menu->quest->achievement, NULL);

    sfRenderWindow_drawText(game->window->window,
        game->game_menu->title[2], NULL);

    modify_quest(game);
}

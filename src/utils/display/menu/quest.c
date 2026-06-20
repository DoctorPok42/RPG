/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** quest
*/

#include <stdlib.h>

#include "game.h"
#include "display.h"
#include "my_str.h"
#include "menu.h"

static void modify_quest(game_t *game)
{
    quest_t *quest = game->game_menu->quest;
    char *num = NULL;
    char *str = NULL;

    if (quest->nb_achievement == quest->nb_achievement_second
        || quest->nb_achievement_second >= 3)
        return;
    sfRectangleShape_setSize(quest->bar,
        (sfVector2f){quest->size.x * quest->nb_achievement / 3 - 20,
            quest->size.y - 10});
    num = my_itoa(quest->nb_achievement);
    str = my_strcat(num, "-3");
    sfText_setString(quest->achievement, str);
    quest->nb_achievement_second = quest->nb_achievement;
    free(num);
    free(str);
}

void display_quest(game_t *game)
{
    if (!menu_tab_quest(game))
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

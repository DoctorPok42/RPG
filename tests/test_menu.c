/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** tests for the named menu state machine (behaviour must match the old
** raw decimal arithmetic)
*/

#include <criterion/criterion.h>
#include "game.h"
#include "menu.h"

Test(menu_transitions, push_pop_set_tab)
{
    game_t g = {0};

    g.menu = MENU_GAME;
    menu_push(&g, SCREEN_PAUSE);
    cr_assert_eq(g.menu, 56);
    menu_pop(&g);
    cr_assert_eq(g.menu, 5);
    g.menu = MENU_PAUSE_CHARACTER;
    menu_set_tab(&g, 2);
    cr_assert_eq(g.menu, MENU_PAUSE_QUEST);
    g.menu = 0;
    menu_push(&g, SCREEN_SAVE);
    cr_assert_eq(g.menu, 3);
}

Test(menu_predicates, start_overworld_hud)
{
    game_t g = {0};

    cr_assert(menu_is_start(&g));
    g.menu = MENU_GAME;
    cr_assert(menu_in_overworld(&g));
    cr_assert(menu_show_hud(&g));
    cr_assert(!menu_is_start(&g));
    g.menu = 56;
    cr_assert(!menu_in_overworld(&g));
    cr_assert(!menu_show_hud(&g));
    cr_assert(menu_pause_open(&g));
}

Test(menu_predicates, pause_tabs)
{
    game_t g = {0};

    g.menu = MENU_PAUSE_INVENTORY;
    cr_assert(menu_tab_inventory(&g));
    cr_assert(menu_in_pause_tab(&g));
    cr_assert(menu_pause_active(&g));
    g.menu = MENU_PAUSE_CHARACTER;
    cr_assert(menu_tab_character(&g));
    g.menu = MENU_PAUSE_QUEST;
    cr_assert(menu_tab_quest(&g));
    cr_assert(!menu_tab_inventory(&g));
}

Test(menu_predicates, settings_tabs)
{
    game_t g = {0};

    g.menu = 21;
    cr_assert(menu_tab_music(&g));
    g.menu = 22;
    cr_assert(menu_tab_keyboard(&g));
    g.menu = 24;
    cr_assert(menu_tab_window(&g));
    g.menu = 25;
    cr_assert(menu_tab_fps(&g));
    g.menu = MENU_SETTINGS;
    cr_assert(menu_in_settings(&g));
}

Test(menu_predicates, win_and_lose)
{
    game_t g = {0};

    g.is_finished = 1;
    g.menu = MENU_WIN;
    cr_assert(menu_won(&g));
    cr_assert(!menu_lost(&g));
    g.menu = MENU_LOSE;
    cr_assert(menu_lost(&g));
    cr_assert(!menu_won(&g));
    g.is_finished = 0;
    cr_assert(!menu_lost(&g));
}

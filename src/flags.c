/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** flags
*/

#include "game.h"

const game_functions_t MENU_FLAGS[] = {
    {.function = &change_to_inventory},
    {.function = &change_to_character},
    {.function = &change_to_quest},
    {.function = &change_to_option},
    {.function = &exit_start_all},
    {.function = NULL},
};

const start_flags_t START_FLAGS[] = {
    {.functions = (void *)&close_start_all},
    {.functions = (void *)&change_to_save},
    {.functions = (void *)&change_to_settings},
    {.functions = (void *)&exit_start_all},
    {.functions = NULL},
};

const params_functions_t PARAMS_FLAGS[] = {
    {.fonctions = &set_fullscreen},
    {.fonctions = &set_windowed},
    {.fonctions = &set_1920x1080},
    {.fonctions = &set_1280x720},
    {.fonctions = &set_800x600},
    {.fonctions = NULL},
};

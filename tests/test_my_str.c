/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** tests for the libc-like string/number helpers
*/

#include <criterion/criterion.h>
#include <limits.h>
#include <stdlib.h>
#include "my_str.h"

Test(my_getnbr, parses_and_stops_at_non_digit)
{
    cr_assert_eq(my_getnbr("123"), 123);
    cr_assert_eq(my_getnbr("-42"), -42);
    cr_assert_eq(my_getnbr("  +7"), 7);
    cr_assert_eq(my_getnbr("12abc"), 12);
    cr_assert_eq(my_getnbr("0"), 0);
}

static void check_itoa(int nb, const char *expected)
{
    char *str = my_itoa(nb);

    cr_assert_str_eq(str, expected);
    free(str);
}

Test(my_itoa, handles_full_int_range)
{
    check_itoa(0, "0");
    check_itoa(42, "42");
    check_itoa(-5, "-5");
    check_itoa(INT_MIN, "-2147483648");
    check_itoa(INT_MAX, "2147483647");
}

Test(my_strcmp, signed_difference)
{
    cr_assert_eq(my_strcmp("abc", "abc"), 0);
    cr_assert(my_strcmp("abc", "abd") < 0);
    cr_assert(my_strcmp("ab", "abc") < 0);
    cr_assert(my_strcmp("abd", "abc") > 0);
}

Test(my_strncmp, compares_n_chars)
{
    cr_assert_eq(my_strncmp("DISPLAY=x", "DISPLAY=", 8), 0);
    cr_assert_eq(my_strncmp("abc", "abd", 2), 0);
    cr_assert(my_strncmp("abc", "abd", 3) != 0);
}

Test(my_strlen, counts_characters)
{
    cr_assert_eq(my_strlen("hello"), 5);
    cr_assert_eq(my_strlen(""), 0);
}

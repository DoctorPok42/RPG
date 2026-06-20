/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** tests for the remaining string/number helpers
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include "my_str.h"

Test(my_strcat, joins_two_strings)
{
    char *r = my_strcat("foo", "bar");

    cr_assert_str_eq(r, "foobar");
    free(r);
    r = my_strcat("", "x");
    cr_assert_str_eq(r, "x");
    free(r);
}

Test(my_strndup, copies_first_n)
{
    char *r = my_strndup("hello", 3);

    cr_assert_str_eq(r, "hel");
    free(r);
}

Test(my_str_to_word_array, splits_on_separator)
{
    char **t = my_str_to_word_array("a b c", ' ');

    cr_assert_str_eq(t[0], "a");
    cr_assert_str_eq(t[1], "b");
    cr_assert_str_eq(t[2], "c");
    cr_assert_null(t[3]);
    free_tab(t);
}

static void check_put_nbr(int nb, const char *expected)
{
    char buf[64] = {0};
    int fd = open("/tmp/cr_put_nbr", O_CREAT | O_TRUNC | O_RDWR, 0644);

    my_put_nbr(nb, fd);
    lseek(fd, 0, SEEK_SET);
    cr_assert(read(fd, buf, sizeof(buf) - 1) >= 0);
    close(fd);
    cr_assert_str_eq(buf, expected);
}

Test(my_put_nbr, writes_full_int_range)
{
    check_put_nbr(0, "0");
    check_put_nbr(-5, "-5");
    check_put_nbr(INT_MIN, "-2147483648");
    check_put_nbr(INT_MAX, "2147483647");
}

static void check_float(double n, const char *expected)
{
    char buf[64] = {0};
    int fd = open("/tmp/cr_float", O_CREAT | O_TRUNC | O_RDWR, 0644);

    my_float(2, n, fd);
    lseek(fd, 0, SEEK_SET);
    cr_assert(read(fd, buf, sizeof(buf) - 1) >= 0);
    close(fd);
    cr_assert_str_eq(buf, expected);
}

Test(my_float, writes_two_decimals)
{
    check_float(3.14, "3.14");
    check_float(-1.5, "-1.50");
}

/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** 07
*/

#include "my_str.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = 1;
    long number = 0;

    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        number = number * 10 + (str[i] - '0');
        i++;
    }
    return (int)(sign * number);
}

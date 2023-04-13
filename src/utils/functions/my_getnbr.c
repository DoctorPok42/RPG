/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** 07
*/

int my_getnbr(char const *str)
{
    long int number = 0;
    int is_neg = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            is_neg = is_neg * -1;
        if (str[i] >= '0' && str[i] <= '9') {
            number = number * 10 + (str[i] - 48);
        }
    }

    if (number == 0)
        return 0;

    return (is_neg * number);
}
